#ifndef PHARMACY_H
#define PHARMACY_H

#include <string>
#include <vector>
#include "Medicine.h"

class Pharmacy {
private:
    int pharmacyId;
    std::string name;
    std::string location;
    std::vector<Medicine> medicines;

public:
    Pharmacy();

    Pharmacy(int pharmacyId,
             std::string name,
             std::string location);

    void addMedicine(const Medicine& medicine);
    void displayMedicines() const;
    Medicine* searchMedicine(int medicineId);
    bool reduceStock(int medicineId, int quantity);
    void sortMedicinesByPrice();

    int getPharmacyId() const;
    std::string getName() const;
    std::string getLocation() const;
};

#endif
