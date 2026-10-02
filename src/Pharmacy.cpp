#include "../include/Pharmacy.h"
#include <iostream>
#include <algorithm>

using namespace std;

Pharmacy::Pharmacy()
    : pharmacyId(0),
      name(""),
      location("") {
}

Pharmacy::Pharmacy(int pharmacyId,
                   string name,
                   string location)
    : pharmacyId(pharmacyId),
      name(name),
      location(location) {
}

void Pharmacy::addMedicine(const Medicine& medicine) {
    medicines.push_back(medicine);
}

void Pharmacy::displayMedicines() const {

    if (medicines.empty()) {
        cout << "No medicines available." << endl;
        return;
    }

    for (const Medicine& medicine : medicines) {
        cout << "-----------------------------" << endl;
        medicine.display();
    }
}

Medicine* Pharmacy::searchMedicine(int medicineId) {

    for (Medicine& medicine : medicines) {

        if (medicine.getId() == medicineId) {
            return &medicine;
        }
    }

    return nullptr;
}

bool Pharmacy::reduceStock(int medicineId, int quantity) {

    Medicine* medicine = searchMedicine(medicineId);

    if (medicine == nullptr) {
        return false;
    }

    if (quantity <= 0 || quantity > medicine->getStock()) {
        return false;
    }

    medicine->setStock(
        medicine->getStock() - quantity
    );

    return true;
}

void Pharmacy::sortMedicinesByPrice() {

    sort(
        medicines.begin(),
        medicines.end(),
        [](const Medicine& first, const Medicine& second) {
            return first.getPrice() < second.getPrice();
        }
    );
}

int Pharmacy::getPharmacyId() const {
    return pharmacyId;
}

string Pharmacy::getName() const {
    return name;
}

string Pharmacy::getLocation() const {
    return location;
}
