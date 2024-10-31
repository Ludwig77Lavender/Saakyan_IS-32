#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

extern int health;
extern bool start;
extern int score;
extern int kills;

// ���������
void inventory();

// ���
void playGame();

// ������� X = 2; Y = 5;
void room_2_5();

// ������� X = 5; Y = 5;
void room_5_5();

// ������� X = 1; Y = 4;
void room_1_4();

// ������� X = 2; Y = 4;
void room_2_4();

// ������� X = 3; Y = 4;
void room_3_4();

// ������� X = 4; Y = 4;
void room_4_4();

// ������� X = 5; Y = 4;
void room_5_4();

// ������� X = 1; Y = 3;
void room_1_3();

// ������� X = 3; Y = 3;
void room_3_3();

// ������� X = 1; Y = 2;
void room_1_2();

// ������� X = 2; Y = 2;
void room_2_2();

// ��������� ������� X = 3; Y = 2;
void room1();

// ������� X = 4; Y = 2;
void room_4_2();

// ������� X = 3; Y = 1;
void room_3_1();

// ������� X = 4; Y = 1;
void room_4_1();

// ������� X = 5; Y = 1;
void room_5_1();