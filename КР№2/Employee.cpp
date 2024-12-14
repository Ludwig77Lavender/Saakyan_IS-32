#include "Employee.h"

Employee::Employee(std::string name, std::string position, double salary)
    : name(name), position(position), salary(salary) {
}

std::string Employee::getName() {
    return name;
}

std::string Employee::getPosition() {
    return position;
}

double Employee::getSalary() {
    return salary;
}