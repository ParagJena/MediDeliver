#include "../include/FileManager.h"
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

void FileManager::initializeFiles() {

    ofstream medicines("data/medicines.txt", ios::app);
    ofstream customers("data/customers.txt", ios::app);
    ofstream orders("data/orders.txt", ios::app);
    ofstream payments("data/payments.txt", ios::app);
    ofstream deliveries("data/deliveries.txt", ios::app);

    medicines.close();
    customers.close();
    orders.close();
    payments.close();
    deliveries.close();
}

void FileManager::saveMedicine(
    const Medicine& medicine
) {

    ifstream input("data/medicines.txt");

    map<int, Medicine> medicineMap;

    string line;

    while (getline(input, line)) {

        if (line.empty()) {
            continue;
        }

        stringstream ss(line);

        string id;
        string name;
        string category;
        string price;
        string stock;

        if (getline(ss, id, '|') &&
            getline(ss, name, '|') &&
            getline(ss, category, '|') &&
            getline(ss, price, '|') &&
            getline(ss, stock, '|')) {

            try {

                Medicine existing(
                    stoi(id),
                    name,
                    category,
                    stod(price),
                    stoi(stock)
                );

                medicineMap[
                    existing.getId()
                ] = existing;
            }
            catch (...) {
            }
        }
    }

    input.close();

    medicineMap[
        medicine.getId()
    ] = medicine;

    ofstream output(
        "data/medicines.txt",
        ios::trunc
    );

    for (const auto& entry : medicineMap) {

        const Medicine& current =
            entry.second;

        output << current.getId()
               << "|"
               << current.getName()
               << "|"
               << current.getCategory()
               << "|"
               << current.getPrice()
               << "|"
               << current.getStock()
               << endl;
    }

    output.close();
}

void FileManager::saveCustomer(
    const Customer& customer
) {

    ifstream input("data/customers.txt");

    map<int, Customer> customerMap;

    string line;

    while (getline(input, line)) {

        if (line.empty()) {
            continue;
        }

        stringstream ss(line);

        string id;
        string name;
        string phone;
        string address;

        if (getline(ss, id, '|') &&
            getline(ss, name, '|') &&
            getline(ss, phone, '|') &&
            getline(ss, address, '|')) {

            try {

                Customer existing(
                    stoi(id),
                    name,
                    phone,
                    address
                );

                customerMap[
                    existing.getCustomerId()
                ] = existing;
            }
            catch (...) {
            }
        }
    }

    input.close();

    customerMap[
        customer.getCustomerId()
    ] = customer;

    ofstream output(
        "data/customers.txt",
        ios::trunc
    );

    for (const auto& entry : customerMap) {

        const Customer& current =
            entry.second;

        output << current.getCustomerId()
               << "|"
               << current.getName()
               << "|"
               << current.getPhone()
               << "|"
               << current.getAddress()
               << endl;
    }

    output.close();
}

vector<Customer> FileManager::loadCustomers() {

    ifstream input(
        "data/customers.txt"
    );

    vector<Customer> customers;

    string line;

    while (getline(input, line)) {

        if (line.empty()) {
            continue;
        }

        stringstream ss(line);

        string id;
        string name;
        string phone;
        string address;

        if (getline(ss, id, '|') &&
            getline(ss, name, '|') &&
            getline(ss, phone, '|') &&
            getline(ss, address, '|')) {

            try {

                Customer customer(
                    stoi(id),
                    name,
                    phone,
                    address
                );

                customers.push_back(
                    customer
                );
            }
            catch (...) {
            }
        }
    }

    input.close();

    return customers;
}

vector<Delivery> FileManager::loadDeliveries() {

    ifstream input(
        "data/deliveries.txt"
    );

    vector<Delivery> deliveries;

    string line;

    while (getline(input, line)) {

        if (line.empty()) {
            continue;
        }

        stringstream ss(line);

        string deliveryId;
        string orderId;
        string address;
        string agent;
        string status;

        if (getline(ss, deliveryId, '|') &&
            getline(ss, orderId, '|') &&
            getline(ss, address, '|') &&
            getline(ss, agent, '|') &&
            getline(ss, status, '|')) {

            try {

                Delivery delivery(
                    stoi(deliveryId),
                    stoi(orderId),
                    address,
                    agent
                );

                if (status == "Assigned") {

                    delivery.updateStatus(
                        DeliveryStatus::Assigned
                    );
                }
                else if (
                    status == "OutForDelivery"
                ) {

                    delivery.updateStatus(
                        DeliveryStatus::OutForDelivery
                    );
                }
                else if (
                    status == "Delivered"
                ) {

                    delivery.updateStatus(
                        DeliveryStatus::Delivered
                    );
                }

                deliveries.push_back(
                    delivery
                );
            }
            catch (...) {
            }
        }
    }

    input.close();

    return deliveries;
}

