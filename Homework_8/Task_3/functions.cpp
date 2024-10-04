#include "h_3.h"

// Реализация функции для изменения размера массива целых чисел
int* resizeArray(int* arr, int oldSize, int newSize) {
    int* newArr = new int[newSize];

    for (int i = 0; i < (oldSize < newSize ? oldSize : newSize); i++) {
        newArr[i] = arr[i];
    }

    for (int i = oldSize; i < newSize; i++) {
        newArr[i] = 0;
    }

    delete[] arr;
    return newArr;
}

// Реализация функции для изменения размера массива вещественных чисел
double* resizeArray(double* arr, int oldSize, int newSize) {
    double* newArr = new double[newSize];

    for (int i = 0; i < (oldSize < newSize ? oldSize : newSize); i++) {
        newArr[i] = arr[i];
    }

    for (int i = oldSize; i < newSize; i++) {
        newArr[i] = 0.0;
    }

    delete[] arr;
    return newArr;
}
