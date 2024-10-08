#include <iostream>
#include "h_3.h"  // Подключаем заголовочный файл

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    const int initialSizeInt = 5;
    const int initialSizeDouble = 5;
    const int newSizeInt = 8;
    const int newSizeDouble = 10;

    // Инициализация массива целых чисел
    int* intArray = new int[initialSizeInt] { 1, 2, 3, 4, 5 };

    intArray = resizeArray(intArray, initialSizeInt, newSizeInt);

    cout << "Массив целых чисел после изменения размера: ";
    for (int i = 0; i < newSizeInt; i++) {
        cout << intArray[i] << " ";
    }
    cout << endl;

    // Инициализация массива вещественных чисел
    double* doubleArray = new double[initialSizeDouble] { 1.1, 2.2, 3.3, 4.4, 5.5 };

    doubleArray = resizeArray(doubleArray, initialSizeDouble, newSizeDouble);

    cout << "Массив вещественных чисел после изменения размера: ";
    for (int i = 0; i < newSizeDouble; i++) {
        cout << doubleArray[i] << " ";
    }
    cout << endl;

    delete[] intArray;
    delete[] doubleArray;

    return 0;
}
