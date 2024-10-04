#ifndef H_1_H
#define H_1_H

// Объявление функции для сравнения целых чисел
bool compareInt(int a, int b);

// Объявление функции для нахождения максимального элемента в массиве
int findMax(int* arr, int size, bool (*compare)(int, int));

#endif
