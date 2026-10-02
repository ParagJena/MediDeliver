#include "../include/Cart.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void Cart::addMedicine(const Medicine& medicine, int quantity) {

    if (quantity <= 0) {
        throw invalid_argument("Quantity must be greater than zero.");
    }

    for (CartItem& item : items) {

        if (item.medicine.getId() == medicine.getId()) {

            if (item.quantity + quantity > medicine.getStock()) {
                throw runtime_error("Insufficient stock for " + medicine.getName());
            }

            item.quantity += quantity;
            return;
        }
    }

    if (quantity > medicine.getStock()) {
        throw runtime_error("Insufficient stock for " + medicine.getName());
    }

    CartItem item;
    item.medicine = medicine;
    item.quantity = quantity;

    items.push_back(item);
}

void Cart::removeMedicine(int medicineId) {

    for (auto it = items.begin(); it != items.end(); ++it) {

        if (it->medicine.getId() == medicineId) {
            items.erase(it);
            return;
        }
    }

    throw runtime_error("Medicine not found in cart.");
}

void Cart::displayCart() const {

    if (items.empty()) {
        cout << "Cart is empty." << endl;
        return;
    }

    double total = 0.0;

    cout << "\n========== MEDICINE CART ==========" << endl;

    for (const CartItem& item : items) {

        double itemTotal =
            item.medicine.getPrice() * item.quantity;

        cout << "-----------------------------" << endl;
        cout << "Medicine : " << item.medicine.getName() << endl;
        cout << "Quantity : " << item.quantity << endl;
        cout << "Price    : Rs. "
             << item.medicine.getPrice() << endl;
        cout << "Subtotal : Rs. "
             << itemTotal << endl;

        total += itemTotal;
    }

    cout << "-----------------------------" << endl;
    cout << "Cart Total : Rs. " << total << endl;
}

double Cart::calculateTotal() const {

    double total = 0.0;

    for (const CartItem& item : items) {
        total += item.medicine.getPrice() * item.quantity;
    }

    return total;
}

bool Cart::isEmpty() const {
    return items.empty();
}

void Cart::clearCart() {
    items.clear();
}

const vector<CartItem>& Cart::getItems() const {
    return items;
}
