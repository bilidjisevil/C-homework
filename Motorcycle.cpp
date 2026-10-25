#include "Motorcycle.h"

Motorcycle::Motorcycle() : engineVolume(0.0), power(0) {}

Motorcycle::Motorcycle(wstring b, wstring m, double v, int p, wstring t)
    : brand(b), model(m), engineVolume(v), power(p), terrain(t) {}

Motorcycle::~Motorcycle() {}

wstring Motorcycle::getType() const {
    return L"Motorcycle";
}

void Motorcycle::input() {
    wcout << L"Введите марку мотоцикла: "; wcin >> brand;
    wcout << L"Введите модель мотоцикла: "; wcin >> model;
    wcout << L"Введите объем двигателя (см3): "; wcin >> engineVolume;
    wcout << L"Введите мощность (л.с.): "; wcin >> power;
    wcout << L"Введите тип местности (дорожный/кроссовый/эндуро): "; wcin >> terrain;
}

void Motorcycle::display() const {
    wcout << L"[Мотоцикл] Марка: " << brand << L", Модель: " << model
          << L", Объем: " << engineVolume << L" см3, Мощность: " << power
          << L" л.с., Назначение: " << terrain << endl;
}

void Motorcycle::save(wofstream& out) const {
    out << L"Motorcycle\n" << brand << L"\n" << model << L"\n"
        << engineVolume << L"\n" << power << L"\n" << terrain << L"\n";
}

void Motorcycle::load(wifstream& in) {
    in >> brand >> model >> engineVolume >> power >> terrain;
}