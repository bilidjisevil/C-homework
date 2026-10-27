#pragma once
#include "Base.h"

/*
 Класс Car (Автомобиль)
 Наследуется от абстрактного класса Base.
 Использует тип wstring для корректной поддержки кириллицы при вводе/выводе.
 */
class Car : public Base {
private:
    wstring brand;        // Марка автомобиля (например, Lada, Toyota)
    wstring model;        // Модель автомобиля (например, Vesta, Camry)
    double engineVolume;  // Объем двигателя в литрах
    wstring color;        // Цвет кузова
    wstring transmission; // Тип коробки передач (механика / автомат)

public:
    // Конструктор по умолчанию
    Car();

    // Конструктор с параметрами для быстрой инициализации
    Car(wstring b, wstring m, double v, wstring c, wstring t);

    // Переопределенный деструктор
    ~Car() override;

    // Реализация виртуальных методов базового класса
    wstring getType() const override;
    void input() override;
    void display() const override;
    void save(wofstream& out) const override;
    void load(wifstream& in) override;
};