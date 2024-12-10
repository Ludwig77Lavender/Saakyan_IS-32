#include "Booking.h"
#include <iostream>

Booking::Booking(Client* client, Ticket* ticket, Session* session) : client(client), ticket(ticket), session(session) {}

void Booking::displayInfo() {
    std::cout << "Бронирование:" << std::endl;
    client->displayInfo();
    ticket->displayInfo();
    session->displayInfo();
}