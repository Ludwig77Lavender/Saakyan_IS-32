#pragma once
#include <string>

class Person {
protected:
    std::string name;
    int id;
public:
    Person(std::string name, int id);
    virtual ~Person() = default;
    virtual void displayInfo() = 0;
};