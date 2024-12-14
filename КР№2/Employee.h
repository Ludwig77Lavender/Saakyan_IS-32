#pragma once
#include <string>

class Employee {
private:
    std::string name;
    std::string position;
    double salary;
public:
    Employee(std::string name, std::string position, double salary);
    std::string getName();
    std::string getPosition();
    double getSalary();
};