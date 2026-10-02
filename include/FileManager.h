#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "Medicine.h"
#include "Customer.h"
#include "Order.h"
#include "Payment.h"

class FileManager {
public:
    static void initializeFiles();

    static void saveMedicine(const Medicine& medicine);
    static void saveCustomer(const Customer& customer);
    static void saveOrder(const Order& order);
    static void savePayment(const Payment& payment);

    static int getNextOrderId();
    static int getNextPaymentId();
    static int getNextDeliveryId();
};

#endif
