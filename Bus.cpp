#include "Bus.h"

Bus::Bus() : seatedSeats(0), totalSeats(0) {}

Bus::Bus(wstring b, wstring m, int s, int t, wstring d)
    : brand(b), model(m), seatedSeats(s), totalSeats(t), destination(d) {}

Bus::~Bus() {}

wstring Bus::getType() const {
    return L"Bus";
}

void Bus::input() {
    wcout << L"Введите марку автобуса: "; wcin >> brand;
    wcout << L"Введите модель автобуса: "; wcin >> model;
    wcout << L"Введите количество сидячих мест: "; wcin >> seatedSeats;
    wcout << L"Введите общее количество мест: "; wcin >> totalSeats;
    wcout << L"Введите конечный пункт: "; wcin >> destination;
}

void Bus::display() const {
    wcout << L"[Автобус] Марка: " << brand << L", Модель: " << model
          << L", Сидячих мест: " << seatedSeats << L", Всего мест: " << totalSeats
          << L", Конечный пункт: " << destination << endl;
}

void Bus::save(wofstream& out) const {
    out << L"Bus\n" << brand << L"\n" << model << L"\n"
        << seatedSeats << L"\n" << totalSeats << L"\n" << destination << L"\n";
}

void Bus::load(wifstream& in) {
    in >> brand >> model >> seatedSeats >> totalSeats >> destination;
}