vector<Order> FileManager::loadOrders() {

    ifstream input(
        "data/orders.txt"
    );

    vector<Order> orders;

    string line;

    while (getline(input, line)) {

        if (line.empty()) {
            continue;
        }

        stringstream ss(line);

        string orderId;
        string totalAmount;
        string status;

        if (getline(ss, orderId, '|') &&
            getline(ss, totalAmount, '|') &&
            getline(ss, status, '|')) {

            try {

                Customer emptyCustomer;

                vector<CartItem> emptyItems;

                Order order(
                    stoi(orderId),
                    emptyCustomer,
                    emptyItems,
                    stod(totalAmount)
                );

                if (status == "Confirmed") {

                    order.updateStatus(
                        OrderStatus::Confirmed
                    );
                }
                else if (
                    status == "OutForDelivery"
                ) {

                    order.updateStatus(
                        OrderStatus::OutForDelivery
                    );
                }
                else if (
                    status == "Delivered"
                ) {

                    order.updateStatus(
                        OrderStatus::Delivered
                    );
                }
                else if (
                    status == "Cancelled"
                ) {

                    order.updateStatus(
                        OrderStatus::Cancelled
                    );
                }

                orders.push_back(order);
            }
            catch (...) {
            }
        }
    }

    input.close();

    return orders;
}

void FileManager::saveDelivery(
    const Delivery& delivery
) {

    ofstream file(
        "data/deliveries.txt",
        ios::app
    );

    string status;

    switch (delivery.getStatus()) {

        case DeliveryStatus::Pending:
            status = "Pending";
            break;

        case DeliveryStatus::Assigned:
            status = "Assigned";
            break;

        case DeliveryStatus::OutForDelivery:
            status = "OutForDelivery";
            break;

        case DeliveryStatus::Delivered:
            status = "Delivered";
            break;
    }

    file << delivery.getDeliveryId()
         << "|"
         << delivery.getOrderId()
         << "|"
         << delivery.getDeliveryAddress()
         << "|"
         << delivery.getDeliveryAgent()
         << "|"
         << status
         << endl;

    file.close();
}

void FileManager::saveOrder(
    const Order& order
) {

    ofstream file(
        "data/orders.txt",
        ios::app
    );

    string status;

    switch (order.getStatus()) {

        case OrderStatus::Placed:
            status = "Placed";
            break;

        case OrderStatus::Confirmed:
            status = "Confirmed";
            break;

        case OrderStatus::OutForDelivery:
            status = "OutForDelivery";
            break;

        case OrderStatus::Delivered:
            status = "Delivered";
            break;

        case OrderStatus::Cancelled:
            status = "Cancelled";
            break;
    }

    file << order.getOrderId()
         << "|"
         << order.getTotalAmount()
         << "|"
         << status
         << endl;

    file.close();
}

void FileManager::savePayment(
    const Payment& payment
) {

    ofstream file(
        "data/payments.txt",
        ios::app
    );

    string status;

    switch (payment.getStatus()) {

        case PaymentStatus::Pending:
            status = "Pending";
            break;

        case PaymentStatus::Successful:
            status = "Successful";
            break;

        case PaymentStatus::Failed:
            status = "Failed";
            break;
    }

    file << payment.getPaymentId()
         << "|"
         << payment.getOrderId()
         << "|"
         << payment.getAmount()
         << "|"
         << payment.getMethod()
         << "|"
         << status
         << endl;

    file.close();
}

int FileManager::getNextOrderId() {

    ifstream file(
        "data/orders.txt"
    );

    string line;

    int highestId = 1000;

    while (getline(file, line)) {

        if (line.empty()) {
            continue;
        }

        stringstream ss(line);

        string id;

        if (getline(ss, id, '|')) {

            try {

                int currentId =
                    stoi(id);

                if (currentId > highestId) {
                    highestId = currentId;
                }
            }
            catch (...) {
            }
        }
    }

    file.close();

    return highestId + 1;
}

int FileManager::getNextPaymentId() {

    ifstream file(
        "data/payments.txt"
    );

    string line;

    int highestId = 5000;

    while (getline(file, line)) {

        if (line.empty()) {
            continue;
        }

        stringstream ss(line);

        string id;

        if (getline(ss, id, '|')) {

            try {

                int currentId =
                    stoi(id);

                if (currentId > highestId) {
                    highestId = currentId;
                }
            }
            catch (...) {
            }
        }
    }

    file.close();

    return highestId + 1;
}

int FileManager::getNextDeliveryId() {

    ifstream file(
        "data/deliveries.txt"
    );

    string line;

    int highestId = 7000;

    while (getline(file, line)) {

        if (line.empty()) {
            continue;
        }

        stringstream ss(line);

        string id;

        if (getline(ss, id, '|')) {

            try {

                int currentId =
                    stoi(id);

                if (currentId > highestId) {
                    highestId = currentId;
                }
            }
            catch (...) {
            }
        }
    }

    file.close();

    return highestId + 1;
}
