#include "Car.h"

// Конструктор по умолчанию: инициализируем числовые поля нулем
Car::Car() : engineVolume(0.0) {}

// Конструктор с параметрами: заполняем поля переданными значениями
Car::Car(wstring b, wstring m, double v, wstring c, wstring t)
    : brand(b), model(m), engineVolume(v), color(c), transmission(t) {}

// Деструктор (оставляем пустым, так как динамической памяти внутри класса нет)
Car::~Car() {}

// Возвращает строковый тип данного класса (используется при десериализации)
wstring Car::getType() const {
    return L"Car";
}

// Запрос и ввод характеристик автомобиля с использованием широкосимвольного ввода (wcin)
void Car::input() {
    wcout << L"Введите марку автомобиля: "; wcin >> brand;
    wcout << L"Введите модель автомобиля: "; wcin >> model;
    wcout << L"Введите объем двигателя (л): "; wcin >> engineVolume;
    wcout << L"Введите цвет: "; wcin >> color;
    wcout << L"Введите тип КПП (механика/автомат): "; wcin >> transmission;
}

// Вывод полной информации об автомобиле в консоль (wcout)
void Car::display() const {
    wcout << L"[Автомобиль] Марка: " << brand << L", Модель: " << model
          << L", Объем: " << engineVolume << L" л, Цвет: " << color
          << L", КПП: " << transmission << endl;
}

// Запись полей автомобиля в файл построчно
void Car::save(wofstream& out) const {
    out << L"Car\n" << brand << L"\n" << model << L"\n"
        << engineVolume << L"\n" << color << L"\n" << transmission << L"\n";
}

// Чтение полей автомобиля из файла
void Car::load(wifstream& in) {
    in >> brand >> model >> engineVolume >> color >> transmission;
}