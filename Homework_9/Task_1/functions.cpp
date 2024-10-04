#include "h_1.h"
#include <stdexcept>

// Реализация функции для сравнения целых чисел
bool compareInt(int a, int b) {
    return a > b;
}

// Реализация функции для нахождения максимального элемента в массиве
int findMax(int* arr, int size, bool (*compare)(int, int)) {
    if (size == 0) {
        throw std::runtime_error("Массив пуст");
    }

    int maxElement = arr[0];

    for (int i = 1; i < size; ++i) {
        if (compare(arr[i], maxElement)) {
            maxElement = arr[i];
        }
    }

    return maxElement;
}

