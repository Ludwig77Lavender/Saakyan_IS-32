#include "Director.h"
#include <iostream>

Director::Director(std::string name, int id) : Employee(name, id, "�������") {}

void Director::displayInfo() {
    std::cout << "�������: " << name << ", ID: " << id << std::endl;
}