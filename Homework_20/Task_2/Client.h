#pragma once
#include "Person.h"

class Client : public Person {
public:
    Client(std::string name, int id);
    void displayInfo() override;
    int getId();
};