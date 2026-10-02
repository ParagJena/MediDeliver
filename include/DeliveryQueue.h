#ifndef DELIVERY_QUEUE_H
#define DELIVERY_QUEUE_H

#include <queue>

class DeliveryQueue {
private:
    std::queue<int> orderIds;

public:
    void addOrder(int orderId);
    int processNextOrder();
    bool isEmpty() const;
    int size() const;
    void displayQueue() const;
};

#endif
