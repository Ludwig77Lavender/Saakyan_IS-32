#include "Client.h"
#include <iostream>

Client::Client(std::string name, int id, std::string membership)
    : Person(name, id), membership(membership) {}

void Client::displayInfo() {}

RegularClient::RegularClient(std::string name, int id, std::string membership)
    : Client(name, id, membership) {}

void RegularClient::displayInfo() {
    std::cout << "Постоянный клиент: " << name << ", ID: " << id << ", Членство: " << membership << std::endl;
}

VIPClient::VIPClient(std::string name, int id, std::string membership)
    : Client(name, id, membership) {}

void VIPClient::displayInfo() {
    std::cout << "VIP Клиент: " << name << ", ID: " << id << ", Членство: " << membership << std::endl;
}

int Client::getId() {
    return id;
}