#pragma once
#include "Person.h"

class Client : public Person {
protected:
    std::string membership;
public:
    Client(std::string name, int id, std::string membership);
    void displayInfo() override;
    int getId();
};

class RegularClient : public Client {
public:
    RegularClient(std::string name, int id, std::string membership);
    void displayInfo() override;
};

class VIPClient : public Client {
public:
    VIPClient(std::string name, int id, std::string membership);
    void displayInfo() override;
};