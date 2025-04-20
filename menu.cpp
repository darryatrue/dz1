#include "menu.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#include "rwFunc.hpp"

using namespace std;

void displayProducts(const vector<Product>& products) {
    cout << "\nСписок продуктов на складе:\n";
    cout << "-------------------------------------------------------------------\n";
    cout << "ID | Код | Название продукта    | Место хранения | Срок годности | Количество\n";

    cout << "-------------------------------------------------------------------\n";

    for (const auto& product : products) {
        cout << setw(2) << product.id << " | "
             << setw(3) << product.code << " | "
             << setw(20) << product.nameproduct << " | "
             << setw(14) << product.place << " | "
             << setw(13) << product.srok << " | "
             << setw(10) << product.kolvo << endl;
    }
    cout << "-------------------------------------------------------------------\n";
}

void aboutProgram() {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    cout << "\nИнформация о программе:\n";
    cout << "-----------------------\n";
    cout << "Автор: Трушина Дарья Дмитриевна\n";
    cout << "Курс: 2\n";
    cout << "Группа: 2\n";
    cout << "Вариант: Продуктовый склад\n"; // Updated variant name
    cout << "Дата компиляции: 20.04.25"
         << 1900 + ltm->tm_year << "-"
         << 1 + ltm->tm_mon << "-"
         << ltm->tm_mday << " "
         << ltm->tm_hour << ":"
         << ltm->tm_min << ":"
         << ltm->tm_sec << "\n";
    cout << "-----------------------\n";
}

void menu() {
    vector<Product> products;
    string filename = "productwarehouse.db"; // Updated filename
    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Открыть файл\n";
        cout << "2. Сохранить файл\n";
        cout << "3. Вывести на экран список продуктов\n";
        cout << "4. О программе\n";
        cout << "5. Выход\n";
        cout << "Выберите пункт меню: ";
        cin >> choice;
        cin.ignore(); // Очистка буфера

        switch (choice) {
            case 1:
                if (readProductsFromFile(filename, products)) {
                    cout << "Файл успешно загружен!\n";
                }
                break;
            case 2:
                if (writeToFile(filename, products)) {
                    cout << "Файл успешно сохранен!\n";
                }
                break;
            case 3:
                if (!products.empty()) {
                    displayProducts(products);
                } else {
                    cout << "Список пуст. Сначала загрузите данные из файла.\n";
                }
                break;
            case 4:
                aboutProgram();
                break;
            case 5:
                cout << "Выход из программы...\n";
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 5);
}