#include <iostream>
#include <string>
#include "Library.h"

int main() {
    setlocale(LC_ALL, "RU");

    Library library;

    // Добавление книг
    library.addBook(new EBook("1984", "Джордж Оруэлл", 1949, "PDF"));
    library.addBook(new PrintedBook("Скотный двор", "Джордж Оруэлл", 1945, 320));

    // Добавление сотрудников
    library.addStaff(new Librarian("Анна Иванова", 1, "Главный библиотекарь"));
    library.addStaff(new Assistant("Иван Петров", 2, "Ассистент главного библиотекаря"));

    // Добавление клиентов
    library.addClient(new RegularClient("Алиса Ленская", 1001, "Постоянный"));
    library.addClient(new VIPClient("Роберт Полсон", 1002, "VIP"));

    // Отображение всей информации о книгах, сотрудниках и клиентах
    std::cout << "Книги в библиотеке:" << std::endl;
    library.displayAllBooks();

    std::cout << "\nСотрудники библиотеки:" << std::endl;
    library.displayAllStaff();

    std::cout << "\nКлиенты библиотеки:" << std::endl;
    library.displayAllClients();

    // Выдача книги клиенту
    Book* book = library.getBook("1984");
    Client* client = library.getClient(1001);
    if (book && client) {
        library.loanBook(book, client);
    }

    // Отображение информации о выданных книгах
    std::cout << "\nВыданные книги:" << std::endl;
    library.displayAllLoans();

    return 0;
}