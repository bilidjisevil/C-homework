#pragma once
#include "Base.h"

/*
 Класс Bus (Автобус)
 Наследуется от Base, хранит вместимость пассажиров и маршрут.
 */
class Bus : public Base {
private:
    wstring brand;       // Марка автобуса
    wstring model;       // Модель автобуса
    int seatedSeats;     // Количество сидячих мест
    int totalSeats;      // Общее количество пассажирских мест
    wstring destination; // Конечный пункт назначения / маршрут

public:
    Bus();
    Bus(wstring b, wstring m, int s, int t, wstring d);
    ~Bus() override;

    wstring getType() const override;
    void input() override;
    void display() const override;
    void save(wofstream& out) const override;
    void load(wifstream& in) override;
};