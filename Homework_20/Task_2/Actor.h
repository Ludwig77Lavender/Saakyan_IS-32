#pragma once
#include "Employee.h"

class Actor : public Employee {
private:
    std::string role;
public:
    Actor(std::string name, int id, std::string role);
    void displayInfo() override;
};