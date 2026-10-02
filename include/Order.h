#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "Customer.h"
#include "Cart.h"

enum class OrderStatus {
    Placed,
    Confirmed,
    OutForDelivery,
    Delivered,
    Cancelled
};

class Order {
private:
    int orderId;
    Customer customer;
    std::vector<CartItem> items;
    double totalAmount;
    OrderStatus status;

public:
    Order();

    Order(int orderId,
          const Customer& customer,
          const std::vector<CartItem>& items,
          double totalAmount);

    int getOrderId() const;
    double getTotalAmount() const;
    OrderStatus getStatus() const;

    void updateStatus(OrderStatus newStatus);
    void display() const;
};

#endif
