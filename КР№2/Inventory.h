#pragma once
#include <vector>
#include <string>
#include <locale>
#include <codecvt>
#include "Product.h"

class Inventory {
private:
    std::vector<Product> products;
public:
    void addProduct(Product product);
    void listProducts();
};