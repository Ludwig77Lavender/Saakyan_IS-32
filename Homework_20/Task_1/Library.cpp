#include "Library.h"
#include <iostream>

void Library::addBook(Book* book) {
    books.push_back(book);
}

void Library::addStaff(Staff* staffMember) {
    staff.push_back(staffMember);
}

void Library::addClient(Client* client) {
    clients.push_back(client);
}

void Library::loanBook(Book* book, Client* client) {
    Loan* loan = new Loan(book, client);
    loans.push_back(loan);
}

void Library::displayAllBooks() {
    for (auto& book : books) {
        book->displayInfo();
    }
}

void Library::displayAllStaff() {
    for (auto& staffMember : staff) {
        staffMember->displayInfo();
    }
}

void Library::displayAllClients() {
    for (auto& client : clients) {
        client->displayInfo();
    }
}

void Library::displayAllLoans() {
    for (auto& loan : loans) {
        loan->displayInfo();
    }
}

Book* Library::getBook(std::string title) {
    for (auto& book : books) {
        if (book->getTitle() == title) {
            return book;
        }
    }
    return nullptr;
}

Client* Library::getClient(int id) {
    for (auto& client : clients) {
        if (client->getId() == id) {
            return client;
        }
    }
    return nullptr;
}

Library::~Library() {
    for (auto& book : books) {
        delete book;
    }
    for (auto& staffMember : staff) {
        delete staffMember;
    }
    for (auto& client : clients) {
        delete client;
    }
    for (auto& loan : loans) {
        delete loan;
    }
}

Loan::Loan(Book* book, Client* client) : book(book), client(client) {}

void Loan::displayInfo() {
    std::cout << "Информация о выдаче: ";
    book->displayInfo();
    client->displayInfo();
}