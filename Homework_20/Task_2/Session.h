#pragma once
#include "Performance.h"
#include "Ticket.h"
#include <vector>

class Session {
private:
    Performance* performance;
    std::vector<Ticket*> tickets;
public:
    Session(Performance* performance);
    void addTicket(Ticket* ticket);
    void displayInfo();
    Ticket* getTicket(int seatNumber);  // Метод для получения билета по номеру места
    ~Session();
};