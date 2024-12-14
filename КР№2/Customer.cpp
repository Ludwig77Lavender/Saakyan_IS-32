#include "Customer.h"

Customer::Customer(std::string name, std::string email, std::string phone)
    : name(name), email(email), phone(phone) {
}
std::string Customer::getName() {
    return name;
}
std::string Customer::getEmail() {
    return email;
}
std::string Customer::getPhone() {
    return phone;
}