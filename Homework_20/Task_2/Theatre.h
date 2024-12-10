#pragma once
#include <vector>
#include "Employee.h"
#include "Session.h"
#include "Client.h"

class Theatre {
private:
    std::vector<Employee*> employees;
    std::vector<Session*> sessions;
    std::vector<Client*> clients;
public:
    void addEmployee(Employee* employee);
    void addSession(Session* session);
    void addClient(Client* client);
    void displayAllEmployees();
    void displayAllSessions();
    void displayAllClients();
    Client* getClient(int id);
    ~Theatre();
};