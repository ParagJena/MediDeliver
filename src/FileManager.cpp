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

    medicines.close();
    customers.close();
    orders.close();
    payments.close();
}

void FileManager::saveMedicine(const Medicine& medicine) {

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

                medicineMap[existing.getId()] = existing;
            }
            catch (...) {
            }
        }
    }

    input.close();

    medicineMap[medicine.getId()] = medicine;

    ofstream output("data/medicines.txt", ios::trunc);

    for (const auto& entry : medicineMap) {

        const Medicine& current = entry.second;

        output << current.getId() << "|"
               << current.getName() << "|"
               << current.getCategory() << "|"
               << current.getPrice() << "|"
               << current.getStock() << endl;
    }

    output.close();
}

void FileManager::saveCustomer(const Customer& customer) {

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

                customerMap[existing.getCustomerId()] = existing;
            }
            catch (...) {
            }
        }
    }

    input.close();

    customerMap[customer.getCustomerId()] = customer;

    ofstream output("data/customers.txt", ios::trunc);

    for (const auto& entry : customerMap) {

        const Customer& current = entry.second;

        output << current.getCustomerId() << "|"
               << current.getName() << "|"
               << current.getPhone() << "|"
               << current.getAddress() << endl;
    }

    output.close();
}

void FileManager::saveOrder(const Order& order) {

    ofstream file("data/orders.txt", ios::app);

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

    file << order.getOrderId() << "|"
         << order.getTotalAmount() << "|"
         << status << endl;

    file.close();
}

void FileManager::savePayment(const Payment& payment) {

    ofstream file("data/payments.txt", ios::app);

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

    file << payment.getPaymentId() << "|"
         << payment.getOrderId() << "|"
         << payment.getAmount() << "|"
         << payment.getMethod() << "|"
         << status << endl;

    file.close();
}
