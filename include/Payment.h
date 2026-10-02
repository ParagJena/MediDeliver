#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>

enum class PaymentStatus {
    Pending,
    Successful,
    Failed
};

class Payment {
private:
    int paymentId;
    int orderId;
    double amount;
    std::string method;
    PaymentStatus status;

public:
    Payment();

    Payment(int paymentId,
            int orderId,
            double amount,
            std::string method);

    int getPaymentId() const;
    int getOrderId() const;
    double getAmount() const;
    std::string getMethod() const;
    PaymentStatus getStatus() const;

    void processPayment();
    void display() const;
};

#endif
