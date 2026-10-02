#include "../include/Medicine.h"
#include <iostream>

using namespace std;

Medicine::Medicine()
    : id(0), name(""), category(""), price(0.0), stock(0) {
}

Medicine::Medicine(int id, string name, string category,
                   double price, int stock)
    : id(id),
      name(name),
      category(category),
      price(price),
      stock(stock) {
}

int Medicine::getId() const {
    return id;
}

string Medicine::getName() const {
    return name;
}

string Medicine::getCategory() const {
    return category;
}

double Medicine::getPrice() const {
    return price;
}

int Medicine::getStock() const {
    return stock;
}

void Medicine::setStock(int stock) {
    this->stock = stock;
}

void Medicine::display() const {
    cout << "ID       : " << id << endl;
    cout << "Medicine : " << name << endl;
    cout << "Category : " << category << endl;
    cout << "Price    : Rs. " << price << endl;
    cout << "Stock    : " << stock << endl;
}
