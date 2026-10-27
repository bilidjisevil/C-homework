#include "Keeper.h"
#include <locale>
#include <codecvt>

Keeper::Keeper() {}

Keeper::~Keeper() {}

void Keeper::add(int choice) {
    shared_ptr<Base> item = nullptr;
    if (choice == 1) item = make_shared<Car>();
    else if (choice == 2) item = make_shared<Motorcycle>();
    else if (choice == 3) item = make_shared<Bus>();

    if (item) {
        item->input();
        items.push_back(item);
        wcout << L"Объект успешно добавлен в гараж.\n";
    }
    else {
        wcout << L"Неверный выбор типа объекта.\n";
    }
}

void Keeper::remove(size_t index) {
    if (index < items.size()) {
        items.erase(items.begin() + index);
        wcout << L"Объект под индексом " << index << L" удален.\n";
    }
    else {
        wcout << L"Ошибка: введен несуществующий индекс.\n";
    }
}

void Keeper::displayAll() const {
    if (items.empty()) {
        wcout << L"Гараж пуст.\n";
        return;
    }
    for (size_t i = 0; i < items.size(); ++i) {
        wcout << i << L". ";
        items[i]->display();
    }
}

void Keeper::saveToFile(const string& filename) const {
    wofstream out(filename);
    out.imbue(locale("ru_RU.UTF-8")); // Корректная запись кириллицы в файл
    if (!out) {
        wcout << L"Ошибка открытия файла для записи!\n";
        return;
    }

    out << items.size() << L"\n";
    for (const auto& item : items) {
        item->save(out);
    }
    wcout << L"Данные успешно сохранены в файл " << filename.c_str() << L".\n";
}

void Keeper::loadFromFile(const string& filename) {
    wifstream in(filename);
    in.imbue(locale("ru_RU.UTF-8")); // Корректное чтение кириллицы из файла
    if (!in) {
        wcout << L"Ошибка открытия файла для чтения!\n";
        return;
    }

    size_t size;
    in >> size;
    items.clear();

    for (size_t i = 0; i < size; ++i) {
        wstring type;
        in >> type;

        shared_ptr<Base> item = nullptr;
        if (type == L"Car") item = make_shared<Car>();
        else if (type == L"Motorcycle") item = make_shared<Motorcycle>();
        else if (type == L"Bus") item = make_shared<Bus>();

        if (item) {
            item->load(in);
            items.push_back(item);
        }
    }
    wcout << L"Данные успешно восстановлены из файла " << filename.c_str() << L".\n";
}