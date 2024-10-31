#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool start = true;
int health = 3;
int score = 0;

int treasure[3] = { 1, 1, 1 };
int monsters[4] = { 1, 1, 1, 1 };
int kills = 0;
int gameResult = -1;

char invent[3] = { '-', ' ', ' ' };

/* Недоработанная механика альтернативного боя */
//char weapon[2] = { 'S', 'H' };
//int damage = 1;

int x = 3;
int y = 2;
char letter;

void inventory() {
    cout << "=Инвентарь=" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ": " << invent[i] << endl;
    }
}

void playGame() {
    srand(time(0));

    int computerChoice = 1 + rand() % 3;
    char playerChoice;

    cout << "Вы встретили монстра! Сыграйте с ним в игру." << endl;
    cout << "Выберите 1 - камень; 2 - ножницы; 3 - бумага: ";
    cin >> playerChoice;

    while (playerChoice != '1' && playerChoice != '2' && playerChoice != '3') {
        cout << "Неправильное значение!" << endl;
        cout << "Выберите 1 - камень; 2 - ножницы; 3 - бумага: ";
        cin >> playerChoice;
    }

    cout << "Ваш выбор: ";
    switch (playerChoice) {
    case '1': cout << "Камень"; break;
    case '2': cout << "Ножницы"; break;
    case '3': cout << "Бумага"; break;
    }

    cout << "\nВыбор монстра: ";
    switch (computerChoice) {
    case 1: cout << "Камень"; break;
    case 2: cout << "Ножницы"; break;
    case 3: cout << "Бумага"; break;
    }
    cout << endl;

    if (playerChoice == computerChoice) {
        cout << "Ничья! Монстр убежал." << endl;
        gameResult = 2;
    }
    else {
        switch (playerChoice) {
        case '1':
            if (computerChoice == 2) {
                cout << "Вы победили! Камень бьёт ножницы.\nМонстр убит." << endl;
                gameResult = 1;
            }
            else {
                cout << "Вы проиграли! Бумага накрывает камень.\nМонстр убежал." << endl;
                gameResult = 0;
            }
            break;
        case '2':
            if (computerChoice == 3) {
                cout << "Вы победили! Ножницы режут бумагу.\nМонстр убит." << endl;
                gameResult = 1;
            }
            else {
                cout << "Вы проиграли! Камень бьёт ножницы.\nМонстр убежал." << endl;
                gameResult = 0;
            }
            break;
        case '3':
            if (computerChoice == 1) {
                cout << "Вы победили! Бумага накрывает камень.\nМонстр убит." << endl;
                gameResult = 1;
            }
            else {
                cout << "Вы проиграли! Ножницы режут бумагу.\nМонстр убежал." << endl;
                gameResult = 0;
            }
            break;
        }
    }

    if (gameResult == 0) {
        health--;
    }
    else if (gameResult == 1) {
        score += 2;
        kills++;
    }
    else if (gameResult == 2) {
        score++;
    }
}

