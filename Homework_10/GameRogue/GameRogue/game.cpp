#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool start = true;
int health = 3;
int score = 0;

int treasure[3] = { 1, 1, 1 };
int monsters[4] = { 1, 1, 1, 1 };
int kills = 0;
int gameResult = -1;

char invent[3] = { '-', ' ', ' ' };

/* �������������� �������� ��������������� ��� */
//char weapon[2] = { 'S', 'H' };
//int damage = 1;

int x = 3;
int y = 2;
char letter;

void inventory() {
    cout << "=���������=" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ": " << invent[i] << endl;
    }
}

void playGame() {
    srand(time(0));

    int computerChoice = 1 + rand() % 3;
    char playerChoice;

    cout << "�� ��������� �������! �������� � ��� � ����." << endl;
    cout << "�������� 1 - ������; 2 - �������; 3 - ������: ";
    cin >> playerChoice;

    while (playerChoice != '1' && playerChoice != '2' && playerChoice != '3') {
        cout << "������������ ��������!" << endl;
        cout << "�������� 1 - ������; 2 - �������; 3 - ������: ";
        cin >> playerChoice;
    }

    cout << "��� �����: ";
    switch (playerChoice) {
    case '1': cout << "������"; break;
    case '2': cout << "�������"; break;
    case '3': cout << "������"; break;
    }

    cout << "\n����� �������: ";
    switch (computerChoice) {
    case 1: cout << "������"; break;
    case 2: cout << "�������"; break;
    case 3: cout << "������"; break;
    }
    cout << endl;

    if (playerChoice == computerChoice) {
        cout << "�����! ������ ������." << endl;
        gameResult = 2;
    }
    else {
        switch (playerChoice) {
        case '1':
            if (computerChoice == 2) {
                cout << "�� ��������! ������ ���� �������.\n������ ����." << endl;
                gameResult = 1;
            }
            else {
                cout << "�� ���������! ������ ��������� ������.\n������ ������." << endl;
                gameResult = 0;
            }
            break;
        case '2':
            if (computerChoice == 3) {
                cout << "�� ��������! ������� ����� ������.\n������ ����." << endl;
                gameResult = 1;
            }
            else {
                cout << "�� ���������! ������ ���� �������.\n������ ������." << endl;
                gameResult = 0;
            }
            break;
        case '3':
            if (computerChoice == 1) {
                cout << "�� ��������! ������ ��������� ������.\n������ ����." << endl;
                gameResult = 1;
            }
            else {
                cout << "�� ���������! ������� ����� ������.\n������ ������." << endl;
                gameResult = 0;
            }
            break;
        }
    }

    if (gameResult == 0) {
        health--;
    }
    else if (gameResult == 1) {
        score += 2;
        kills++;
    }
    else if (gameResult == 2) {
        score++;
    }
}

