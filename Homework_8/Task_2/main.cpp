#include <iostream>
#include "h_2.h"  // Подключаем заголовочный файл

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    const int sizeInt = 5;
    const int sizeDouble = 5;

    // Пример 1
    int intArray[sizeInt] = { 10, 20, 30, 40, 50 };
    int intValueToFind = 30;

    if (contains(intArray, sizeInt, intValueToFind)) {
        cout << "Элемент " << intValueToFind << " найден в массиве целых чисел." << endl;
    } else {
        cout << "Элемент " << intValueToFind << " не найден в массиве целых чисел." << endl;
    }

    // Пример 2
    double doubleArray[sizeDouble] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    double doubleValueToFind = 4.4;

    if (contains(doubleArray, sizeDouble, doubleValueToFind)) {
        cout << "Элемент " << doubleValueToFind << " найден в массиве чисел с плавающей точкой." << endl;
    } else {
        cout << "Элемент " << doubleValueToFind << " не найден в массиве чисел с плавающей точкой." << endl;
    }

    return 0;
}
