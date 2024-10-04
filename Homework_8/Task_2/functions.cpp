#include "h_2.h"

// Реализация функции для целых чисел
bool contains(const int* arr, int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

// Реализация функции для чисел с плавающей точкой
bool contains(const double* arr, int size, double value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}
