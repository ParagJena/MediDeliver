#include "../include/Payment.h"
#include <iostream>

using namespace std;

Payment::Payment()
    : paymentId(0),
      orderId(0),
      amount(0.0),
      method(""),
      status(PaymentStatus::Pending) {
}

Payment::Payment(int paymentId,
                 int orderId,
                 double amount,
                 string method)
    : paymentId(paymentId),
      orderId(orderId),
      amount(amount),
      method(method),
      status(PaymentStatus::Pending) {
}

int Payment::getPaymentId() const {
    return paymentId;
}

int Payment::getOrderId() const {
    return orderId;
}

double Payment::getAmount() const {
    return amount;
}

string Payment::getMethod() const {
    return method;
}

PaymentStatus Payment::getStatus() const {
    return status;
}

void Payment::processPayment() {
    if (amount > 0) {
        status = PaymentStatus::Successful;
    } else {
        status = PaymentStatus::Failed;
    }
}

void Payment::display() const {

    cout << "\n========== PAYMENT ==========" << endl;
    cout << "Payment ID : " << paymentId << endl;
    cout << "Order ID   : " << orderId << endl;
    cout << "Amount     : Rs. " << amount << endl;
    cout << "Method     : " << method << endl;
    cout << "Status     : ";

    switch (status) {
        case PaymentStatus::Pending:
            cout << "Pending";
            break;

        case PaymentStatus::Successful:
            cout << "Successful";
            break;

        case PaymentStatus::Failed:
            cout << "Failed";
            break;
    }

    cout << endl;
}
