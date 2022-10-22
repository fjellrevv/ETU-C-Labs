#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <stdlib.h>

using namespace std;

int main(void) {

    bool step = 0; 
    bool lose = 1;
    bool lock = 1;
    bool pol = 1;
    int key; 
    int cnt = 1;
    short operation = 1; 
    long n = 3; 
    long m = 3; 
    long a = 1, b = 1;
    long menu = 1; 
    long x_cnt = 3, o_cnt = 3;
    long win = 0;

    char field[12][12];
    char snake_1[100] = { ' ' };
    char snake_2[100] = { ' ' };
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) field[i][j] = ' ';
    }

    char ans = ' ';

    while (1) {

        system("cls");

 //       for (int i = 0; i < 255; i++) cout << char(i) << ' ' << i << endl;

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
        SetConsoleTextAttribute(hConsole, 242);
        cout <<
            " ╔═╗╔╗╔╔═╗╦╔═╔═╗\n"
            " ╚═╗║║║╠═╣╠╩╗║╣\n"
            " ╚═╝╝╚╝╩ ╩╩ ╩╚═╝\n"
             << endl;

        SetConsoleTextAttribute(hConsole, 240); 

        if (menu == 1) { // главное меню

            cout << " Начать ";
            if (operation == 1) printf("%c", 17);
            cout << "\n\n Выход ";
            if (operation == 2) printf("%c", 17);
        }

        if (menu == 2) { // выбор поля

            cout << " Задайте размер поля:\n\n Управляйте клавишами " << char(27)
                << " и " << char(26) << " (A и D) для изменения значения: \n\n\n";
            if (operation == 3) printf("   %c Длина поля   %c  %d  %c\n\n", 249, 17, (int)n, 16);
            else printf("     Длина поля   %c  %d  %c\n\n", 17, (int)n, 16);

            if (operation == 4) printf("  %c Ширина поля   %c  %d  %c\n\n", 249, 17, (int)m, 16);
            else printf("    Ширина поля   %c  %d  %c\n\n", 17, (int)m, 16);

            char field[12][12];
            for (int i = 0; i < 12; i++) {
                for (int j = 0; j < 12; j++) field[i][j] = ' ';
            }

            // рисуем поле
            for (int i = 0; i < n + 2; i++) {
                for (int j = 0; j < m + 2; j++) {

                    if (i == 0 && j == 0) field[i][j] = char(218);
                    if (i == n+1 && j == m+1) field[i][j] = char(217);
                    if (i == 0 && j == m+1) field[i][j] = char(191);
                    if (i == n+1 && j == 0) field[i][j] = char(192);

                    if (j != 0 && j != m+1 && (i == 0 || i==n+1)) field[i][j] = char(196);
                    if ((j == 0 || j == m+1) && i != 0 && i != n+1) field[i][j] = char(179);

                }
            }

            for (int i = 0; i < n+2; i++) // вывод поля
            {

                cout << ' ';

                for (int j = 0; j < m+2; j++) {

                    cout << field[i][j];

                }
                cout << endl;
            }

            cout << "\n\n Продолжить ";
            if (operation == 5) cout << char(17) << "\n" << endl;
            else cout << "\n" << endl;


            cout << " Назад ";
            if (operation == 6) cout << char(17) << "\n\n" << endl;
            cout << "\n\n" << endl;


        }

        if (menu == 3) { // устанавливаем барьеры

            if (cnt <= n * m) {
                    cout << " Установите барьер. " << endl;
                    cout << "\n Используйте стрелки на клавиатуре или клавиши WASD для перемещения. \n\n Для сохранения нажмите Enter:\n\n";
                    if (field[a][b] == ' ') field[a][b] = char(219); 

            }

            for (int i = 0; i < n+2; i++) // вывод поля
            {
                cout << ' ';

                for (int j = 0; j < m+2; j++) {

                        cout << field[i][j];
                    }

                cout << endl;
            }


            cout << "\n\n " << char (249) << " Нажмите 1, чтобы начать игру.\n" << endl;

            cout << ' ' << char(249) << " Нажмите 2, чтобы вернуться к построению поля.\n" << endl;

        }

        if (menu == 4) { // игра

            for (int i = 0; i < n+2; i++) { // вывод поля

                cout << ' ';

                for (int j = 0; j < m+2; j++) {

                    cout << field[i][j];

                }
                cout << endl;
            }
        }

        key = _getch(); // нажали клавишу

        if (key == 49) { // 1

            if (menu == 3) { 

                menu = 4;

                //a = 1;
                //b = 1;
                //cnt = 1;
                //win = 0;
                //step = 0;
                //ans = ' ';
                //continue;

            }

        }

        if (key == 50) { // 2

            if (menu == 3) {

                menu = 2;
                operation = 3;
                for (int i = 0; i < 12; i++) {
                    for (int j = 0; j < 12; j++) field[i][j] = ' ';
                }
                continue;

            }

        }

        if (key == 13) { // Enter

            if (menu != 4 && menu != 3) {

                if (operation == 1) { // из меню 1 в меню 2

                    menu = 2;
                    operation = 3;
                    continue;

                }

                if (operation == 2) { // выход

                    return 0;
                    break;

                }

                if (operation == 5) { // из меню 2 в меню 3

                    menu = 3;
                    a = 1;
                    b = 1;
                    for (int i = 0; i < n + 2; i++) {
                        for (int j = 0; j < m + 2; j++) {

                            if (i == 0 && j == 0) field[i][j] = char(218);
                            if (i == n + 1 && j == m + 1) field[i][j] = char(217);
                            if (i == 0 && j == m + 1) field[i][j] = char(191);
                            if (i == n + 1 && j == 0) field[i][j] = char(192);

                            if (j != 0 && j != m + 1 && (i == 0 || i == n + 1)) field[i][j] = char(196);
                            if ((j == 0 || j == m + 1) && i != 0 && i != n + 1) field[i][j] = char(179);
                            continue;
                        }
                    }

                }

                if (operation == 6) { // из меню 2 в меню 1

                    menu = 1;
                    operation = 1;
                    continue;

                }
            }

            else if (menu == 3) {

                if (cnt >= n * m + 1) continue;

                else {

                    cnt++;

                }
                
                for (int i = 1; i < n+2; i++)
                {
                    for (int j = 1; j < m+1; j++) {
                        if (field[i][j] != char(219)) {
                            a = i;
                            b = j;
                            break; 
                        }
                    }
                    cout << endl;
                }

            }
        }

        if (key == 80 || key == 155 || key == 235 || key == 115) { // вниз

            if (win) continue; 

            if (menu != 3) operation += 1;

            if (menu == 1) {

                if (operation == 3) operation = 1;

            }

            if (menu == 2) {

                if (operation == 7) operation = 3;

            }

            if (menu == 3 && cnt < n * m) {

                lock = 1;

                for (int i = a + 1; i < n + 1; i += 1) { 

                    if (field[i][b] != char(88) && field[i][b] != char(79)) {

                        field[a][b] = char(32);
                        a = i;
                        lock = 0;
                        break;
                    }
                }

                if (lock) {
                    pol = 0;

                    for (int i = a + 1; i < n + 1; i += 1)
                    {
                        for (int j = 1; j < m + 1; j += 1) {

                            if (pol) continue;

                            if (field[i][j] != char(88) && field[i][j] != char(79)) {

                                field[a][b] = char(32);
                                a = i;
                                b = j;
                                pol = 1;
                                break;
                            }

                        }

                    }
                    if (pol == 0) { 
                        for (int i = 1; i < n + 1; i += 1)
                        {
                            for (int j = 1; j < m + 1; j += 1) {

                                if (pol) continue;

                                if (field[i][j] != char(88) && field[i][j] != char(79)) {

                                    field[a][b] = char(32);
                                    a = i;
                                    b = j;
                                    pol = 1;
                                    break;
                                }

                            }

                        }
                    }
                }

            }

            continue;
        }

        if (key == 75 || key == 148 || key == 228 || key == 97) { // влево

            if (win) continue; 

            if (menu == 2) {

                if (operation == 3) {
                    if (n - 1 == 2) n = 10;
                    else n--;
                }

                if (operation == 4) {
                    if (m - 1 == 2) m = 10;
                    else m--;
                }

                a = n-1;
                b = 1;
                
                continue;
            }

            if (menu == 3 && cnt < n * m) {

                lock = 1;

                for (int j = b - 1; j >= 1; j -= 1) { 

                    if (field[a][j] != char(88) && field[a][j] != char(79)) {

                        field[a][b] = char(32);
                        b = j;
                        lock = 0;
                        break;
                    }
                }

                if (lock) { 

                    pol = 0;
                    if (a != 1) {
                        for (int i = a - 1; i >= 1; i -= 1)
                        {
                            for (int j = m; j >= 1; j -= 1) {

                                if (pol) continue;

                                if (field[i][j] != char(88) && field[i][j] != char(79)) {

                                    field[a][b] = char(32);
                                    a = i;
                                    b = j;
                                    pol = 1;
                                    break;
                                }

                            }

                        }
                    }
                    if (pol == 0) {

                        for (int i = n; i >= 1; i -= 1)
                        {
                            for (int j = m; j >= 1; j -= 1) {

                                if (pol) continue;

                                if (field[i][j] != char(88) && field[i][j] != char(79)) {

                                    field[a][b] = char(32);
                                    a = i;
                                    b = j;
                                    pol = 1;
                                    break;
                                }

                            }

                        }
                    }

                }

            }
        }

        if (key == 77 || key == 130 || key == 162 || key == 100) { // вправо

            if (win) continue; 

            if (menu == 2) {

                if (operation == 3) {

                    if (n + 1 == 11) n = 3;
                    else n++;
                    a = n;
                    b = 1;
                    for (int i = 0; i < 12; i++) {
                        for (int j = 0; j < 12; j++) field[i][j] = ' ';
                    }

                }

                if (operation == 4) {

                    if (m + 1 == 11) m = 3;
                    else m++;
                    a = 2 * n - 1;
                    b = 1;
                    for (int i = 0; i < 12; i++) {
                        for (int j = 0; j < 12; j++) field[i][j] = ' ';
                    }
                }

                continue;

            }

            if (menu == 3 && cnt < n * m) {

                lock = 1;

                for (int j = b + 1; j < m+1; j += 1) { 

                    if (field[a][j] != char(88) && field[a][j] != char(79)) {

                        field[a][b] = char(32);
                        b = j;
                        lock = 0;
                        break;
                    }
                }
                if (lock) { 

                    pol = 0;

                    for (int i = a + 1; i < n+1; i += 1) 
                    {
                        for (int j = 1; j < m+1; j += 1) {

                            if (pol) continue;

                            if (field[i][j] != char(88) && field[i][j] != char(79)) {

                                field[a][b] = char(32);
                                a = i;
                                b = j;
                                pol = 1;
                                break;
                            }

                        }

                    }

                    if (pol == 0) {

                        for (int i = 1; i < n+2; i += 1) 
                        {
                            for (int j = 1; j < m+2; j += 1) {

                                if (pol) continue;

                                if (field[i][j] != char(88) && field[i][j] != char(79)) {

                                    field[a][b] = char(32);
                                    a = i;
                                    b = j;
                                    pol = 1;
                                    break;
                                }

                            }

                        }
                    }
                }

            }
        }

        if (key == 72 || key == 150 || key == 230 || key == 119) { // вверх

            if (win) continue; 

            if (menu != 3) operation -= 1;

            if (menu == 1) {

                if (operation == 0) operation = 2;
            }

            if (menu == 2) {

                if (operation == 2) operation = 6;

            }

            if (menu == 3 && cnt < n * m) {

                lock = 1;

                for (int i = a - 1; i >= 0; i -= 1) { 

                    if (field[i][b] != char(88) && field[i][b] != char(79)) {

                        field[a][b] = char(32);
                        a = i;
                        lock = 0;
                        break;
                    }
                }

                if (lock) { 
                    pol = 0;
                    for (int i = a - 1; i >= 0; i -= 1)
                    {
                        for (int j = 1; j < m + 1; j += 1) {

                            if (pol) continue;

                            if (field[i][j] != char(88) && field[i][j] != char(79)) {

                                field[a][b] = char(32);
                                a = i;
                                b = j;
                                pol = 1;
                                break;
                            }

                        }

                    }
                    if (pol == 0) { 
                        for (int i = n; i >= 1; i -= 1) {
                            for (int j = m; j >= 1; j -= 1) {

                                if (pol) continue;

                                if (field[i][j] != char(88) && field[i][j] != char(79)) {

                                    field[a][b] = char(32);
                                    a = i;
                                    b = j;
                                    pol = 1;
                                    break;
                                }

                            }

                        }
                    }

                }

            }

            continue;
        }

        // Esc

        if (key == 27) break;

    };
    return 0;
}