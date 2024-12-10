#include "Book.h"
#include <iostream>

Book::Book(std::string title, std::string author, int year)
    : title(title), author(author), year(year) {}

EBook::EBook(std::string title, std::string author, int year, std::string fileFormat)
    : Book(title, author, year), fileFormat(fileFormat) {}

void EBook::displayInfo() {
    std::cout << "Эл-Книга: " << title << " от " << author << ", " << year << " [" << fileFormat << "]" << std::endl;
}

PrintedBook::PrintedBook(std::string title, std::string author, int year, int pages)
    : Book(title, author, year), pages(pages) {}

void PrintedBook::displayInfo() {
    std::cout << "Печатное издание: " << title << " от " << author << ", " << year << " [" << pages << " страниц]" << std::endl;
}

std::string Book::getTitle() {
    return title;
}