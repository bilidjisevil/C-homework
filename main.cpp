#include "Keeper.h"
#include <windows.h>

int main() {
    // Принудительно устанавливаем кодировку консоли на UTF-8 (65001)
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // Настраиваем глобальную локаль для поддержки русских широких символов (wchar_t)
    setlocale(LC_ALL, "Russian");
    locale::global(locale("ru_RU.UTF-8"));
    wcin.imbue(locale("ru_RU.UTF-8"));
    wcout.imbue(locale("ru_RU.UTF-8"));

    Keeper garage;
    int choice;

    do {
        wcout << L"\nМЕНЮ УПРАВЛЕНИЯ ГАРАЖОМ\n"
            << L"1. Добавить автомобиль\n"
            << L"2. Добавить мотоцикл\n"
            << L"3. Добавить автобус\n"
            << L"4. Удалить объект по индексу\n"
            << L"5. Показать все объекты\n"
            << L"6. Сохранить данные в файл\n"
            << L"7. Загрузить данные из файла\n"
            << L"0. Выход\n"
            << L"Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: garage.add(1); break;
        case 2: garage.add(2); break;
        case 3: garage.add(3); break;
        case 4: {
            size_t idx;
            wcout << L"Введите индекс объекта для удаления: ";
            cin >> idx;
            garage.remove(idx);
            break;
        }
        case 5: garage.displayAll(); break;
        case 6: garage.saveToFile("garage_data.txt"); break;
        case 7: garage.loadFromFile("garage_data.txt"); break;
        case 0: wcout << L"Выход из программы.\n"; break;
        default: wcout << L"Неверный пункт меню. Выберите число от 0 до 7.\n";
        }
    } while (choice != 0);

    return 0;
}