/*======================================================================================*/
void room1() {
    if (x == 3 && y == 2) {
        cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|?????|  # - Стена\n|?#?##|  ? - Путь\n|??@?#|\n|##???|\n" << endl;
        cout << "Ваши жизни: " << health << endl;
        cout << "Ваши очки: " << score << endl;
        cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
        cout << "W - прямо; S - назад; A - влево; D - вправо; I - инвентарь" << endl;
        cout << "Вы пойдёте: ";
        cin >> letter;
        cout << endl;

        if (letter == 'W') y++;
        else if (letter == 'S') y--;
        else if (letter == 'A') x--;
        else if (letter == 'D') x++;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'W' && letter != 'S' && letter != 'A' && letter != 'D' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "Неправильное направление!" << endl;
            }
            cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|?????|  # - Стена\n|?#?##|  ? - Путь\n|??@?#|\n|##???|\n" << endl;
            cout << "Ваши жизни: " << health << endl;
            cout << "Ваши очки: " << score << endl;
            cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
            cout << "W - прямо; S - назад; A - влево; D - вправо; I - инвентарь" << endl;
            cout << "Вы пойдёте: ";
            cin >> letter;
            cout << endl;

            if (letter == 'W') y++;
            else if (letter == 'S') y--;
            else if (letter == 'A') x--;
            else if (letter == 'D') x++;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_2_5() {
    if (x == 2 && y == 5) {
        if (treasure[2] == 1) {
            cout << "Вы нашли монету! +1 очко" << endl;
            score++;
            treasure[2] = 0;
        }
        if (monsters[2] == 1) {
            playGame();
            monsters[2] = 0;
        }
        if (health == 0) {
            !start;
            cout << "\nВы проиграли... Вас убил монстр." << endl;
            cout << "Ваши очки: " << score << endl;
            cout << "Монстров убито: " << kills << endl;
            return;
        }
        cout << "\nВаша карта местности:\n|#@##?|  @ - Вы\n|?????|  # - Стена\n|?#?##|  ? - Путь\n|????#|\n|##???|\n" << endl;
        cout << "Ваши жизни: " << health << endl;
        cout << "Ваши очки: " << score << endl;
        cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
        cout << "S - назад; I - инвентарь" << endl;
        cout << "Вы пойдёте: ";
        cin >> letter;
        cout << endl;

        if (letter == 'S') y--;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'S' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "Неправильное направление!" << endl;
            }
            cout << "\nВаша карта местности:\n|#@##?|  @ - Вы\n|?????|  # - Стена\n|?#?##|  ? - Путь\n|????#|\n|##???|\n" << endl;
            cout << "Ваши жизни: " << health << endl;
            cout << "Ваши очки: " << score << endl;
            cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
            cout << "S - назад; I - инвентарь" << endl;
            cout << "Вы пойдёте: ";
            cin >> letter;
            cout << endl;

            if (letter == 'S') y--;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_5_5() {
    if (x == 5 && y == 5) {
        cout << "\nВаша карта местности:\n|#?##@|  @ - Вы\n|?????|  # - Стена\n|?#?##|  ? - Путь\n|????#|\n|##???|\n" << endl;
        cout << "Вы нашли сокровище и выбрались из пещеры!" << endl;
        cout << "Ваши остатки жизней: " << health << endl;
        cout << "Ваши итоговые очки: " << score << endl;
        cout << "Всего монстров убито: " << kills << endl;

        start = false;
        letter = '\0';
    }
}
/*======================================================================================*/
void room_1_4() {
    if (x == 1 && y == 4) {
        cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|@????|  # - Стена\n|?#?##|  ? - Путь\n|????#|\n|##???|\n" << endl;
        cout << "Ваши жизни: " << health << endl;
        cout << "Ваши очки: " << score << endl;
        cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
        cout << "S - назад; D - вправо; I - инвентарь" << endl;
        cout << "Вы пойдёте: ";
        cin >> letter;
        cout << endl;

        if (letter == 'S') y--;
        else if (letter == 'D') x++;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'S' && letter != 'D' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "Неправильное направление!" << endl;
            }
            cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|@????|  # - Стена\n|?#?##|  ? - Путь\n|????#|\n|##???|\n" << endl;
            cout << "Ваши жизни: " << health << endl;
            cout << "Ваши очки: " << score << endl;
            cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
            cout << "S - назад; D - вправо; I - инвентарь" << endl;
            cout << "Вы пойдёте: ";
            cin >> letter;
            cout << endl;

            if (letter == 'S') y--;
            else if (letter == 'D') x++;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_2_4() {
    if (x == 2 && y == 4) {
        cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|?@???|  # - Стена\n|?#?##|  ? - Путь\n|????#|\n|##???|\n" << endl;
        cout << "Ваши жизни: " << health << endl;
        cout << "Ваши очки: " << score << endl;
        cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
        cout << "W - прямо; A - влево; D - вправо; I - инвентарь" << endl;
        cout << "Вы пойдёте: ";
        cin >> letter;
        cout << endl;

        if (letter == 'W') y++;
        else if (letter == 'A') x--;
        else if (letter == 'D') x++;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'W' && letter != 'A' && letter != 'D' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "Неправильное направление!" << endl;
            }
            cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|?@???|  # - Стена\n|?#?##|  ? - Путь\n|????#|\n|##???|\n" << endl;
            cout << "Ваши жизни: " << health << endl;
            cout << "Ваши очки: " << score << endl;
            cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
            cout << "W - прямо; A - влево; D - вправо; I - инвентарь" << endl;
            cout << "Вы пойдёте: ";
            cin >> letter;
            cout << endl;

            if (letter == 'W') y++;
            else if (letter == 'A') x--;
            else if (letter == 'D') x++;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_3_4() {
    if (x == 3 && y == 4) {
        cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|??@??|  # - Стена\n|?#?##|  ? - Путь\n|????#|\n|##???|\n" << endl;
        cout << "Ваши жизни: " << health << endl;
        cout << "Ваши очки: " << score << endl;
        cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
        cout << "S - назад; A - влево; D - вправо; I - инвентарь" << endl;
        cout << "Вы пойдёте: ";
        cin >> letter;
        cout << endl;

        if (letter == 'S') y--;
        else if (letter == 'A') x--;
        else if (letter == 'D') x++;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'S' && letter != 'A' && letter != 'D' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "Неправильное направление!" << endl;
            }
            cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|??@??|  # - Стена\n|?#?##|  ? - Путь\n|????#|\n|##???|\n" << endl;
            cout << "Ваши жизни: " << health << endl;
            cout << "Ваши очки: " << score << endl;
            cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
            cout << "S - назад; A - влево; D - вправо; I - инвентарь" << endl;
            cout << "Вы пойдёте: ";
            cin >> letter;
            cout << endl;

            if (letter == 'S') y--;
            else if (letter == 'A') x--;
            else if (letter == 'D') x++;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_4_4() {
    if (x == 4 && y == 4) {
        if (monsters[3] == 1) {
            playGame();
            monsters[3] = 0;
        }
        if (health == 0) {
            !start;
            cout << "\nВы проиграли... Вас убил монстр." << endl;
            cout << "Ваши очки: " << score << endl;
            cout << "Монстров убито: " << kills << endl;
            return;
        }
        cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|???@?|  # - Стена\n|?#?##|  ? - Путь\n|????#|\n|##???|\n" << endl;
        cout << "Ваши жизни: " << health << endl;
        cout << "Ваши очки: " << score << endl;
        cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
        cout << "A - влево; D - вправо; I - инвентарь" << endl;
        cout << "Вы пойдёте: ";
        cin >> letter;
        cout << endl;

        if (letter == 'A') x--;
        else if (letter == 'D') x++;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'A' && letter != 'D' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "Неправильное направление!" << endl;
            }
            cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|???@?|  # - Стена\n|?#?##|  ? - Путь\n|????#|\n|##???|\n" << endl;
            cout << "Ваши жизни: " << health << endl;
            cout << "Ваши очки: " << score << endl;
            cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
            cout << "A - влево; D - вправо; I - инвентарь" << endl;
            cout << "Вы пойдёте: ";
            cin >> letter;
            cout << endl;

            if (letter == 'A') x--;
            else if (letter == 'D') x++;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_5_4() {
    if (x == 5 && y == 4) {
        cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|????@|  # - Стена\n|?#?##|  ? - Путь\n|????#|\n|##???|\n" << endl;
        cout << "Ваши жизни: " << health << endl;
        cout << "Ваши очки: " << score << endl;
        cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
        cout << "W - прямо; A - влево; I - инвентарь" << endl;
        cout << "Вы пойдёте: ";
        cin >> letter;
        cout << endl;

        if (letter == 'W') y++;
        else if (letter == 'A') x--;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'W' && letter != 'A' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "Неправильное направление!" << endl;
            }
            cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|????@|  # - Стена\n|?#?##|  ? - Путь\n|????#|\n|##???|\n" << endl;
            cout << "Ваши жизни: " << health << endl;
            cout << "Ваши очки: " << score << endl;
            cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
            cout << "W - прямо; A - влево; I - инвентарь" << endl;
            cout << "Вы пойдёте: ";
            cin >> letter;
            cout << endl;

            if (letter == 'W') y++;
            else if (letter == 'A') x--;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_1_3() {
    if (x == 1 && y == 3) {
        cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|?????|  # - Стена\n|@#?##|  ? - Путь\n|????#|\n|##???|\n" << endl;
        cout << "Ваши жизни: " << health << endl;
        cout << "Ваши очки: " << score << endl;
        cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
        cout << "W - прямо; S - назад; I - инвентарь" << endl;
        cout << "Вы пойдёте: ";
        cin >> letter;
        cout << endl;

        if (letter == 'W') y++;
        else if (letter == 'S') y--;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'W' && letter != 'S' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "Неправильное направление!" << endl;
            }
            cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|?????|  # - Стена\n|@#?##|  ? - Путь\n|????#|\n|##???|\n" << endl;
            cout << "Ваши жизни: " << health << endl;
            cout << "Ваши очки: " << score << endl;
            cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
            cout << "W - прямо; S - назад; I - инвентарь" << endl;
            cout << "Вы пойдёте: ";
            cin >> letter;
            cout << endl;

            if (letter == 'W') y++;
            else if (letter == 'S') y--;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_3_3() {
    if (x == 3 && y == 3) {
        if (treasure[0] == 1) {
            cout << "Вы нашли монету! +1 очко" << endl;
            score++;
            treasure[0] = 0;
        }
        cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|?????|  # - Стена\n|?#@##|  ? - Путь\n|????#|\n|##???|\n" << endl;
        cout << "Ваши жизни: " << health << endl;
        cout << "Ваши очки: " << score << endl;
        cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
        cout << "W - прямо; S - назад;" << endl;
        cout << "Вы пойдёте: ";
        cin >> letter;
        cout << endl;

        if (letter == 'W') y++;
        else if (letter == 'S') y--;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'W' && letter != 'S' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "Неправильное направление!" << endl;
            }
            cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|?????|  # - Стена\n|?#@##|  ? - Путь\n|????#|\n|##???|\n" << endl;
            cout << "Ваши жизни: " << health << endl;
            cout << "Ваши очки: " << score << endl;
            cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
            cout << "W - прямо; S - назад; I - инвентарь" << endl;
            cout << "Вы пойдёте: ";
            cin >> letter;
            cout << endl;

            if (letter == 'W') y++;
            else if (letter == 'S') y--;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_1_2() {
    if (x == 1 && y == 2) {
        if (monsters[1] == 1) {
            playGame();
            monsters[1] = 0;
        }
        if (health == 0) {
            !start;
            cout << "\nВы проиграли... Вас убил монстр." << endl;
            cout << "Ваши очки: " << score << endl;
            cout << "Монстров убито: " << kills << endl;
            return;
        }
        cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|?????|  # - Стена\n|?#?##|  ? - Путь\n|@???#|\n|##???|\n" << endl;
        cout << "Ваши жизни: " << health << endl;
        cout << "Ваши очки: " << score << endl;
        cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
        cout << "W - прямо; D - вправо; I - инвентарь" << endl;
        cout << "Вы пойдёте: ";
        cin >> letter;
        cout << endl;

        if (letter == 'W') y++;
        else if (letter == 'D') x++;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'W' && letter != 'D' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "Неправильное направление!" << endl;
            }
            cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|?????|  # - Стена\n|?#?##|  ? - Путь\n|@???#|\n|##???|\n" << endl;
            cout << "Ваши жизни: " << health << endl;
            cout << "Ваши очки: " << score << endl;
            cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
            cout << "W - прямо; D - вправо; I - инвентарь" << endl;
            cout << "Вы пойдёте: ";
            cin >> letter;
            cout << endl;

            if (letter == 'W') y++;
            else if (letter == 'D') x++;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_2_2() {
    if (x == 2 && y == 2) {
        cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|?????|  # - Стена\n|?#?##|  ? - Путь\n|?@??#|\n|##???|\n" << endl;
        cout << "Ваши жизни: " << health << endl;
        cout << "Ваши очки: " << score << endl;
        cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
        cout << "A - влево; D - вправо; I - инвентарь" << endl;
        cout << "Вы пойдёте: ";
        cin >> letter;
        cout << endl;

        if (letter == 'A') x--;
        else if (letter == 'D') x++;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'A' && letter != 'D' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "Неправильное направление!" << endl;
            }
            cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|?????|  # - Стена\n|?#?##|  ? - Путь\n|?@??#|\n|##???|\n" << endl;
            cout << "Ваши жизни: " << health << endl;
            cout << "Ваши очки: " << score << endl;
            cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
            cout << "A - влево; D - вправо; I - инвентарь" << endl;
            cout << "Вы пойдёте: ";
            cin >> letter;
            cout << endl;

            if (letter == 'A') x--;
            else if (letter == 'D') x++;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_4_2() {
    if (x == 4 && y == 2) {
        cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|?????|  # - Стена\n|?#?##|  ? - Путь\n|???@#|\n|##???|\n" << endl;
        cout << "Ваши жизни: " << health << endl;
        cout << "Ваши очки: " << score << endl;
        cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
        cout << "S - назад; A - влево; I - инвентарь" << endl;
        cout << "Вы пойдёте: ";
        cin >> letter;
        cout << endl;

        if (letter == 'S') y--;
        else if (letter == 'A') x--;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'S' && letter != 'A' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "Неправильное направление!" << endl;
            }
            cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|?????|  # - Стена\n|?#?##|  ? - Путь\n|???@#|\n|##???|\n" << endl;
            cout << "Ваши жизни: " << health << endl;
            cout << "Ваши очки: " << score << endl;
            cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
            cout << "S - назад; A - влево; I - инвентарь" << endl;
            cout << "Вы пойдёте: ";
            cin >> letter;
            cout << endl;

            if (letter == 'S') y--;
            else if (letter == 'A') x--;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_3_1() {
    if (x == 3 && y == 1) {
        cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|?????|  # - Стена\n|?#?##|  ? - Путь\n|????#|\n|##@??|\n" << endl;
        cout << "Ваши жизни: " << health << endl;
        cout << "Ваши очки: " << score << endl;
        cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
        cout << "W - прямо; D - вправо; I - инвентарь" << endl;
        cout << "Вы пойдёте: ";
        cin >> letter;
        cout << endl;

        if (letter == 'W') y++;
        else if (letter == 'D') x++;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'W' && letter != 'D' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "Неправильное направление!" << endl;
            }
            cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|?????|  # - Стена\n|?#?##|  ? - Путь\n|????#|\n|##@??|\n" << endl;
            cout << "Ваши жизни: " << health << endl;
            cout << "Ваши очки: " << score << endl;
            cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
            cout << "W - прямо; D - вправо; I - инвентарь" << endl;
            cout << "Вы пойдёте: ";
            cin >> letter;
            cout << endl;

            if (letter == 'W') y++;
            else if (letter == 'D') x++;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_4_1() {
    if (x == 4 && y == 1) {
        if (monsters[0] == 1) {
            playGame();
            monsters[0] = 0;
        }
        if (health == 0) {
            !start;
            cout << "\nВы проиграли... Вас убил монстр." << endl;
            cout << "Ваши очки: " << score << endl;
            cout << "Монстров убито: " << kills << endl;
            return;
        }
        cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|?????|  # - Стена\n|?#?##|  ? - Путь\n|????#|\n|##?@?|\n" << endl;
        cout << "Ваши жизни: " << health << endl;
        cout << "Ваши очки: " << score << endl;
        cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
        cout << "W - прямо; A - влево; D - вправо; I - инвентарь" << endl;
        cout << "Вы пойдёте: ";
        cin >> letter;
        cout << endl;

        if (letter == 'W') y++;
        else if (letter == 'A') x--;
        else if (letter == 'D') x++;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'W' && letter != 'A' && letter != 'D' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "Неправильное направление!" << endl;
            }
            cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|?????|  # - Стена\n|?#?##|  ? - Путь\n|????#|\n|##?@?|\n" << endl;
            cout << "Ваши жизни: " << health << endl;
            cout << "Ваши очки: " << score << endl;
            cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
            cout << "W - прямо; A - влево; D - вправо; I - инвентарь" << endl;
            cout << "Вы пойдёте: ";
            cin >> letter;
            cout << endl;

            if (letter == 'W') y++;
            else if (letter == 'A') x--;
            else if (letter == 'D') x++;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/
void room_5_1() {
    if (x == 5 && y == 1) {
        if (treasure[1] == 1) {
            cout << "Вы нашли монету! +1 очко" << endl;
            score++;
            treasure[1] = 0;
        }
        cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|?????|  # - Стена\n|?#?##|  ? - Путь\n|????#|\n|##??@|\n" << endl;
        cout << "Ваши жизни: " << health << endl;
        cout << "Ваши очки: " << score << endl;
        cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
        cout << "A - влево; I - инвентарь" << endl;
        cout << "Вы пойдёте: ";
        cin >> letter;
        cout << endl;

        if (letter == 'A') x--;
        else if (letter == 'I') {
            inventory();
            cout << endl;
        }

        while (letter != 'A' && letter != 'I') {
            if (letter == 'I') {
                inventory();
                cout << endl;
            }
            else {
                cout << "Неправильное направление!" << endl;
            }
            cout << "\nВаша карта местности:\n|#?##?|  @ - Вы\n|?????|  # - Стена\n|?#?##|  ? - Путь\n|????#|\n|##??@|\n" << endl;
            cout << "Ваши жизни: " << health << endl;
            cout << "Ваши очки: " << score << endl;
            cout << "Вы находитесь в комнате, из которой можно пойти:" << endl;
            cout << "A - влево; I - инвентарь" << endl;
            cout << "Вы пойдёте: ";
            cin >> letter;
            cout << endl;

            if (letter == 'A') x--;
            else if (letter == 'I') {
                inventory();
                cout << endl;
            }
        }
        letter = '\0';
    }
}
/*======================================================================================*/