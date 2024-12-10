#include "Ticket.h"
#include <iostream>

Ticket::Ticket(int seatNumber, double price) : seatNumber(seatNumber), price(price) {}

void Ticket::displayInfo() {
    std::cout << "Билет: Место " << seatNumber << ", Цена: " << price << " руб." << std::endl;
}

int Ticket::getSeatNumber() {
    return seatNumber;
}