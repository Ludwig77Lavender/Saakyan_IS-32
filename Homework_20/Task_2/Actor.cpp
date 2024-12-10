#include "Actor.h"
#include <iostream>

Actor::Actor(std::string name, int id, std::string role) : Employee(name, id, "Актёр"), role(role) {}

void Actor::displayInfo() {
    std::cout << "Актёр: " << name << ", ID: " << id << ", Роль: " << role << std::endl;
}