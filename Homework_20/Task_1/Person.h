#pragma once
#include <string>

class Person {
protected:
    std::string name;
    int id;
public:
    Person(std::string name, int id);
    virtual ~Person() = default;
    virtual void displayInfo() = 0;  // Абстрактный метод
};

class Staff : public Person {
protected:
    std::string position;
public:
    Staff(std::string name, int id, std::string position);
    void displayInfo() override;
};

class Librarian : public Staff {
public:
    Librarian(std::string name, int id, std::string position);
    void displayInfo() override;
};

class Assistant : public Staff {
public:
    Assistant(std::string name, int id, std::string position);
    void displayInfo() override;
};