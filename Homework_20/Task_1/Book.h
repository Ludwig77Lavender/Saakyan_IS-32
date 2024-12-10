#pragma once
#include <string>

class Book {
protected:
    std::string title;
    std::string author;
    int year;
public:
    Book(std::string title, std::string author, int year);
    virtual ~Book() = default;
    virtual void displayInfo() = 0;
    std::string getTitle();
};

class EBook : public Book {
private:
    std::string fileFormat;
public:
    EBook(std::string title, std::string author, int year, std::string fileFormat);
    void displayInfo() override;
};

class PrintedBook : public Book {
private:
    int pages;
public:
    PrintedBook(std::string title, std::string author, int year, int pages);
    void displayInfo() override;
};