#include "Product.h"

Product::Product(std::string name, double price, int stock)
    : name(name), price(price), stock(stock) {
}

std::string Product::getName() {
    return name;
}

double Product::getPrice() {
    return price;
}

int Product::getStock() {
    return stock;
}
