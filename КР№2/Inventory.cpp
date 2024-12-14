#include "Inventory.h"
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

void Inventory::addProduct(Product product) {
    products.push_back(product);
}

void Inventory::listProducts() {
    //std::locale::global(std::locale(""));
    //wchar_t rubl = L'\u20BD';
    std::cout << "Инвентарь:" << std::endl;
    for (auto& product : products) {
        std::cout << product.getName() << " " << product.getPrice() << " руб, Количество: " << product.getStock() << " шт." << std::endl;
    }
}