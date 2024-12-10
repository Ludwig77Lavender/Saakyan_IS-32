#pragma once
#include <vector>
#include "Book.h"
#include "Client.h"
#include "Person.h"

class Loan;

class Library {
private:
    std::vector<Book*> books;
    std::vector<Staff*> staff;
    std::vector<Client*> clients;
    std::vector<Loan*> loans;
public:
    void addBook(Book* book);
    void addStaff(Staff* staffMember);
    void addClient(Client* client);
    void loanBook(Book* book, Client* client);
    void displayAllBooks();
    void displayAllStaff();
    void displayAllClients();
    void displayAllLoans();
    Book* getBook(std::string title);
    Client* getClient(int id);
    ~Library();
};

class Loan {
private:
    Book* book;
    Client* client;
public:
    Loan(Book* book, Client* client);
    void displayInfo();
};