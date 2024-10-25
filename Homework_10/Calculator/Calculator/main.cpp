#include <iostream>
#include <limits>
#include "calculate.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    char choice;
    bool keepRunning = true;

    while (keepRunning) {
        cout << "Выберите операцию (+, -, *, /, !, ^) или 'q' для выхода: ";
        cin >> choice;

        if (choice == 'q') {
            keepRunning = false;
            break;
        }

        try {
            int a, b;
            switch (choice) {
            case '+':
                cout << "Введите два числа: ";
                cin >> a >> b;
                cout << "Результат: " << add(a, b) << endl;
                break;
            case '-':
                cout << "Введите два числа: ";
                cin >> a >> b;
                cout << "Результат: " << subtract(a, b) << endl;
                break;
            case '*':
                cout << "Введите два числа: ";
                cin >> a >> b;
                cout << "Результат: " << multiply(a, b) << endl;
                break;
            case '/':
                cout << "Введите два числа: ";
                cin >> a >> b;
                cout << "Результат: " << divide(a, b) << endl;
                break;
            case '!':
                cout << "Введите число: ";
                cin >> a;
                cout << "Результат: " << factorial(a) << endl;
                break;
            case '^':
                cout << "Введите основание и показатель степени: ";
                cin >> a >> b;
                cout << "Результат: " << power(a, b) << endl;
                break;
            default:
                cout << "Ошибка: неверная операция." << endl;
                break;
            }
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }

        cout << endl;
    }

    cout << "Программа завершена." << endl;

    return 0;
}