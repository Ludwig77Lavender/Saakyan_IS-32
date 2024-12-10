#pragma once
#include "Client.h"
#include "Ticket.h"
#include "Session.h"

class Booking {
private:
    Client* client;
    Ticket* ticket;
    Session* session;
public:
    Booking(Client* client, Ticket* ticket, Session* session);
    void displayInfo();
};