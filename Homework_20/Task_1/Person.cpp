#include "Person.h"
#include <iostream>

Person::Person(std::string name, int id)
    : name(name), id(id) {}

Staff::Staff(std::string name, int id, std::string position)
    : Person(name, id), position(position) {}

void Staff::displayInfo() {}

Librarian::Librarian(std::string name, int id, std::string position)
    : Staff(name, id, position) {}

void Librarian::displayInfo() {
    std::cout << "Библиотекарь: " << name << ", ID: " << id << ", Должность: " << position << std::endl;
}

Assistant::Assistant(std::string name, int id, std::string position)
    : Staff(name, id, position) {}

void Assistant::displayInfo() {
    std::cout << "Ассистент: " << name << ", ID: " << id << ", Должность: " << position << std::endl;
}