/*======================================================================================*/
void room1() {
    if (x == 3 && y == 2) {
        cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|?????|  # - �����\n|?#?##|  ? - ����\n|??@?#|\n|##???|\n" << endl;
        cout << "���� �����: " << health << endl;
        cout << "���� ����: " << score << endl;
        cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
        cout << "W - �����; S - �����; A - �����; D - ������; I - ���������" << endl;
        cout << "�� ������: ";
        cin >> letter;
        cout << endl;

        if (letter == 'W') y++;
        else if (letter == 'S') y--;
        else if (letter == 'A') x--;
        else if (letter == 'D') x++;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'W' && letter != 'S' && letter != 'A' && letter != 'D' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "������������ �����������!" << endl;
            }
            cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|?????|  # - �����\n|?#?##|  ? - ����\n|??@?#|\n|##???|\n" << endl;
            cout << "���� �����: " << health << endl;
            cout << "���� ����: " << score << endl;
            cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
            cout << "W - �����; S - �����; A - �����; D - ������; I - ���������" << endl;
            cout << "�� ������: ";
            cin >> letter;
            cout << endl;

            if (letter == 'W') y++;
            else if (letter == 'S') y--;
            else if (letter == 'A') x--;
            else if (letter == 'D') x++;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_2_5() {
    if (x == 2 && y == 5) {
        if (treasure[2] == 1) {
            cout << "�� ����� ������! +1 ����" << endl;
            score++;
            treasure[2] = 0;
        }
        if (monsters[2] == 1) {
            playGame();
            monsters[2] = 0;
        }
        if (health == 0) {
            !start;
            cout << "\n�� ���������... ��� ���� ������." << endl;
            cout << "���� ����: " << score << endl;
            cout << "�������� �����: " << kills << endl;
            return;
        }
        cout << "\n���� ����� ���������:\n|#@##?|  @ - ��\n|?????|  # - �����\n|?#?##|  ? - ����\n|????#|\n|##???|\n" << endl;
        cout << "���� �����: " << health << endl;
        cout << "���� ����: " << score << endl;
        cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
        cout << "S - �����; I - ���������" << endl;
        cout << "�� ������: ";
        cin >> letter;
        cout << endl;

        if (letter == 'S') y--;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'S' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "������������ �����������!" << endl;
            }
            cout << "\n���� ����� ���������:\n|#@##?|  @ - ��\n|?????|  # - �����\n|?#?##|  ? - ����\n|????#|\n|##???|\n" << endl;
            cout << "���� �����: " << health << endl;
            cout << "���� ����: " << score << endl;
            cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
            cout << "S - �����; I - ���������" << endl;
            cout << "�� ������: ";
            cin >> letter;
            cout << endl;

            if (letter == 'S') y--;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_5_5() {
    if (x == 5 && y == 5) {
        cout << "\n���� ����� ���������:\n|#?##@|  @ - ��\n|?????|  # - �����\n|?#?##|  ? - ����\n|????#|\n|##???|\n" << endl;
        cout << "�� ����� ��������� � ��������� �� ������!" << endl;
        cout << "���� ������� ������: " << health << endl;
        cout << "���� �������� ����: " << score << endl;
        cout << "����� �������� �����: " << kills << endl;

        start = false;
        letter = '\0';
    }
}
/*======================================================================================*/
void room_1_4() {
    if (x == 1 && y == 4) {
        cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|@????|  # - �����\n|?#?##|  ? - ����\n|????#|\n|##???|\n" << endl;
        cout << "���� �����: " << health << endl;
        cout << "���� ����: " << score << endl;
        cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
        cout << "S - �����; D - ������; I - ���������" << endl;
        cout << "�� ������: ";
        cin >> letter;
        cout << endl;

        if (letter == 'S') y--;
        else if (letter == 'D') x++;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'S' && letter != 'D' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "������������ �����������!" << endl;
            }
            cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|@????|  # - �����\n|?#?##|  ? - ����\n|????#|\n|##???|\n" << endl;
            cout << "���� �����: " << health << endl;
            cout << "���� ����: " << score << endl;
            cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
            cout << "S - �����; D - ������; I - ���������" << endl;
            cout << "�� ������: ";
            cin >> letter;
            cout << endl;

            if (letter == 'S') y--;
            else if (letter == 'D') x++;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_2_4() {
    if (x == 2 && y == 4) {
        cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|?@???|  # - �����\n|?#?##|  ? - ����\n|????#|\n|##???|\n" << endl;
        cout << "���� �����: " << health << endl;
        cout << "���� ����: " << score << endl;
        cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
        cout << "W - �����; A - �����; D - ������; I - ���������" << endl;
        cout << "�� ������: ";
        cin >> letter;
        cout << endl;

        if (letter == 'W') y++;
        else if (letter == 'A') x--;
        else if (letter == 'D') x++;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'W' && letter != 'A' && letter != 'D' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "������������ �����������!" << endl;
            }
            cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|?@???|  # - �����\n|?#?##|  ? - ����\n|????#|\n|##???|\n" << endl;
            cout << "���� �����: " << health << endl;
            cout << "���� ����: " << score << endl;
            cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
            cout << "W - �����; A - �����; D - ������; I - ���������" << endl;
            cout << "�� ������: ";
            cin >> letter;
            cout << endl;

            if (letter == 'W') y++;
            else if (letter == 'A') x--;
            else if (letter == 'D') x++;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_3_4() {
    if (x == 3 && y == 4) {
        cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|??@??|  # - �����\n|?#?##|  ? - ����\n|????#|\n|##???|\n" << endl;
        cout << "���� �����: " << health << endl;
        cout << "���� ����: " << score << endl;
        cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
        cout << "S - �����; A - �����; D - ������; I - ���������" << endl;
        cout << "�� ������: ";
        cin >> letter;
        cout << endl;

        if (letter == 'S') y--;
        else if (letter == 'A') x--;
        else if (letter == 'D') x++;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'S' && letter != 'A' && letter != 'D' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "������������ �����������!" << endl;
            }
            cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|??@??|  # - �����\n|?#?##|  ? - ����\n|????#|\n|##???|\n" << endl;
            cout << "���� �����: " << health << endl;
            cout << "���� ����: " << score << endl;
            cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
            cout << "S - �����; A - �����; D - ������; I - ���������" << endl;
            cout << "�� ������: ";
            cin >> letter;
            cout << endl;

            if (letter == 'S') y--;
            else if (letter == 'A') x--;
            else if (letter == 'D') x++;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_4_4() {
    if (x == 4 && y == 4) {
        if (monsters[3] == 1) {
            playGame();
            monsters[3] = 0;
        }
        if (health == 0) {
            !start;
            cout << "\n�� ���������... ��� ���� ������." << endl;
            cout << "���� ����: " << score << endl;
            cout << "�������� �����: " << kills << endl;
            return;
        }
        cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|???@?|  # - �����\n|?#?##|  ? - ����\n|????#|\n|##???|\n" << endl;
        cout << "���� �����: " << health << endl;
        cout << "���� ����: " << score << endl;
        cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
        cout << "A - �����; D - ������; I - ���������" << endl;
        cout << "�� ������: ";
        cin >> letter;
        cout << endl;

        if (letter == 'A') x--;
        else if (letter == 'D') x++;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'A' && letter != 'D' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "������������ �����������!" << endl;
            }
            cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|???@?|  # - �����\n|?#?##|  ? - ����\n|????#|\n|##???|\n" << endl;
            cout << "���� �����: " << health << endl;
            cout << "���� ����: " << score << endl;
            cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
            cout << "A - �����; D - ������; I - ���������" << endl;
            cout << "�� ������: ";
            cin >> letter;
            cout << endl;

            if (letter == 'A') x--;
            else if (letter == 'D') x++;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_5_4() {
    if (x == 5 && y == 4) {
        cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|????@|  # - �����\n|?#?##|  ? - ����\n|????#|\n|##???|\n" << endl;
        cout << "���� �����: " << health << endl;
        cout << "���� ����: " << score << endl;
        cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
        cout << "W - �����; A - �����; I - ���������" << endl;
        cout << "�� ������: ";
        cin >> letter;
        cout << endl;

        if (letter == 'W') y++;
        else if (letter == 'A') x--;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'W' && letter != 'A' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "������������ �����������!" << endl;
            }
            cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|????@|  # - �����\n|?#?##|  ? - ����\n|????#|\n|##???|\n" << endl;
            cout << "���� �����: " << health << endl;
            cout << "���� ����: " << score << endl;
            cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
            cout << "W - �����; A - �����; I - ���������" << endl;
            cout << "�� ������: ";
            cin >> letter;
            cout << endl;

            if (letter == 'W') y++;
            else if (letter == 'A') x--;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_1_3() {
    if (x == 1 && y == 3) {
        cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|?????|  # - �����\n|@#?##|  ? - ����\n|????#|\n|##???|\n" << endl;
        cout << "���� �����: " << health << endl;
        cout << "���� ����: " << score << endl;
        cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
        cout << "W - �����; S - �����; I - ���������" << endl;
        cout << "�� ������: ";
        cin >> letter;
        cout << endl;

        if (letter == 'W') y++;
        else if (letter == 'S') y--;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'W' && letter != 'S' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "������������ �����������!" << endl;
            }
            cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|?????|  # - �����\n|@#?##|  ? - ����\n|????#|\n|##???|\n" << endl;
            cout << "���� �����: " << health << endl;
            cout << "���� ����: " << score << endl;
            cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
            cout << "W - �����; S - �����; I - ���������" << endl;
            cout << "�� ������: ";
            cin >> letter;
            cout << endl;

            if (letter == 'W') y++;
            else if (letter == 'S') y--;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_3_3() {
    if (x == 3 && y == 3) {
        if (treasure[0] == 1) {
            cout << "�� ����� ������! +1 ����" << endl;
            score++;
            treasure[0] = 0;
        }
        cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|?????|  # - �����\n|?#@##|  ? - ����\n|????#|\n|##???|\n" << endl;
        cout << "���� �����: " << health << endl;
        cout << "���� ����: " << score << endl;
        cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
        cout << "W - �����; S - �����;" << endl;
        cout << "�� ������: ";
        cin >> letter;
        cout << endl;

        if (letter == 'W') y++;
        else if (letter == 'S') y--;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'W' && letter != 'S' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "������������ �����������!" << endl;
            }
            cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|?????|  # - �����\n|?#@##|  ? - ����\n|????#|\n|##???|\n" << endl;
            cout << "���� �����: " << health << endl;
            cout << "���� ����: " << score << endl;
            cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
            cout << "W - �����; S - �����; I - ���������" << endl;
            cout << "�� ������: ";
            cin >> letter;
            cout << endl;

            if (letter == 'W') y++;
            else if (letter == 'S') y--;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_1_2() {
    if (x == 1 && y == 2) {
        if (monsters[1] == 1) {
            playGame();
            monsters[1] = 0;
        }
        if (health == 0) {
            !start;
            cout << "\n�� ���������... ��� ���� ������." << endl;
            cout << "���� ����: " << score << endl;
            cout << "�������� �����: " << kills << endl;
            return;
        }
        cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|?????|  # - �����\n|?#?##|  ? - ����\n|@???#|\n|##???|\n" << endl;
        cout << "���� �����: " << health << endl;
        cout << "���� ����: " << score << endl;
        cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
        cout << "W - �����; D - ������; I - ���������" << endl;
        cout << "�� ������: ";
        cin >> letter;
        cout << endl;

        if (letter == 'W') y++;
        else if (letter == 'D') x++;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'W' && letter != 'D' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "������������ �����������!" << endl;
            }
            cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|?????|  # - �����\n|?#?##|  ? - ����\n|@???#|\n|##???|\n" << endl;
            cout << "���� �����: " << health << endl;
            cout << "���� ����: " << score << endl;
            cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
            cout << "W - �����; D - ������; I - ���������" << endl;
            cout << "�� ������: ";
            cin >> letter;
            cout << endl;

            if (letter == 'W') y++;
            else if (letter == 'D') x++;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_2_2() {
    if (x == 2 && y == 2) {
        cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|?????|  # - �����\n|?#?##|  ? - ����\n|?@??#|\n|##???|\n" << endl;
        cout << "���� �����: " << health << endl;
        cout << "���� ����: " << score << endl;
        cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
        cout << "A - �����; D - ������; I - ���������" << endl;
        cout << "�� ������: ";
        cin >> letter;
        cout << endl;

        if (letter == 'A') x--;
        else if (letter == 'D') x++;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'A' && letter != 'D' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "������������ �����������!" << endl;
            }
            cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|?????|  # - �����\n|?#?##|  ? - ����\n|?@??#|\n|##???|\n" << endl;
            cout << "���� �����: " << health << endl;
            cout << "���� ����: " << score << endl;
            cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
            cout << "A - �����; D - ������; I - ���������" << endl;
            cout << "�� ������: ";
            cin >> letter;
            cout << endl;

            if (letter == 'A') x--;
            else if (letter == 'D') x++;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_4_2() {
    if (x == 4 && y == 2) {
        cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|?????|  # - �����\n|?#?##|  ? - ����\n|???@#|\n|##???|\n" << endl;
        cout << "���� �����: " << health << endl;
        cout << "���� ����: " << score << endl;
        cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
        cout << "S - �����; A - �����; I - ���������" << endl;
        cout << "�� ������: ";
        cin >> letter;
        cout << endl;

        if (letter == 'S') y--;
        else if (letter == 'A') x--;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'S' && letter != 'A' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "������������ �����������!" << endl;
            }
            cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|?????|  # - �����\n|?#?##|  ? - ����\n|???@#|\n|##???|\n" << endl;
            cout << "���� �����: " << health << endl;
            cout << "���� ����: " << score << endl;
            cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
            cout << "S - �����; A - �����; I - ���������" << endl;
            cout << "�� ������: ";
            cin >> letter;
            cout << endl;

            if (letter == 'S') y--;
            else if (letter == 'A') x--;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_3_1() {
    if (x == 3 && y == 1) {
        cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|?????|  # - �����\n|?#?##|  ? - ����\n|????#|\n|##@??|\n" << endl;
        cout << "���� �����: " << health << endl;
        cout << "���� ����: " << score << endl;
        cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
        cout << "W - �����; D - ������; I - ���������" << endl;
        cout << "�� ������: ";
        cin >> letter;
        cout << endl;

        if (letter == 'W') y++;
        else if (letter == 'D') x++;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'W' && letter != 'D' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "������������ �����������!" << endl;
            }
            cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|?????|  # - �����\n|?#?##|  ? - ����\n|????#|\n|##@??|\n" << endl;
            cout << "���� �����: " << health << endl;
            cout << "���� ����: " << score << endl;
            cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
            cout << "W - �����; D - ������; I - ���������" << endl;
            cout << "�� ������: ";
            cin >> letter;
            cout << endl;

            if (letter == 'W') y++;
            else if (letter == 'D') x++;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_4_1() {
    if (x == 4 && y == 1) {
        if (monsters[0] == 1) {
            playGame();
            monsters[0] = 0;
        }
        if (health == 0) {
            !start;
            cout << "\n�� ���������... ��� ���� ������." << endl;
            cout << "���� ����: " << score << endl;
            cout << "�������� �����: " << kills << endl;
            return;
        }
        cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|?????|  # - �����\n|?#?##|  ? - ����\n|????#|\n|##?@?|\n" << endl;
        cout << "���� �����: " << health << endl;
        cout << "���� ����: " << score << endl;
        cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
        cout << "W - �����; A - �����; D - ������; I - ���������" << endl;
        cout << "�� ������: ";
        cin >> letter;
        cout << endl;

        if (letter == 'W') y++;
        else if (letter == 'A') x--;
        else if (letter == 'D') x++;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'W' && letter != 'A' && letter != 'D' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "������������ �����������!" << endl;
            }
            cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|?????|  # - �����\n|?#?##|  ? - ����\n|????#|\n|##?@?|\n" << endl;
            cout << "���� �����: " << health << endl;
            cout << "���� ����: " << score << endl;
            cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
            cout << "W - �����; A - �����; D - ������; I - ���������" << endl;
            cout << "�� ������: ";
            cin >> letter;
            cout << endl;

            if (letter == 'W') y++;
            else if (letter == 'A') x--;
            else if (letter == 'D') x++;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_5_1() {
    if (x == 5 && y == 1) {
        if (treasure[1] == 1) {
            cout << "�� ����� ������! +1 ����" << endl;
            score++;
            treasure[1] = 0;
        }
        cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|?????|  # - �����\n|?#?##|  ? - ����\n|????#|\n|##??@|\n" << endl;
        cout << "���� �����: " << health << endl;
        cout << "���� ����: " << score << endl;
        cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
        cout << "A - �����; I - ���������" << endl;
        cout << "�� ������: ";
        cin >> letter;
        cout << endl;

        if (letter == 'A') x--;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'A' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "������������ �����������!" << endl;
            }
            cout << "\n���� ����� ���������:\n|#?##?|  @ - ��\n|?????|  # - �����\n|?#?##|  ? - ����\n|????#|\n|##??@|\n" << endl;
            cout << "���� �����: " << health << endl;
            cout << "���� ����: " << score << endl;
            cout << "�� ���������� � �������, �� ������� ����� �����:" << endl;
            cout << "A - �����; I - ���������" << endl;
            cout << "�� ������: ";
            cin >> letter;
            cout << endl;

            if (letter == 'A') x--;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/