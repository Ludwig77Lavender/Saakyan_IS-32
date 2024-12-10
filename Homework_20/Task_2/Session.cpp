#include "Session.h"
#include <iostream>

Session::Session(Performance* performance) : performance(performance) {}

void Session::addTicket(Ticket* ticket) {
    tickets.push_back(ticket);
}

void Session::displayInfo() {
    performance->displayInfo();
    std::cout << "Билеты на спектакль:" << std::endl;
    for (auto& ticket : tickets) {
        ticket->displayInfo();
    }
}

Ticket* Session::getTicket(int seatNumber) {
    for (auto& ticket : tickets) {
        if (ticket->getSeatNumber() == seatNumber) {
            return ticket;
        }
    }
    return nullptr;
}

Session::~Session() {
    for (auto& ticket : tickets) {
        delete ticket;
    }
}