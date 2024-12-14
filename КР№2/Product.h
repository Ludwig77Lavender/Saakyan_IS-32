#pragma once
#include <string>

class Product {
private:
    std::string name;
    double price;
    int stock;
public:
    Product(std::string name, double price, int stock);
    std::string getName();
    double getPrice();
    int getStock();
};