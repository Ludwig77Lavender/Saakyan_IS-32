#pragma once
#include <string>

class Ticket {
private:
    int seatNumber;
    double price;
public:
    Ticket(int seatNumber, double price);
    void displayInfo();
    int getSeatNumber();
};