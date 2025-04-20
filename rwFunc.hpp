#ifndef RWFUNC_HPP
#define RWFUNC_HPP

#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct Product {
    int id;
    int code;
    string nameproduct;
    string place;
    int srok;
    int kolvo;
};

bool readProductsFromFile(const string& filename, vector<Product>& products);
bool writeToFile(const string& filename, const vector<Product>& products);

#endif