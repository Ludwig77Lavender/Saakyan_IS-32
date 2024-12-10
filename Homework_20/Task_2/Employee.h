#pragma once
#include "Person.h"

class Employee : public Person {
protected:
    std::string position;
public:
    Employee(std::string name, int id, std::string position);
    void displayInfo() override;
};