#include <iostream>
#include "Theatre.h"
#include "Booking.h"
#include "Actor.h"
#include "Director.h"

int main() {
    setlocale(LC_ALL, "RU");

    Theatre theatre;

    // Добавление сотрудников
    theatre.addEmployee(new Actor("Иван Иванов", 1, "Ромео"));
    theatre.addEmployee(new Actor("Диана Иванова", 2, "Джульетта"));
    theatre.addEmployee(new Director("Анна Петрова", 3));

    // Добавление сеансов
    Performance* performance = new Performance("Ромео и Джульетта", 120);
    Session* session = new Session(performance);
    session->addTicket(new Ticket(1, 500));
    session->addTicket(new Ticket(2, 500));
    theatre.addSession(session);
    
    // Добавление клиентов
    theatre.addClient(new Client("Мария Смирнова", 1001));

    // Отображение всей информации
    theatre.displayAllEmployees(); // О сотрудниках
    std::cout << std::endl;
    theatre.displayAllSessions(); // О сеансах
    std::cout << std::endl;
    theatre.displayAllClients(); // О клиентах
    std::cout << std::endl;

    // Добавление бронирования билетов
    Client* client = theatre.getClient(1001);
    Ticket* ticket = session->getTicket(1);
    if (client && ticket) {
        Booking* booking = new Booking(client, ticket, session);
        booking->displayInfo();
        delete booking;
    }

    delete performance;
    delete session;

    return 0;
}