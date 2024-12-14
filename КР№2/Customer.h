#pragma once
#include <string>

class Customer {
private:
    std::string name;
    std::string email;
    std::string phone;
public:
    Customer(std::string name, std::string email, std::string phone);
    std::string getName();
    std::string getEmail();
    std::string getPhone();
};