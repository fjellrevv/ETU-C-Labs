//#include <iostream>
//#include <vector>
//#include <conio.h>
//#include <windows.h>
//#include <locale.h>
//#include <stdlib.h>
//
//using namespace std;
//
//char check(vector <vector <char>>& vec, long x, long i, long j, char z) {
//
//    char g; // символ
//    int cnt = 1;
//    bool win = 0;
//    int x1 = i;
//    int y1 = j;
//
//    // запоминаем символ из начала i строки поля
//
//    g = z;
//
//    // проверка по горизонтали
//    for (int k = 3; k < vec[0].size(); k += 2) {
//        if (vec[i][k] != vec[i][k - 2]) {
//            cnt = 1;
//        }
//        else {
//            if (vec[i][k] == z) cnt++;
//            if (cnt == x) {
//                win = 1;
//                break;
//            }
//        }
//    }
//    cnt = 1;
//
//    // проверка по вертикали
//    for (int k = 3; k < vec.size(); k += 2) {
//        if (vec[k][j] != vec[k - 2][j]) {
//            cnt = 1;
//        }
//        else {
//            if (vec[k][j] == z) cnt++;
//            if (cnt == x) {
//                win = 1;
//                break;
//            }
//        }
//    }
//
//    cnt = 1;
//
//    // проверка по основной диагонали
//    while (i != 1 && j > 1) {
//        j -= 2;
//        i -= 2;
//    }
//    for (int k = i + 2; k < vec.size(); k += 2) {
//        if (j + 2 < vec[0].size()) {
//            j += 2;
//            if (vec[k][j] != vec[k - 2][j - 2]) {
//                cnt = 1;
//            }
//            else {
//                if (vec[k][j] == z) cnt++;
//                if (cnt == x) {
//                    win = 1;
//                    break;
//                }
//            }
//        }
//    }
//
//    i = x1;
//    j = y1;
//
//    // проверка по побочной диагонали
//
//    while (i != 1 && j < vec[0].size() - 2) {
//        j += 2;
//        i -= 2;
//    }
//    for (int k = i + 2; k < vec.size(); k += 2) {
//        if (j - 2 >= 1) {
//            j -= 2;
//            if (vec[k][j] != vec[k - 2][j + 2]) {
//                cnt = 1;
//            }
//            else {
//                if (vec[k][j] == z) cnt++;
//                if (cnt == x) {
//                    win = 1;
//                    break;
//                }
//            }
//        }
//    }
//
//    if (win) return g;
//
//    cnt = 1;
//
//    return ' ';
//}
//
//int main(void) {
//
//    bool step = 0; // ход игрока
//    bool lose = 1;
//    bool lock = 1;
//    bool pol = 1;
//    int key; // код клавиши
//    int cnt = 1;
//    short operation = 1; // пункт меню
//    long n = 2; // длина массива
//    long m = 2; // ширина массива
//    long a = 1, b = 1;
//    long menu = 1; // номер меню
//    long x_cnt = 3, o_cnt = 3;
//    long win = 0;
//
//    vector <vector <char>> field;
//    vector <vector <char>> win_field;
//    field.assign(2 * m + 1, vector<char>(2 * n + 1));
//    win_field.assign(2 * m + 1, vector<char>(2 * n + 1));
//
//    char ans = ' ';
//
//    while (1) {
//
//        system("cls");
//
//        //   for (int i = 0; i < 256; i++) cout << i << char(i) << endl;
//
//        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//        SetConsoleTextAttribute(hConsole, 242);
//       
//        SetConsoleTextAttribute(hConsole, 240);
//
//        if (menu == 1) {
//
//            cout << " Старт ";
//            if (operation == 1) printf("%c", 17);
//            cout << "\n\n Выход ";
//            if (operation == 2) printf("%c", 17);
//
//        }
//
//        if (menu == 2) {
//
//            cout << " Задайте размер поля и количество X и O для выигрыша.\n\n Управляйте клавишами " << char(27)
//                << " и " << char(26) << " для изменения значения: \n\n\n";
//            if (operation == 3) printf(" %c  Длина поля   %c  %d  %c\n\n", 249, 17, (int)n, 16);
//            else printf("    Длина поля   %c  %d  %c\n\n", 17, (int)n, 16);
//
//            if (operation == 4) printf(" %c Ширина поля   %c  %d  %c\n\n", 249, 17, (int)m, 16);
//            else printf("   Ширина поля   %c  %d  %c\n\n", 17, (int)m, 16);
//
//            if (operation == 5) printf("\t   %c X   %c  %d  %c\n\n", 249, 17, (int)x_cnt, 16);
//            else printf("\t     X   %c  %d  %c\n\n", 17, (int)x_cnt, 16);
//
//            if (operation == 6) printf("\t   %c O   %c  %d  %c\n\n", 249, 17, (int)o_cnt, 16);
//            else printf("\t     O   %c  %d  %c\n\n", 17, (int)o_cnt, 16);
//
//
//            cout << "\n\n Начать игру ";
//            if (operation == 7) cout << char(17) << "\n" << endl;
//            else cout << "\n" << endl;
//
//
//            cout << " Назад ";
//            if (operation == 8) cout << char(17) << "\n\n" << endl;
//            cout << "\n\n" << endl;
//
//        }
//
//        if (menu == 3) {
//
//            // построение поля
//            for (int i = 0; i < field.size(); i++) {
//                for (int j = 0; j < field[0].size(); j++) {
//
//                    if (i == 0 && j == 0) field[i][j] = char(218);
//                    if (i == field.size() - 1 && j == field[0].size() - 1) field[i][j] = char(217);
//                    if (i == 0 && j == field[0].size() - 1) field[i][j] = char(191);
//                    if (i == field.size() - 1 && j == 0) field[i][j] = char(192);
//
//                    if (j % 2 == 1 && i % 2 == 0) field[i][j] = char(196);
//                    if (j % 2 == 0 && i % 2 == 1) field[i][j] = char(179);
//
//                    if (j != field[0].size() - 1 && j != 0 && j % 2 == 0 && i == field.size() - 1) field[i][j] = char(193);
//                    if (j != field[0].size() - 1 && j != 0 && j % 2 == 0 && i == 0) field[i][j] = char(194);
//
//                    if (j == 0 && i % 2 == 0 && i != 0 && i != field.size() - 1) field[i][j] = char(195);
//                    if (j == field[0].size() - 1 && i != field.size() - 1 && i % 2 == 0 && i != 0) field[i][j] = char(180);
//
//                    if (i != field.size() - 1 && i != 0 && i % 2 == 0 && j != field[0].size() - 1 && j % 2 == 0 && j != 0) field[i][j] = char(197);
//                }
//            }
//
//            // ход X
//            if (step == 0 && ans != char(88) && ans != char(79)) {
//
//                if (cnt < n * m) cout << " Выберите положение для Х и нажмите Enter:\n" << endl;
//                if (ans != char(88) && ans != char(79)) field[a][b] = char(88); // текущее положение Х
//
//            }
//
//            // ход О
//            else if (step == 1 && ans != char(88) && ans != char(79)) {
//
//                if (cnt < n * m) cout << " Выберите положение для О и нажмите Enter:\n" << endl;
//                field[a][b] = char(79); // текущее положение О
//
//            }
//
//            // выводим поле
//            for (int i = 0; i < field.size(); i++)
//            {
//                cout << ' ';
//
//                for (int j = 0; j < field[0].size(); j++) {
//
//                    if (field[i][j] == char(88)) {
//                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//                        SetConsoleTextAttribute(hConsole, 244);
//                        cout << field[i][j];
//                    }
//                    else if (field[i][j] == char(79)) {
//                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//                        SetConsoleTextAttribute(hConsole, 245);
//                        cout << field[i][j];
//                    }
//                    else {
//                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//                        SetConsoleTextAttribute(hConsole, 240);
//                        cout << field[i][j];
//                    }
//
//                }
//                cout << endl;
//            }
//
//
//            if (ans == char(88) || ans == char(79)) {
//
//                cout << "\n\n Игра окончена!\n\n Итог: ";
//                if (ans == char(88)) cout << "победа Х" << endl;
//                if (ans == char(79)) cout << "победа O" << endl;
//
//                win = 1;
//            }
//            else if (ans == ' ' && cnt == n * m) {
//                cout << "\n\n Игра окончена!\n\n Итог: ничья" << endl;
//            }
//
//            cout << "\n\n 1. К выбору условий (потеря прогресса)\n" << endl;
//
//            cout << " 2. Главное меню\n" << endl;
//
//        }
//
//        key = _getch(); // ввод клавиши
//
//        if (key == 49) { // 1
//
//            if (menu == 3) { // в меню 2 из меню 3
//
//                menu = 2;
//                operation = 3;
//                n = 2;
//                m = 2;
//                a = 1;
//                b = 1;
//                cnt = 1;
//                win = 0;
//                step = 0;
//                ans = ' ';
//
//                field.clear();
//                field.assign(5, vector<char>(5));
//
//                continue;
//
//            }
//
//        }
//
//        if (key == 50) { // 2
//
//            if (menu == 3) { // в меню 1 из меню 3
//
//                menu = 1;
//                operation = 1;
//
//                n = 2;
//                m = 2;
//                a = 1;
//                b = 1;
//                cnt = 1;
//                win = 0;
//                ans = ' ';
//                step = 0;
//
//                field.clear();
//                field.assign(5, vector<char>(5));
//
//                continue;
//
//            }
//
//        }
//
//        if (key == 13) { // Enter
//
//            if (menu != 3) {
//
//                if (operation == 1) { // в меню 2 из меню 1
//
//                    menu = 2;
//                    operation = 3;
//                    continue;
//
//                }
//
//                if (operation == 2) { // выход
//
//                    return 0;
//                    break;
//
//                }
//
//                if (operation == 8) { // в меню 1 из меню 2
//
//                    menu = 1;
//                    operation = 1;
//                    continue;
//
//                }
//
//                if (operation == 7) { // в меню 3 из меню 2
//
//                    menu = 3;
//                    win = 0;
//                    operation = 9;
//                    continue;
//
//                }
//            }
//
//            else {
//
//                if (win) continue;
//
//                if (cnt >= n * m || ans != ' ') continue;
//
//                else if (step == 0 && ans != char(88) && ans != char(79)) {
//
//                    step = 1;
//                    ans = check(field, x_cnt, a, b, char(88));
//                    cnt++;
//
//                }
//                else if (step == 1 && ans != char(88) && ans != char(79)) {
//
//                    step = 0;
//                    ans = check(field, o_cnt, a, b, char(79));
//                    cnt++;
//
//                }
//
//                for (int i = 0; i < field.size(); i++)
//                {
//                    for (int j = 0; j < field[0].size(); j++) {
//                        if (field[i][j] != char(88) && field[i][j] != char(79) && i % 2 == 1 && j % 2 == 1) {
//                            a = i;
//                            b = j;
//                            break; break;
//                        }
//                    }
//                    cout << endl;
//                }
//
//            }
//        }
//
//
//        if (key == 224) { // нажата стрелка
//
//            if (win) continue;
//
//            int inp2 = _getch();
//
//            if (inp2 == 80) { // вниз
//
//                if (menu != 3) operation += 1;
//
//                if (menu == 1) {
//
//                    if (operation == 3) operation = 1;
//
//                }
//
//                if (menu == 2) {
//
//                    if (operation == 9) operation = 3;
//
//                }
//
//                if (menu == 3 && cnt < n * m) {
//
//                    lock = 1;
//
//                    for (int i = a + 2; i < field.size(); i += 2) {
//
//                        if (field[i][b] != char(88) && field[i][b] != char(79)) {
//
//                            field[a][b] = char(32);
//                            a = i;
//                            lock = 0;
//                            break;
//                        }
//                    }
//
//                    if (lock) {
//                        pol = 0;
//
//                        for (int i = a + 2; i < field.size(); i += 2)
//                        {
//                            for (int j = 1; j < field[0].size(); j += 2) {
//
//                                if (pol) continue;
//
//                                if (field[i][j] != char(88) && field[i][j] != char(79)) {
//
//                                    field[a][b] = char(32);
//                                    a = i;
//                                    b = j;
//                                    pol = 1;
//                                    break;
//                                }
//
//                            }
//
//                        }
//
//                    }
//
//                }
//
//                continue;
//            }
//
//            if (inp2 == 75) { // влево
//
//                if (menu == 2) {
//
//                    if (operation == 3) {
//                        if (n - 1 == 1) n = 14;
//                        else n--;
//                    }
//
//                    if (operation == 4) {
//                        if (m - 1 == 1) m = 14;
//                        else m--;
//                    }
//
//                    if (operation == 5) {
//                        if (x_cnt - 1 == 2) x_cnt = 14;
//                        else x_cnt--;
//                    }
//
//                    if (operation == 6 && o_cnt + 1 < 15) {
//                        if (o_cnt - 1 == 2) o_cnt = 14;
//                        else o_cnt--;
//                    }
//
//                    field.assign(2 * m + 1, vector<char>(2 * n + 1));
//                    win_field.assign(2 * m + 1, vector<char>(2 * n + 1));
//                    a = field.size() - 2;
//                    b = 1;
//                    continue;
//                }
//
//                if (menu == 3 && cnt < n * m) {
//
//                    if (a == 1 && b == 1) {
//                        field[a][b] = char(32);
//                        a = field.size() - 2;
//                        b = field[0].size() - 2;
//                    }
//
//                    else {
//                        lock = 1;
//
//                        for (int j = b - 2; j >= 0; j -= 2) {
//
//                            if (field[a][j] != char(88) && field[a][j] != char(79)) {
//
//                                field[a][b] = char(32);
//                                b = j;
//                                lock = 0;
//                                break;
//                            }
//                        }
//
//                        if (lock) {
//                            pol = 0;
//                            for (int i = a - 2; i >= 0; i -= 2)
//                            {
//                                for (int j = field[0].size() - 2; j >= 0; j -= 2) {
//
//                                    if (pol) continue;
//
//                                    if (field[i][j] != char(88) && field[i][j] != char(79)) {
//
//                                        field[a][b] = char(32);
//                                        a = i;
//                                        b = j;
//                                        pol = 1;
//                                        break;
//                                    }
//
//                                }
//
//                            }
//
//                        }
//                    }
//
//                }
//            }
//
//            if (inp2 == 77) { // вправо
//
//                if (menu == 2) {
//
//                    if (operation == 3) {
//
//                        if (n + 1 == 15) n = 2;
//                        else n++;
//
//                    }
//
//                    if (operation == 4) {
//
//                        if (m + 1 == 15) m = 2;
//                        else m++;
//
//                    }
//
//                    if (operation == 5) {
//
//                        if (x_cnt + 1 == 15) x_cnt = 3;
//                        else x_cnt++;
//
//                    }
//
//                    if (operation == 6) {
//
//                        if (o_cnt + 1 == 15) o_cnt = 3;
//                        else o_cnt++;
//
//                    }
//
//                    field.assign(2 * m + 1, vector<char>(2 * n + 1));
//                    win_field.assign(2 * m + 1, vector<char>(2 * n + 1));
//                    a = field.size() - 2;
//                    b = 1;
//                    continue;
//
//                }
//
//                if (menu == 3 && cnt < n * m) {
//
//                    if (a == field.size() - 2 && b == field[0].size() - 2 && field[1][1] != char(88) && field[1][1] != char(79)) {
//
//                        field[a][b] = char(32);
//                        a = 1;
//                        b = 1;
//                    }
//
//                    else {
//
//                        lock = 1;
//
//                        for (int j = b + 2; j < field[0].size(); j += 2) {
//
//                            if (field[a][j] != char(88) && field[a][j] != char(79)) {
//
//                                field[a][b] = char(32);
//                                b = j;
//                                lock = 0;
//                                break;
//                            }
//                        }
//                        if (lock) {
//
//                            pol = 0;
//
//                            for (int i = a + 2; i < field.size(); i += 2)
//                            {
//                                for (int j = 1; j < field[0].size(); j += 2) {
//
//                                    if (pol) continue;
//
//                                    if (field[i][j] != char(88) && field[i][j] != char(79)) {
//
//                                        field[a][b] = char(32);
//                                        a = i;
//                                        b = j;
//                                        pol = 1;
//                                        break;
//                                    }
//
//                                }
//
//                            }
//
//                        }
//                    }
//
//                }
//            }
//
//            if (inp2 == 72) { // вверх
//
//                if (menu != 3) operation -= 1;
//
//                if (menu == 1) {
//
//                    if (operation == 0) operation = 2;
//                }
//
//                if (menu == 2) {
//
//                    if (operation == 2) operation = 8;
//
//                }
//
//                if (menu == 3 && cnt < n * m) {
//
//                    lock = 1;
//
//                    for (int i = a - 2; i >= 0; i -= 2) {
//
//                        if (field[i][b] != char(88) && field[i][b] != char(79)) {
//
//                            field[a][b] = char(32);
//                            a = i;
//                            lock = 0;
//                            break;
//                        }
//                    }
//
//                    if (lock) {
//                        pol = 0;
//                        for (int i = a - 2; i >= 0; i -= 2)
//                        {
//                            for (int j = 1; j < field[0].size(); j += 2) {
//
//                                if (pol) continue;
//
//                                if (field[i][j] != char(88) && field[i][j] != char(79)) {
//
//                                    field[a][b] = char(32);
//                                    a = i;
//                                    b = j;
//                                    pol = 1;
//                                    break;
//                                }
//
//                            }
//
//                        }
//
//                    }
//
//                }
//
//                continue;
//            }
//        }
//
//        // Esc
//
//        if (key == 27) break;
//
//    };
//    return 0;
//}