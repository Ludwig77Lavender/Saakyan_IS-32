#include <iostream>
#include "Theatre.h"
#include "Booking.h"
#include "Actor.h"
#include "Director.h"

int main() {
    setlocale(LC_ALL, "RU");

    Theatre theatre;

    // ���������� �����������
    theatre.addEmployee(new Actor("���� ������", 1, "�����"));
    theatre.addEmployee(new Actor("����� �������", 2, "���������"));
    theatre.addEmployee(new Director("���� �������", 3));

    // ���������� �������
    Performance* performance = new Performance("����� � ���������", 120);
    Session* session = new Session(performance);
    session->addTicket(new Ticket(1, 500));
    session->addTicket(new Ticket(2, 500));
    theatre.addSession(session);
    
    // ���������� ��������
    theatre.addClient(new Client("����� ��������", 1001));

    // ����������� ���� ����������
    theatre.displayAllEmployees(); // � �����������
    std::cout << std::endl;
    theatre.displayAllSessions(); // � �������
    std::cout << std::endl;
    theatre.displayAllClients(); // � ��������
    std::cout << std::endl;

    // ���������� ������������ �������
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