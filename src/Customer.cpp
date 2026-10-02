#include "../include/Customer.h"
#include <iostream>

using namespace std;

Customer::Customer()
    : customerId(0),
      name(""),
      phone(""),
      address("") {
}

Customer::Customer(int customerId,
                   string name,
                   string phone,
                   string address)
    : customerId(customerId),
      name(name),
      phone(phone),
      address(address) {
}

int Customer::getCustomerId() const {
    return customerId;
}

string Customer::getName() const {
    return name;
}

string Customer::getPhone() const {
    return phone;
}

string Customer::getAddress() const {
    return address;
}

void Customer::display() const {
    cout << "Customer ID : " << customerId << endl;
    cout << "Name        : " << name << endl;
    cout << "Phone       : " << phone << endl;
    cout << "Address     : " << address << endl;
}
