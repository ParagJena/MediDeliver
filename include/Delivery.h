#ifndef DELIVERY_H
#define DELIVERY_H

#include <string>

enum class DeliveryStatus {
    Pending,
    Assigned,
    OutForDelivery,
    Delivered
};

class Delivery {
private:
    int deliveryId;
    int orderId;
    std::string deliveryAddress;
    std::string deliveryAgent;
    DeliveryStatus status;

public:
    Delivery();

    Delivery(int deliveryId,
             int orderId,
             std::string deliveryAddress,
             std::string deliveryAgent);

    int getDeliveryId() const;
    int getOrderId() const;
    std::string getDeliveryAddress() const;
    std::string getDeliveryAgent() const;
    DeliveryStatus getStatus() const;

    void assignDeliveryAgent(std::string agent);
    void updateStatus(DeliveryStatus newStatus);
    void display() const;
};

#endif
