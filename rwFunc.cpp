#include "rwFunc.hpp"
#include <iostream>
#include <sstream>


bool readProductsFromFile(const string& filename, vector<Product>& products) {
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла для чтения: " << filename << endl;
        return false;
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string token;
        Product product;

        // Чтение ID
        getline(ss, token, ';');
        product.id = stoi(token);

        // Чтение кода категории
        getline(ss, token, ';');
        product.code = stoi(token);

        // Чтение названия продукта
        getline(ss, product.nameproduct, ';');

        // Чтение места хранения
        getline(ss, product.place, ';');

        // Чтение срока годности
        getline(ss, token, ';');
        product.srok = stoi(token);

        // Чтение количества
        getline(ss, token, ';');
        product.kolvo = stoi(token);

        products.push_back(product);
    }

    inputFile.close();
    return true;
}

bool writeToFile(const string& filename, const vector<Product>& products) {
    ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        cerr << "Ошибка открытия файла для записи: " << filename << endl;
        return false;
    }

    for (const auto& product : products) {
        outputFile << product.id << ";"
                   << product.code << ";"
                   << product.nameproduct << ";"
                   << product.place << ";"
                   << product.srok << ";"
                   << product.kolvo << ";\n";
    }

    outputFile.close();
    return true;
}