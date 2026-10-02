#include "../include/Medicine.h"
#include "../include/Customer.h"
#include "../include/Pharmacy.h"
#include "../include/Cart.h"
#include "../include/Order.h"
#include "../include/Payment.h"
#include "../include/Delivery.h"
#include "../include/DeliveryQueue.h"
#include "../include/FileManager.h"

#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <sstream>

using namespace std;

int main() {

    try {

        FileManager::initializeFiles();

        vector<Medicine> medicines;

        ifstream medicineFile("data/medicines.txt");

        string medicineLine;

        while (getline(medicineFile, medicineLine)) {

            if (medicineLine.empty()) {
                continue;
            }

            stringstream ss(medicineLine);

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
                    medicines.emplace_back(
                        stoi(id),
                        name,
                        category,
                        stod(price),
                        stoi(stock)
                    );
                }
                catch (...) {
                }
            }
        }

        medicineFile.close();

        if (medicines.empty()) {

            medicines.emplace_back(
                101,
                "Paracetamol",
                "Pain Relief",
                25.50,
                100
            );

            medicines.emplace_back(
                102,
                "Cetirizine",
                "Allergy",
                35.00,
                50
            );

            medicines.emplace_back(
                103,
                "Vitamin C",
                "Supplement",
                120.00,
                30
            );

            for (const Medicine& medicine : medicines) {
                FileManager::saveMedicine(medicine);
            }
        }

        Customer customer(
            1,
            "Rahul Sharma",
            "9876543210",
            "Bhubaneswar, Odisha"
        );

        Pharmacy pharmacy(
            101,
            "MediCare Pharmacy",
            "Bhubaneswar"
        );

        for (const Medicine& medicine : medicines) {
            pharmacy.addMedicine(medicine);
        }

        FileManager::saveCustomer(customer);

        Cart cart;

        int choice;

        do {

            cout << "\n=================================" << endl;
            cout << "       MEDIDELIVER SYSTEM" << endl;
            cout << "=================================" << endl;
            cout << "1. View Medicines" << endl;
            cout << "2. Search Medicine" << endl;
            cout << "3. Add Medicine to Cart" << endl;
            cout << "4. View Cart" << endl;
            cout << "5. Remove Medicine from Cart" << endl;
            cout << "6. Place Order" << endl;
            cout << "7. Exit" << endl;
            cout << "=================================" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input." << endl;
                continue;
            }

            switch (choice) {

                case 1: {

                    cout << "\n--- AVAILABLE MEDICINES ---"
                         << endl;

                    pharmacy.sortMedicinesByPrice();
                    pharmacy.displayMedicines();

                    break;
                }

                case 2: {

                    int medicineId;

                    cout << "\nEnter Medicine ID: ";
                    cin >> medicineId;

                    Medicine* medicine =
                        pharmacy.searchMedicine(medicineId);

                    if (medicine != nullptr) {
                        cout << "\nMedicine found:"
                             << endl;
                        medicine->display();
                    }
                    else {
                        cout << "Medicine not found."
                             << endl;
                    }

                    break;
                }

                case 3: {

                    int medicineId;
                    int quantity;

                    cout << "\nEnter Medicine ID: ";
                    cin >> medicineId;

                    Medicine* medicine =
                        pharmacy.searchMedicine(medicineId);

                    if (medicine == nullptr) {
                        cout << "Medicine not found."
                             << endl;
                        break;
                    }

                    cout << "Medicine : "
                         << medicine->getName()
                         << endl;

                    cout << "Available Stock : "
                         << medicine->getStock()
                         << endl;

                    cout << "Enter Quantity: ";
                    cin >> quantity;

                    try {
                        cart.addMedicine(
                            *medicine,
                            quantity
                        );

                        cout << "Medicine added to cart."
                             << endl;
                    }
                    catch (const invalid_argument& e) {
                        cout << "Error: "
                             << e.what() << endl;
                    }
                    catch (const runtime_error& e) {
                        cout << "Error: "
                             << e.what() << endl;
                    }

                    break;
                }

                case 4: {

                    cout << "\n--- YOUR CART ---"
                         << endl;

                    if (cart.isEmpty()) {
                        cout << "Cart is empty."
                             << endl;
                    }
                    else {
                        cart.displayCart();
                    }

                    break;
                }

                case 5: {

                    if (cart.isEmpty()) {
                        cout << "\nCart is empty."
                             << endl;
                        break;
                    }

                    int medicineId;

                    cout << "\nEnter Medicine ID to remove: ";
                    cin >> medicineId;

                    try {
                        cart.removeMedicine(medicineId);

                        cout << "Medicine removed from cart."
                             << endl;
                    }
                    catch (const runtime_error& e) {
                        cout << "Error: "
                             << e.what() << endl;
                    }

                    break;
                }

                case 6: {

                    if (cart.isEmpty()) {
                        cout << "\nCart is empty."
                             << endl;
                        break;
                    }

                    double total =
                        cart.calculateTotal();

                    cout << "\n--- ORDER SUMMARY ---"
                         << endl;

                    cart.displayCart();

                    cout << "\nCustomer:"
                         << endl;

                    customer.display();

                    cout << "\nConfirm order? "
                         << "(1 = Yes, 0 = No): ";

                    int confirm;
                    cin >> confirm;

                    if (confirm != 1) {
                        cout << "Order cancelled."
                             << endl;
                        break;
                    }

                    int orderId =
                        FileManager::getNextOrderId();

                    Order order(
                        orderId,
                        customer,
                        cart.getItems(),
                        total
                    );

                    cout << "\n--- ORDER CREATED ---"
                         << endl;

                    order.display();

                    int paymentId =
                        FileManager::getNextPaymentId();

                    Payment payment(
                        paymentId,
                        order.getOrderId(),
                        order.getTotalAmount(),
                        "UPI"
                    );

                    cout << "\n--- PAYMENT ---"
                         << endl;

                    payment.processPayment();
                    payment.display();

                    if (payment.getStatus() !=
                        PaymentStatus::Successful) {

                        throw runtime_error(
                            "Payment failed."
                        );
                    }

                    FileManager::savePayment(
                        payment
                    );

                    for (const CartItem& item :
                         cart.getItems()) {

                        if (!pharmacy.reduceStock(
                                item.medicine.getId(),
                                item.quantity)) {

                            throw runtime_error(
                                "Unable to update medicine stock."
                            );
                        }
                    }

                    order.updateStatus(
                        OrderStatus::Confirmed
                    );

                    cout << "\n--- ORDER CONFIRMED ---"
                         << endl;

                    order.display();

                    for (const CartItem& item :
                         cart.getItems()) {

                        Medicine* medicine =
                            pharmacy.searchMedicine(
                                item.medicine.getId()
                            );

                        if (medicine != nullptr) {
                            FileManager::saveMedicine(
                                *medicine
                            );
                        }
                    }

                    DeliveryQueue deliveryQueue;

                    deliveryQueue.addOrder(
                        order.getOrderId()
                    );

                    cout << "\n--- DELIVERY QUEUE ---"
                         << endl;

                    deliveryQueue.displayQueue();

                    int deliveryId =
                        FileManager::getNextDeliveryId();

                    Delivery delivery(
                        deliveryId,
                        order.getOrderId(),
                        customer.getAddress(),
                        ""
                    );

                    delivery.assignDeliveryAgent(
                        "Amit Kumar"
                    );

                    cout << "\n--- DELIVERY ASSIGNED ---"
                         << endl;

                    delivery.display();

                    delivery.updateStatus(
                        DeliveryStatus::OutForDelivery
                    );

                    cout << "\n--- DELIVERY UPDATE ---"
                         << endl;

                    delivery.display();

                    int processedOrder =
                        deliveryQueue.processNextOrder();

                    cout << "\nProcessing Order ID : "
                         << processedOrder
                         << endl;

                    delivery.updateStatus(
                        DeliveryStatus::Delivered
                    );

                    order.updateStatus(
                        OrderStatus::Delivered
                    );

                    FileManager::saveOrder(
                        order
                    );

                    cout << "\n--- FINAL ORDER STATUS ---"
                         << endl;

                    order.display();

                    cout << "\n--- FINAL DELIVERY STATUS ---"
                         << endl;

                    delivery.display();

                    cout << "\nOrder completed successfully."
                         << endl;

                    cart.clearCart();

                    break;
                }

                case 7: {

                    cout << "\nThank you for using MediDeliver."
                         << endl;

                    break;
                }

                default:

                    cout << "\nInvalid choice."
                         << endl;
            }

        } while (choice != 7);

    }
    catch (const invalid_argument& e) {

        cout << "\nError: "
             << e.what() << endl;
    }
    catch (const runtime_error& e) {

        cout << "\nError: "
             << e.what() << endl;
    }
    catch (const exception& e) {

        cout << "\nUnexpected error: "
             << e.what() << endl;
    }

    return 0;
}
