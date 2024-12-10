#include "Theatre.h"
#include <iostream>

void Theatre::addEmployee(Employee* employee) {
    employees.push_back(employee);
}

void Theatre::addSession(Session* session) {
    sessions.push_back(session);
}

void Theatre::addClient(Client* client) {
    clients.push_back(client);
}

void Theatre::displayAllEmployees() {
    std::cout << "Сотрудники театра:" << std::endl;
    for (auto& employee : employees) {
        employee->displayInfo();
    }
}

void Theatre::displayAllSessions() {
    std::cout << "Сеансы:" << std::endl;
    for (auto& session : sessions) {
        session->displayInfo();
    }
}

void Theatre::displayAllClients() {
    std::cout << "Клиенты:" << std::endl;
    for (auto& client : clients) {
        client->displayInfo();
    }
}

Client* Theatre::getClient(int id) {
    for (auto& client : clients) {
        if (client->getId() == id) {
            return client;
        }
    }
    return nullptr;
}

Theatre::~Theatre() {
    for (auto& employee : employees) {
        delete employee;
    }
    for (auto& session : sessions) {
        delete session;
    }
    for (auto& client : clients) {
        delete client;
    }
}