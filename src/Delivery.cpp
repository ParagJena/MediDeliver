#include "../include/Delivery.h"
#include <iostream>

using namespace std;

Delivery::Delivery()
    : deliveryId(0),
      orderId(0),
      deliveryAddress(""),
      deliveryAgent(""),
      status(DeliveryStatus::Pending) {
}

Delivery::Delivery(int deliveryId,
                   int orderId,
                   string deliveryAddress,
                   string deliveryAgent)
    : deliveryId(deliveryId),
      orderId(orderId),
      deliveryAddress(deliveryAddress),
      deliveryAgent(deliveryAgent),
      status(DeliveryStatus::Pending) {
}

int Delivery::getDeliveryId() const {
    return deliveryId;
}

int Delivery::getOrderId() const {
    return orderId;
}

string Delivery::getDeliveryAddress() const {
    return deliveryAddress;
}

string Delivery::getDeliveryAgent() const {
    return deliveryAgent;
}

DeliveryStatus Delivery::getStatus() const {
    return status;
}

void Delivery::assignDeliveryAgent(string agent) {
    deliveryAgent = agent;
    status = DeliveryStatus::Assigned;
}

void Delivery::updateStatus(DeliveryStatus newStatus) {
    status = newStatus;
}

void Delivery::display() const {

    cout << "\n========== DELIVERY ==========" << endl;
    cout << "Delivery ID : " << deliveryId << endl;
    cout << "Order ID    : " << orderId << endl;
    cout << "Address     : " << deliveryAddress << endl;
    cout << "Agent       : " << deliveryAgent << endl;
    cout << "Status      : ";

    switch (status) {
        case DeliveryStatus::Pending:
            cout << "Pending";
            break;

        case DeliveryStatus::Assigned:
            cout << "Assigned";
            break;

        case DeliveryStatus::OutForDelivery:
            cout << "Out For Delivery";
            break;

        case DeliveryStatus::Delivered:
            cout << "Delivered";
            break;
    }

    cout << endl;
}
