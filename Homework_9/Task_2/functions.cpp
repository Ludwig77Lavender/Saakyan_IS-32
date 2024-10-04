#include "h_2.h"

// Реализация функции для проверки на четность
bool isEven(int number) {
    return number % 2 == 0;
}

// Реализация функции для нахождения суммы четных чисел в массиве
int sumEven(int* arr, int size, bool (*check)(int)) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        if (check(arr[i])) {
            sum += arr[i];
        }
    }

    return sum;
}

