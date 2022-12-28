#include "Labs.h"
using namespace std;

void Laba1() {
    setlocale(0, "");
    cout << "З а д а н и е 1" << endl;
    cout << "Размер переменной типа integer равен " << sizeof(int) << " байта" << endl;
    cout << "Размер переменной типа short int равен " << sizeof(short int) << " байта" << endl;
    cout << "Размер переменной типа long int равен " << sizeof(long int) << " байта" << endl;
    cout << "Размер переменной типа float равен " << sizeof(float) << " байта" << endl;
    cout << "Размер переменной типа double равен " << sizeof(double) << " байт" << endl;
    cout << "Размер переменной типа long double равен " << sizeof(long double) << " байт" << endl;
    cout << "Размер переменной типа char равен " << sizeof(char) << " байт" << endl;
    cout << "Размер переменной типа bool равен " << sizeof(bool) << " байт" << endl;

    cout << "З а д а н и е 2" << endl;
    cout << "Введите число" << endl;
    int chislo1;
    cin >> chislo1;
    unsigned int mask0 = 1 << (sizeof(int) * 8 - 1);

    for (int i = 0; i < sizeof(int) * 8; ++i) {
        if (i % 8 == 0 || i == 1) {
            putchar(' ');
        }
        putchar(chislo1 & mask0 ? '1' : '0');
        chislo1 <<= 1;
    }
    cout << endl << &mask0 << "\n";
    cout << "\n\n\n";

    cout << "З а д а н и е 3" << endl;

    union {
        float chislo2;
        int a;
    };

    unsigned mask1 = 1 << (sizeof(float) * 8 - 1);
    cout << "Введите число типа float" << endl;
    cin >> chislo2;

    for (int j = 0; j < sizeof(float) * 8; ++j) {
        if (j == 1 || j % 8 == 0) {
            putchar(' ');
        }
        putchar(a & mask1 ? '1' : '0');
        a <<= 1;
    }
    cout << "\n" << " | <-Экс-> | <--------Мантиса---------> | " << endl;
    cout << "\n\n\n\n" << endl;


    cout << "З а д а н и е 4" << endl;

    union {
        double chislo3;
        int b[2];
    };

    unsigned int mask2 = 1 << (sizeof(double) * 8 - 1);
    cout << "Введите число типа double" << endl;
    cin >> chislo3;

    for (int k = 0; k < (sizeof(double) * 8) / 2; ++k) {
        if (k == 1 || k % 8 == 0 || k == 12) {
            putchar(' ');
        }
        putchar(b[1] & mask2 ? '1' : '0');
        b[1] <<= 1;
        for (int d = 0; d < (sizeof(double) * 8) / 2; ++d) {
            if (d % 8 == 0) {
                putchar(' ');
            }
            putchar(b[0] & mask2 ? '1' : '0');
            b[0] <<= 1;
        }
    }
}
