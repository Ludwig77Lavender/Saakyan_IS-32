#include <iostream>
#include "h_2.h"  // Подключаем заголовочный файл

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    const int size = 5;
    // Примерный массив
    int arr[size] = { 10, 21, 4, 30, 15 };

    int evenSum = sumEven(arr, size, isEven);
    cout << "Сумма четных чисел в массиве: " << evenSum << endl;

    return 0;
}