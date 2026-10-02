#ifndef CART_H
#define CART_H

#include <vector>
#include "Medicine.h"

struct CartItem {
    Medicine medicine;
    int quantity;
};

class Cart {
private:
    std::vector<CartItem> items;

public:
    void addMedicine(const Medicine& medicine, int quantity);
    void removeMedicine(int medicineId);
    void displayCart() const;
    double calculateTotal() const;
    bool isEmpty() const;
    void clearCart();
    const std::vector<CartItem>& getItems() const;
};

#endif
