#include "Director.h"
#include <iostream>

Director::Director(std::string name, int id) : Employee(name, id, "–ежиссЄр") {}

void Director::displayInfo() {
    std::cout << "–ежиссЄр: " << name << ", ID: " << id << std::endl;
}