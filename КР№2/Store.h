#pragma once
#include <vector>
#include "Employee.h"
#include "Product.h"

class Store {
private:
    std::string name;
    std::string category;
    std::vector<Employee> employees;
    std::vector<Product> products;
public:
    Store(std::string name, std::string category);
    void addEmployee(Employee employee);
    void addProduct(Product product);
    void listEmployees();
    void listProducts();

    std::string getName();
    std::string getCategory();
};