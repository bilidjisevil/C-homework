#pragma once
#include "Base.h"

/*
Класс Motorcycle (Мотоцикл)
Наследуется от Base, описывает характеристики мототехники.
 */
class Motorcycle : public Base {
private:
    wstring brand;        // Марка мотоцикла
    wstring model;        // Модель мотоцикла
    double engineVolume;  // Объем двигателя (в куб. см)
    int power;            // Мощность в лошадиных силах
    wstring terrain;      // Назначение / тип местности (дорожный, кроссовый и т.д.)

public:
    Motorcycle();
    Motorcycle(wstring b, wstring m, double v, int p, wstring t);
    ~Motorcycle() override;

    wstring getType() const override;
    void input() override;
    void display() const override;
    void save(wofstream& out) const override;
    void load(wifstream& in) override;
};