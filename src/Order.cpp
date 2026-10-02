#include "../include/Order.h"
#include <iostream>

using namespace std;

Order::Order()
    : orderId(0),
      customer(),
      items(),
      totalAmount(0.0),
      status(OrderStatus::Placed) {
}

Order::Order(int orderId,
             const Customer& customer,
             const vector<CartItem>& items,
             double totalAmount)
    : orderId(orderId),
      customer(customer),
      items(items),
      totalAmount(totalAmount),
      status(OrderStatus::Placed) {
}

int Order::getOrderId() const {
    return orderId;
}

double Order::getTotalAmount() const {
    return totalAmount;
}

OrderStatus Order::getStatus() const {
    return status;
}

void Order::updateStatus(OrderStatus newStatus) {
    status = newStatus;
}

void Order::display() const {

    cout << "\n========== ORDER ==========" << endl;
    cout << "Order ID    : " << orderId << endl;

    cout << "\nCustomer:" << endl;
    customer.display();

    cout << "\nOrder Items:" << endl;

    for (const CartItem& item : items) {
        cout << "-----------------------------" << endl;
        cout << "Medicine : " << item.medicine.getName() << endl;
        cout << "Quantity : " << item.quantity << endl;
        cout << "Price    : Rs. "
             << item.medicine.getPrice() << endl;
        cout << "Subtotal : Rs. "
             << item.medicine.getPrice() * item.quantity << endl;
    }

    cout << "-----------------------------" << endl;
    cout << "Total     : Rs. " << totalAmount << endl;

    cout << "Status    : ";

    switch (status) {
        case OrderStatus::Placed:
            cout << "Placed";
            break;

        case OrderStatus::Confirmed:
            cout << "Confirmed";
            break;

        case OrderStatus::OutForDelivery:
            cout << "Out For Delivery";
            break;

        case OrderStatus::Delivered:
            cout << "Delivered";
            break;

        case OrderStatus::Cancelled:
            cout << "Cancelled";
            break;
    }

    cout << endl;
}
