#ifndef MEDICINE_H
#define MEDICINE_H

#include <string>

class Medicine {
private:
    int id;
    std::string name;
    std::string category;
    double price;
    int stock;

public:
    Medicine();

    Medicine(int id,
             std::string name,
             std::string category,
             double price,
             int stock);

    int getId() const;
    std::string getName() const;
    std::string getCategory() const;
    double getPrice() const;
    int getStock() const;

    void setStock(int stock);

    void display() const;
};

#endif
