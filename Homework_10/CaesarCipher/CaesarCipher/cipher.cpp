#include <string>
#include "cipher.h"

using namespace std;

string encode(const string& text, int shift, int direction) {
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    int alphabet_size = 26;
    string encoded_text = text;

    if (direction == 0) {
        shift = -shift;
    }

    for (int i = 0; i < encoded_text.size(); i++) {
        char c = encoded_text[i];

        // Проверка на заглавную букву
        size_t index = upper_case.find(c);
        if (index != string::npos) {
            int new_index = (index + shift + alphabet_size) % alphabet_size;
            encoded_text[i] = upper_case[new_index];
            continue;
        }

        // Проверка на строчную букву
        index = lower_case.find(c);
        if (index != string::npos) {
            int new_index = (index + shift + alphabet_size) % alphabet_size;
            encoded_text[i] = lower_case[new_index];
        }
    }

    return encoded_text;
}