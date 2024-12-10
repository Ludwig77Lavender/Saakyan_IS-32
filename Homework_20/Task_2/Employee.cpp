#include "Employee.h"
#include <iostream>

Employee::Employee(std::string name, int id, std::string position) : Person(name, id), position(position) {}

void Employee::displayInfo() {
    std::cout << "Сотрудник: " << name << ", ID: " << id << ", Должность: " << position << std::endl;
}