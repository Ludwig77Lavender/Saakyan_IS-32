#include <iostream>
#include "h_1.h"  // Подключаем заголовочный файл с объявлениями функций

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    const int size = 5;

    // Пример 1
    int intArraySrc[size] = { 10, 20, 30, 40, 50 };
    int intArrayDest[size];

    copyArray(intArraySrc, intArrayDest, size);

    cout << "Копия массива целых чисел: ";
    for (int i = 0; i < size; ++i) {
        cout << intArrayDest[i] << " ";
    }
    cout << endl;

    // Пример 2
    double doubleArraySrc[size] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    double doubleArrayDest[size];

    copyArray(doubleArraySrc, doubleArrayDest, size);

    cout << "Копия массива чисел с плавающей точкой: ";
    for (int i = 0; i < size; ++i) {
        cout << doubleArrayDest[i] << " ";
    }
    cout << endl;

    return 0;
}
