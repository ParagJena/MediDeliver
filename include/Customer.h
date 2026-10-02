#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    int customerId;
    std::string name;
    std::string phone;
    std::string address;

public:
    Customer();
    
    Customer(int customerId,
             std::string name,
             std::string phone,
             std::string address);

    int getCustomerId() const;
    std::string getName() const;
    std::string getPhone() const;
    std::string getAddress() const;

    void display() const;
};

#endif
