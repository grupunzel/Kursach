#include "Labs.h"
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

void Laba2() {
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> s, e;
    srand(time(0));
    setlocale(0, "");
    const int n = 100;
    int arr1[n], arr2[n];
    int r, sort, sr, nm, k, max, min;

    cout << "Создан неотсортированный массив из 100 элементов: ";
    for (int i = 0; i < n; i++) {
        arr1[i] = rand() % 199 - 99;
        arr2[i] = arr1[i];
        cout << arr1[i] << " ";
    }
    sort = 0;
    cout << endl << "Для продолжения нажмите enter";
    getchar();
    cout << endl;

    while (true) {

        cout << "          Меню\n" <<
            "1 - создать новый массив\n" <<
            "2 - отсортировать массив\n" <<
            "3 - вывод max и min элемента массива\n" <<
            "4 - вывод среднего значения max и min, кол-ва элементов, равных ему, и их индексы\n" <<
            "5 - вывод кол-ва элементов отсортированного массива, меньше введённого числа\n" <<
            "6 - найти кол-во элементов отсортированного массива, больше введённого числа\n" <<
            "7 - поменять местами элементы массива\n" <<
            "0 - выйти из программы\n";

        cout << "Ваш выбор: ";
        cin >> r;
        cin.sync();
        if (r == 0) break;
        switch (r) {

        case 1:
            cout << "Создаем неотсортированный массив из 100 элементов: ";
            for (int i = 0; i < n; i++) {
                arr1[i] = rand() % 199 - 99;
                arr2[i] = arr1[i];
                cout << arr1[i] << " ";
            }
            sort = 0;
            cout << endl << "Для продолжения нажмите enter";
            getchar();
            cout << endl;
            break;

        case 2:
            nm = n - 1;
            cout << "Получаем отсортированный массив из 100 элементов: ";
            s = steady_clock::now();
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n - 1; k++) {
                    if (arr1[k] > arr1[k + 1]) {
                        int b = arr1[k];
                        arr1[k] = arr1[k + 1];
                        arr1[k + 1] = b;
                    }
                }
            }
            e = steady_clock::now();
            for (int i = 0; i < n; i++) {
                cout << arr1[i] << " ";
            }
            sort = 1;
            cout << endl << "Время сортировки (наносекунды): " << duration_cast<nanoseconds>(e - s).count();
            cout << endl << "Для продолжения нажмите enter";
            getchar();
            cout << endl;
            break;

        case 3:

            s = steady_clock::now();
            max = arr1[n - 1];
            min = arr1[0];
            e = steady_clock::now();
            cout << "Максимальный элемент массива: " << max << endl << "\nМинимальный элемент массива: " << min;
            cout << endl << "Время поиска в отсортированном массиве (наносекунды): " << duration_cast<nanoseconds>(e - s).count();

            s = steady_clock::now();
            for (int i = 0; i < n; i++) {
                if (arr2[i] > max) {
                    max = arr2[i];
                }
                if (arr2[i] < min) {
                    min = arr2[i];
                }
            }
            e = steady_clock::now();
            cout << endl << "Время поиска в неотсортированном массиве (наносекунды): " << duration_cast<nanoseconds>(e - s).count();
            cout << endl << "Для продолжения нажмите enter";
            getchar();
            cout << endl;

            break;

        case 4:
            sr = max + min;
            k = 0;
            if ((sr % 2) != 0) {
                sr += 1;
            }
            sr /= 2;
            cout << "Среднее значение max и min: " << sr << endl << endl;
            cout << "Отсортированный массив" << endl;
            cout << "Индексы равных элементов: ";
            s = steady_clock::now();
            for (int i = 0; i < n; i++) {
                if (arr1[i] == sr) {
                    cout << i << " ";
                    k++;
                }
                if (arr1[i] > sr) {
                    e = steady_clock::now();
                    cout << endl << "Кол-во равных элементов: " << k;
                    cout << endl << "Время поиска (наносекунды): " << duration_cast<nanoseconds>(e - s).count() << endl;
                    break;
                }
            }
            k = 0;
            cout << endl << "Неотсортированный массив" << endl;
            cout << "Индексы равных элементов: ";
            s = steady_clock::now();
            for (int i = 0; i < n; i++) {
                if (arr2[i] == sr) {
                    cout << i << " ";
                    k++;
                }
            }
            e = steady_clock::now();
            cout << endl << "Кол-во равных элементов: " << k;
            cout << endl << "Время поиска (наносекунды): " << duration_cast<nanoseconds>(e - s).count();
            cout << endl << "Для продолжения нажмите enter";
            getchar();
            cout << endl;

            break;

        case 5:
            int a;
            int counter = 0;
            if (sort == 1) {
                cout << "Введите число: ";
                cin >> a;
                for (int i = 0; i < n; i++) {
                    if (arr1[i] < a) {
                        counter++;
                    }
                    else {
                        break;
                    }
                }
                cout << endl << "Чисел меньше " << a << ": " << counter;
                cout << endl << "Для продолжения нажмите enter" << endl;
                getchar();
                cout << endl;
            }
            else {
                cout << "Сначала отсортируйте массив";
                cout << endl << "Для продолжения нажмите enter";
                getchar();
                cout << endl;
            }
            break;

        case 6:
            int b;
            counter = 0;
            if (sort == 1) {
                cout << "Введите число: ";
                cin >> b;
                for (int i = n - 1; i >= 0; i--) {
                    if (arr1[i] > b) {
                        counter++;
                    }
                    else {
                        break;
                    }
                }
                cout << endl << "Чисел больше " << b << ": " << counter;
                cout << endl << "Для продолжения нажмите enter" << endl;
                getchar();
                cout << endl;
            }
            else {
                cout << "Сначала отсортируйте массив";
                cout << endl << "Для продолжения нажмите enter";
                getchar();
                cout << endl;
            }
            break;

        case 7:
            int i, j;
            cout << "Введите индекс 1 элемента: ";
            cin >> i;
            cout << endl << "Введите индекс 2 элемента: ";
            cin >> j;
            s = steady_clock::now();
            swap(arr1[i], arr1[j]);
            e = steady_clock::now();
            cout << endl << "Время замены элементов (наносекунды): " << duration_cast<nanoseconds>(e - s).count() << endl;
            cout << "Получен массив: ";
            for (int k = 0; k < n; k++) {
                cout << arr1[k] << " ";
            }
            cout << endl << "Для продолжения нажмите enter";
            getchar();
            cout << endl << endl;
            break;

        default:
            cout << "Пункт меню выбран неправильно\n";
        }
    }
}
