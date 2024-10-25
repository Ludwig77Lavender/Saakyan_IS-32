#include <iostream>
#include <string>
#include <clocale>
#include "cipher.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    cout << "Шифр Цезаря 25.10.2024" << endl;
    cout << "Нажмите Enter, чтобы продолжить" << endl;

    while (true) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера перед вводом текста

        string text;
        cout << "Введите текст: ";
        getline(cin, text);

        int direction;
        cout << "В какую сторону будет кодировка символов? (0 влево, 1 вправо): ";
        cin >> direction;

        int shift;
        cout << "На сколько символов: ";
        cin >> shift;

        string encoded_text = encode(text, shift, direction);

        cout << "Закодированный текст: " << encoded_text << endl << endl;
    }

    return 0;
}