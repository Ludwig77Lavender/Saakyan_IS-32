#include <iostream>
#include <clocale>
#include "game.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(0));

    cout << "Вы попали в подземелье. Ваша задача: найти сокровища!" << endl;
    
    do {
        // Стартовая локация X = 3; Y = 2;
        room1();

        // Локация X = 2; Y = 5;
        room_2_5();

        // Локация X = 5; Y = 5;
        room_5_5();

        // Локация X = 1; Y = 4;
        room_1_4();

        // Локация X = 2; Y = 4;
        room_2_4();

        // Локация X = 3; Y = 4;
        room_3_4();

        // Локация X = 4; Y = 4;
        room_4_4();

        // Локация X = 5; Y = 4;
        room_5_4();

        // Локация X = 1; Y = 3;
        room_1_3();

        // Локация X = 3; Y = 3;
        room_3_3();

        // Локация X = 1; Y = 2;
        room_1_2();

        // Локация X = 2; Y = 2;
        room_2_2();

        // Локация X = 4; Y = 2;
        room_4_2();

        // Локация X = 3; Y = 1;
        room_3_1();

        // Локация X = 4; Y = 1;
        room_4_1();

        // Локация X = 5; Y = 1;
        room_5_1();

    } while (start && health > 0);

    return 0;
}