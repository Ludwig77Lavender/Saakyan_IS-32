#include "Mall.h"
#include <iostream>

Mall::Mall(std::string name, std::string location)
    : name(name), location(location) {
}
void Mall::addStore(Store store) {
    stores.push_back(store);
}
void Mall::listStores() {
    std::cout << "Магазины в " << name << " по адресу " << location << ":\n";
    for (auto& store : stores) {
        std::cout << "Магазин: " << store.getName() << ", Категория: " << store.getCategory() << std::endl;
    }
}