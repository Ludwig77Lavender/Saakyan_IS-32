#ifndef H_2_H
#define H_2_H

// Объявление функции для проверки на четность
bool isEven(int number);

// Объявление функции для нахождения суммы четных чисел
int sumEven(int* arr, int size, bool (*check)(int));

#endif
