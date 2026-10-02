#include "../include/DeliveryQueue.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void DeliveryQueue::addOrder(int orderId) {
    if (orderId <= 0) {
        throw invalid_argument("Invalid order ID.");
    }

    orderIds.push(orderId);
}

int DeliveryQueue::processNextOrder() {

    if (orderIds.empty()) {
        throw runtime_error("Delivery queue is empty.");
    }

    int orderId = orderIds.front();
    orderIds.pop();

    return orderId;
}

bool DeliveryQueue::isEmpty() const {
    return orderIds.empty();
}

int DeliveryQueue::size() const {
    return static_cast<int>(orderIds.size());
}

void DeliveryQueue::displayQueue() const {

    if (orderIds.empty()) {
        cout << "Delivery queue is empty." << endl;
        return;
    }

    queue<int> temporary = orderIds;

    cout << "\n========== DELIVERY QUEUE ==========" << endl;

    while (!temporary.empty()) {
        cout << "Order ID : "
             << temporary.front() << endl;

        temporary.pop();
    }
}
