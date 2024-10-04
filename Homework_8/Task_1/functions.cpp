#include "h_1.h"

// Для массива целых чисел
void copyArray(const int* src, int* dest, int size) {
    for (int i = 0; i < size; ++i) {
        dest[i] = src[i];
    }
}

// Для массива чисел с плавающей точкой
void copyArray(const double* src, double* dest, int size) {
    for (int i = 0; i < size; ++i) {
        dest[i] = src[i];
    }
}
