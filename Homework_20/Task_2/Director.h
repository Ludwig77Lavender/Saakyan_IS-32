#pragma once
#include "Employee.h"

class Director : public Employee {
public:
    Director(std::string name, int id);
    void displayInfo() override;
};