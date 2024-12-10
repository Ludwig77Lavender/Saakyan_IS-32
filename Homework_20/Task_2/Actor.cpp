#include "Actor.h"
#include <iostream>

Actor::Actor(std::string name, int id, std::string role) : Employee(name, id, "����"), role(role) {}

void Actor::displayInfo() {
    std::cout << "����: " << name << ", ID: " << id << ", ����: " << role << std::endl;
}