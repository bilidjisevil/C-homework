#pragma once
#include "Base.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Bus.h"
#include <vector>
#include <memory>

class Keeper {
private:
    vector<shared_ptr<Base>> items;

public:
    Keeper();
    ~Keeper();

    void add(int choice);
    void remove(size_t index);
    void displayAll() const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};