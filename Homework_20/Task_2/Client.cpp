#include "Client.h"
#include <iostream>

Client::Client(std::string name, int id) : Person(name, id) {}

void Client::displayInfo() {
    std::cout << "Клиент: " << name << ", ID: " << id << std::endl;
}

int Client::getId() {
    return id;
}