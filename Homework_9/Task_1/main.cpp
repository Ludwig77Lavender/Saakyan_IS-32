#include <iostream>
#include "h_1.h"  // Подключаем заголовочный файл

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    const int size = 5;
    // Примерный массив
    int arr[size] = { 10, 20, 5, 30, 15 };

    try {
        int maxElement = findMax(arr, size, compareInt);
        cout << "Максимальный элемент массива: " << maxElement << endl;
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}
