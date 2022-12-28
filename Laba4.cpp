#include "Labs.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string text;

void Probel(string txt) {
    for (int i = 0; i < txt.size(); i++) {
        if (txt[i] == ' ' && txt[i + 1] == ' ')
            while (txt[i + 1] == ' ')
                txt.erase((i + 1), 1);
    }
    text = txt;
}

void Znak(string txt) {
    for (int i = 0; i <= txt.size(); i++) {
        if ((txt[i] == '.' || txt[i] == ',' || txt[i] == ';' || txt[i] == ':' || txt[i] == '!' || txt[i] == '?') && (txt[i + 1] == '.' || txt[i + 1] == ',' || txt[i + 1] == ';' || txt[i + 1] == ':' || txt[i + 1] == '!' || txt[i + 1] == '?'))
            if (txt[i] == '.' && txt[i + 1] == '.' && txt[i + 2] == '.' && txt[i + 3] == ' ')
                i += 3;
            else {
                while (txt[i + 1] == '.' || txt[i + 1] == ',' || txt[i + 1] == ';' || txt[i + 1] == ':' || txt[i + 1] == '!' || txt[i + 1] == '?')
                    txt.erase((i + 1), 1);
            }
    }
    text = txt;
}

void Registr(string txt) {
    for (int i = 0; i < txt.size(); i++) {
        if (txt[i] == ' ')
            i += 2;
        txt[i] = tolower(txt[i]);
    }
    text = txt;
}

void sZaglavnoy(string txt) {
    txt[0] = toupper(txt[0]);
    for (int i = 0; i < txt.size(); i++) {
        if (txt[i] == ' ')
            txt[i + 1] = toupper(txt[i + 1]);
    }
    text = txt;
}

void PoiskPodstroki(string txt) {
    string key;
    bool check;
    int count = 0;

    cin >> key;

    for (int i = 0; i < txt.size(); i++) {
        if (txt[i] == key[0]) {
            check = true;
            for (int j = 1; j < key.size(); j++) {
                if (txt[i + j] != key[j]) {
                    check = false;
                }
            }
            if (check == true) {
                count++;
                cout << "Позиция " << i << "\n";
            }
        }
    }
    if (count == 0) {
        cout << "По запросу ничего не найдено";
    }
    else {
        cout << "Всего найдено " << count << " соответствий";
    }
}

void Laba4() {
    setlocale(0, "");

    {
        char input;
    Menu: {
        cout << "Записать текст или прочитать его с файла?\n"
            "1. Записать\n"
            "2. Прочитать с файла\n";
        cin >> input;
        }
    if (input == '1') {
        cin.ignore();
        getline(cin, text);
    }
    else if (input == '2') {
        ifstream in("C:\\Programming\\tekst.txt");
        if (in.is_open()) {
            getline(in, text);
        }
        in.close();
    }
    else {
        system("cls");
        goto Menu;
    }

    cout << "1) Исходная строка: " << text << "\n";
    }

    {
        Probel(text);
        Znak(text);
        Registr(text);

        cout << "2) Отредактированная строка: " << text << "\n";
    }

    {
        cout << "3) Cтрока в обратном порядке: ";
        int a = 0;
        text += " ";

        for (int i = text.length(); i >= 0; i--) {
            if (text[i] == ' ') {
                for (int k = i + 1; k <= (i + a); k++) {
                    cout << text[k];
                }
                a = 0;
            }
            a++;
        }
        for (int i = 0; i < text.length(); i++) {
            if (text[i] == ' ') break;
            cout << text[i];
        }
    }

    {
        sZaglavnoy(text);

        cout << "\n4) Все слова с заглавной буквы: " << text << "\n";
    }

    {
        cout << "5) Введите подстроку, которую вы хотите найти (учтите, что поиск будет совершаться в итоговой строке из прошлого номера)\n";
        PoiskPodstroki(text);
    }

    cout << "\n";
}
