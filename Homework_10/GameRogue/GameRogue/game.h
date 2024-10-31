#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

extern int health;
extern bool start;
extern int score;
extern int kills;

// Инвентарь
void inventory();

// Бой
void playGame();

// Локация X = 2; Y = 5;
void room_2_5();

// Локация X = 5; Y = 5;
void room_5_5();

// Локация X = 1; Y = 4;
void room_1_4();

// Локация X = 2; Y = 4;
void room_2_4();

// Локация X = 3; Y = 4;
void room_3_4();

// Локация X = 4; Y = 4;
void room_4_4();

// Локация X = 5; Y = 4;
void room_5_4();

// Локация X = 1; Y = 3;
void room_1_3();

// Локация X = 3; Y = 3;
void room_3_3();

// Локация X = 1; Y = 2;
void room_1_2();

// Локация X = 2; Y = 2;
void room_2_2();

// Стартовая локация X = 3; Y = 2;
void room1();

// Локация X = 4; Y = 2;
void room_4_2();

// Локация X = 3; Y = 1;
void room_3_1();

// Локация X = 4; Y = 1;
void room_4_1();

// Локация X = 5; Y = 1;
void room_5_1();