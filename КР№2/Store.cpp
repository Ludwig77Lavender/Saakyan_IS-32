#include "Store.h"
#include <iostream>

Store::Store(std::string name, std::string category)
    : name(name), category(category) {
}

void Store::addEmployee(Employee employee) {
    employees.push_back(employee);
}

void Store::addProduct(Product product) {
    products.push_back(product);
}

void Store::listEmployees() {
    std::cout << "Сотрудники в магазине " << name << ":\n";
    for (auto& employee : employees) {
        std::cout << employee.getName() << " - " << employee.getPosition() << std::endl;
    }
}

void Store::listProducts() {
    std::cout << "Товары в магазине " << name << ":\n";
    for (auto& product : products) {
        std::cout << product.getName() << " - " << product.getPrice() << " руб, В наличии: " << product.getStock() << " шт." << std::endl;
    }
}

std::string Store::getName() {
    return name;
}

std::string Store::getCategory() {
    return category;
}