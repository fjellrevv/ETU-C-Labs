#include <iostream>
#include <vector>
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <stdlib.h>

using namespace std;

long random(long a) {
    return 1 + rand() % 10;
}

int main(void) {

    srand((unsigned)time(NULL));

    bool step = 0;
    bool lose = 1;
    bool snake = 0;
    bool lock = 1;
    bool pol = 1;
    int key;
    int cnt = 0;
    short operation = 1;
    long n = 3;
    long m = 3;
    int food = 0;
    long a = 1, b = 1, c = 1, d = 1;
    int snake_1_cnt = 1;
    int snake_2_cnt = 1;
    long menu = 1;

    char field[12][12];

    int snake_1[100][2] = { ' ' };
    int snake_2[100][2] = { ' ' };

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) field[i][j] = ' ';
    }

    char finish = ' ';

    while (1) {

        system("cls");

        //   for (int i = 0; i < 255; i++) cout << char(i) << ' ' << i << endl;

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 242);
        cout <<
            " �ͻɻ��ͻ����ͻ\n"
            " �ͻ����͹�ʻ��\n"
            " �ͼ�ȼ� �� ��ͼ\n"
            << endl;

        SetConsoleTextAttribute(hConsole, 240);

        if (menu == 1) { // ������� ����

            cout << " ����� ";
            if (operation == 1) printf("%c", 17);
            cout << "\n\n ��室 ";
            if (operation == 2) printf("%c", 17);
        }

        if (menu == 2) { // �롮� ����

            cout << " ������ ࠧ��� ����:\n\n ��ࠢ��� �����蠬� " << char(27)
                << " � " << char(26) << " (A � D) ��� ��������� ���祭��: \n\n\n";
            if (operation == 3) printf("   %c ����� ����   %c  %d  %c\n\n", 249, 17, (int)n, 16);
            else printf("     ����� ����   %c  %d  %c\n\n", 17, (int)n, 16);

            if (operation == 4) printf("  %c ��ਭ� ����   %c  %d  %c\n\n", 249, 17, (int)m, 16);
            else printf("    ��ਭ� ����   %c  %d  %c\n\n", 17, (int)m, 16);

            char field[12][12];
            for (int i = 0; i < 12; i++) {
                for (int j = 0; j < 12; j++) field[i][j] = ' ';
            }

            // ��㥬 ����
            for (int i = 0; i < n + 2; i++) {
                for (int j = 0; j < m + 2; j++) {

                    if (i == 0 && j == 0) field[i][j] = char(218);
                    if (i == n + 1 && j == m + 1) field[i][j] = char(217);
                    if (i == 0 && j == m + 1) field[i][j] = char(191);
                    if (i == n + 1 && j == 0) field[i][j] = char(192);

                    if (j != 0 && j != m + 1 && (i == 0 || i == n + 1)) field[i][j] = char(196);
                    if ((j == 0 || j == m + 1) && i != 0 && i != n + 1) field[i][j] = char(179);

                }
            }

            for (int i = 0; i < n + 2; i++) // �뢮� ����
            {

                cout << ' ';

                for (int j = 0; j < m + 2; j++) {

                    cout << field[i][j];

                }
                cout << endl;
            }

            cout << "\n\n �த������ ";
            if (operation == 5) cout << char(17) << "\n" << endl;
            else cout << "\n" << endl;


            cout << " ����� ";
            if (operation == 6) cout << char(17) << "\n\n" << endl;
            cout << "\n\n" << endl;


        }

        if (menu == 3) { // ��⠭�������� ������

            if (cnt <= n * m - 6) {
                cout << " ��⠭���� ������. " << endl;
                cout << "\n �ᯮ���� ��५�� �� ��������� ��� ������ WASD ��� ��६�饭��. \n\n ��� ��࠭���� ��������� ������ Enter:\n\n";
                if (field[a][b] == ' ') field[a][b] = char(219);

            }
            else {
                cout << " ��⠭������ ���ᨬ��쭮� ������⢮ ����஢!\n\n";
            }

            for (int i = 0; i < n + 2; i++) // �뢮� ����
            {
                cout << ' ';

                for (int j = 0; j < m + 2; j++) {

                    cout << field[i][j];
                }

                cout << endl;
            }


            cout << "\n\n " << char(249) << " ������ 1, �⮡� ����� ����\n" << endl;

            cout << ' ' << char(249) << " ������ 2, �⮡� �������� � ����஥��� ����\n" << endl;

        }

        if (menu == 4) { // ���

            if (finish == ' ') {

                if (step == 0) cout << " ����� ����� ������ (��ப 1)\n";

                else if (step == 1) cout << " ����� 䨮��⮢�� ������ (��ப 2)\n";

                cout << "\n �ᯮ���� ��५�� �� ��������� ��� ������ WASD ��� ��६�饭��:\n\n";
            }
            else {
                cout << " ��� ����祭�!\n\n";
            }

            if (cnt == 0) { // ����

                while (field[a][b] != ' ') {

                   // a = random(a);
                    while ((a = rand()) > 10 - (10 - 5) % 6)
                    { /* bad value retrieved so get next one */
                    }

                    printf("%d,\t%d\n", a, a % 6 + 1);
                    while ((b = rand()) > 10 - (10 - 5) % 6)
                    { /* bad value retrieved so get next one */
                    }

                    printf("%d,\t%d\n", b, b % 6 + 1);
                  //  b = random(b);

                }

                snake_1[0][0] = a;
                snake_1[0][1] = b;

                while (field[a][b] != ' ') {

                    c = random(c);
                    d = random(d);

                }

                snake_2[0][0] = c;
                snake_2[0][1] = d;

                while (food != 4) {

                    while (field[a][b] != ' ') {

                        a = 1 + rand() % n;
                        b = 1 + rand() % m;

                    }

                    field[a][b] = char(3);
                    food++;

                }
            }
            cnt = 1;

            for (int i = 0; i < n + 2; i++) { // �뢮� ����

                cout << ' ';

                for (int j = 0; j < m + 2; j++) {

                    snake = 0;

                    for (int k = 0; k < snake_1_cnt; k++) {
                        if (i == snake_1[k][0] && j == snake_1[k][1]) {
                            SetConsoleTextAttribute(hConsole, 242);
                            cout << char(177);
                            snake = 1;
                            SetConsoleTextAttribute(hConsole, 240);
                            break;
                        }
                    }
                    for (int k = 0; k < snake_2_cnt; k++) {
                        if (i == snake_2[k][0] && j == snake_2[k][1]) {
                            SetConsoleTextAttribute(hConsole, 245);
                            cout << char(178);
                            snake = 1;
                            SetConsoleTextAttribute(hConsole, 240);
                            break;
                        }
                    }

                    if (snake == 0) cout << field[i][j];
                }
                cout << endl;
            }


            cout << snake_1[0][0] << snake_1[0][1] << snake_2[0][0] << snake_2[0][1] << endl;


            cout << "\n ��ப 1: " << snake_1_cnt << "\t ��ப 2: " << snake_2_cnt;

            cout << "\n\n " << char(249) << " ������ 1, �⮡� �������� ����� (����� �ண���)\n" << endl;

            cout << ' ' << char(249) << " ������ 2, �⮡� �������� �� ������� ����\n" << endl;

        }

        key = _getch(); // ������ �������

        if (key == 49) { // 1

            if (menu == 3) {

                field[a][b] = ' ';
                menu = 4;
                operation = 7;
                cnt = 0;
                continue;
            }

            else if (menu == 4) { // �� ���� 4 � ���� 3

                step = 0;
                menu = 3;
                operation = 3;
                for (int i = 1; i < n + 1; i++) {
                    for (int j = 1; j < m + 1; j++) field[i][j] = ' ';
                }
                cnt = 0;
                food = 0;
                snake_1_cnt = 1;
                finish = ' ';
                a = 1;
                b = 1;
                snake_2_cnt = 1;
                continue;

            }

        }

        if (key == 50) { // 2

            if (menu == 3) {

                menu = 2;
                operation = 3;
                cnt = 0;
                for (int i = 0; i < 12; i++) {
                    for (int j = 0; j < 12; j++) field[i][j] = ' ';
                }
                continue;

            }

            if (menu == 4) { // �� ���� 4 � ���� 1

                step = 0;
                menu = 1;
                operation = 1;
                for (int i = 0; i < n + 2; i++) {
                    for (int j = 0; j < m + 2; j++) field[i][j] = ' ';
                }
                cnt = 0;
                n = 3;
                m = 3;
                a = 1;
                b = 1;
                snake_1_cnt = 1;
                snake_2_cnt = 1;
                food = 0;
                finish = ' ';
                continue;

            }
        }

        if (key == 13) { // Enter

            if (menu != 4 && menu != 3) {

                if (operation == 1) { // �� ���� 1 � ���� 2

                    menu = 2;
                    operation = 3;
                    continue;

                }

                if (operation == 2) { // ��室

                    return 0;
                    break;

                }

                if (operation == 5) { // �� ���� 2 � ���� 3

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

                if (operation == 6) { // �� ���� 2 � ���� 1

                    menu = 1;
                    operation = 1;
                    continue;

                }

            }

            if (menu == 3) {

                if (cnt > n * m - 6) continue;

                else {

                    cnt++;

                }

                for (int i = 1; i < n + 1; i++)
                {
                    for (int j = 1; j < m + 1; j++) {

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

        if (key == 80 || key == 155 || key == 235 || key == 115) { // ����

            if (finish == 1) continue;

            if (menu != 3 && menu != 4) operation += 1;

            if (menu == 1) {

                if (operation == 3) operation = 1;

            }

            if (menu == 2) {

                if (operation == 7) operation = 3;

            }

            if (menu == 3 && cnt <= n * m - 6) {

                lock = 1;

                for (int i = a + 1; i < n + 1; i += 1) {

                    if (field[i][b] != char(219)) {

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

                            if (field[i][b] != char(219)) {

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

                                if (field[i][b] != char(219)) {

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

            if (menu == 4) {

                if (step == 0) {

                    int x = snake_1[0][0] + 1;
                    int y = snake_1[0][1];

                    for (int k = 0; k < snake_2_cnt; k++) {

                        if (snake_2[k][0] == x && snake_2[k][1] == y) {

                            finish = 1;
                            continue;

                        }

                    }

                    if (x == n + 1 || field[x][y] == char(219)) {

                        finish = 1;
                        continue;

                    }

                    int cnt = 1;

                    while (cnt < snake_1_cnt) {

                        snake_1[snake_1_cnt - cnt][0] = snake_1[snake_1_cnt - cnt - 1][0];
                        snake_1[snake_1_cnt - cnt][1] = snake_1[snake_1_cnt - cnt - 1][1];

                        cnt++;

                    }

                    snake_1[0][0] = x;
                    snake_1[0][1] = y;

                    step = 1;
                    continue;

                }

                else {

                    int x = snake_2[0][0] + 1;
                    int y = snake_2[0][1];

                    for (int k = 0; k < snake_1_cnt; k++) {

                        if (snake_1[k][0] == x && snake_1[k][1] == y) {

                            finish = 1;
                            continue;

                        }

                    }

                    if (x == n + 1 || field[x][y] == char(219)) {

                        finish = 1;
                        continue;

                    }

                    int cnt = 1;

                    while (cnt < snake_2_cnt) {

                        snake_2[snake_2_cnt - cnt][0] = snake_2[snake_2_cnt - cnt - 1][0];
                        snake_2[snake_2_cnt - cnt][1] = snake_2[snake_2_cnt - cnt - 1][1];

                        cnt++;

                    }

                    snake_2[0][0] = x;
                    snake_2[0][1] = y;

                    step = 0;
                    continue;
                }

                continue;
            }

        }

        if (key == 75 || key == 148 || key == 228 || key == 97) { // �����

            if (finish == 1) continue;

            if (menu == 2) {

                if (operation == 3) {
                    if (n - 1 == 2) n = 10;
                    else n--;
                }

                if (operation == 4) {
                    if (m - 1 == 2) m = 10;
                    else m--;
                }

                a = n - 1;
                b = 1;

                continue;
            }

            if ((menu == 3) && cnt < n * m - 6) {

                lock = 1;

                for (int j = b - 1; j >= 1; j -= 1) {

                    if (field[a][j] != char(219)) {

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

                                if (field[i][b] != char(219)) {

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

                                if (field[i][b] != char(219)) {

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

            if (menu == 4) {

                if (step == 0) {

                    int x = snake_1[0][0];
                    int y = snake_1[0][1] - 1;

                    for (int k = 0; k < snake_2_cnt; k++) {

                        if (snake_2[k][0] == x && snake_2[k][1] == y) {

                            finish = 1;
                            continue;

                        }

                    }

                    if (y == 0 || field[x][y] == char(219)) {

                        finish = 1;
                        continue;

                    }

                    int cnt_snake = 1;

                    while (cnt_snake < snake_1_cnt) {

                        snake_1[snake_1_cnt - cnt_snake][0] = snake_1[snake_1_cnt - cnt_snake - 1][0];
                        snake_1[snake_1_cnt - cnt_snake][1] = snake_1[snake_1_cnt - cnt_snake - 1][1];

                        cnt_snake++;

                    }

                    snake_1[0][0] = x;
                    snake_1[0][1] = y;

                    step = 1;
                    continue;

                }

                else {

                    int x = snake_2[0][0];
                    int y = snake_2[0][1] - 1;

                    for (int k = 0; k < snake_1_cnt; k++) {

                        if (snake_1[k][0] == x && snake_1[k][1] == y) {

                            finish = 1;
                            continue;

                        }

                    }

                    if (y == 0 || field[x][y] == char(219)) {

                        finish = 1;
                        continue;

                    }

                    int cnt = 1;

                    while (cnt < snake_2_cnt) {

                        snake_2[snake_2_cnt - cnt][0] = snake_2[snake_2_cnt - cnt - 1][0];
                        snake_2[snake_2_cnt - cnt][1] = snake_2[snake_2_cnt - cnt - 1][1];

                        cnt++;

                    }

                    snake_2[0][0] = x;
                    snake_2[0][1] = y;

                    step = 0;
                    continue;

                }

                continue;
            }
        }

        if (key == 77 || key == 130 || key == 162 || key == 100) { // ��ࠢ�

            if (finish == 1) continue;

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
                    a = n;
                    b = 1;
                    for (int i = 0; i < 12; i++) {
                        for (int j = 0; j < 12; j++) field[i][j] = ' ';
                    }
                }

                continue;

            }

            if ((menu == 3) && cnt < n * m - 6) {

                lock = 1;

                for (int j = b + 1; j < m + 1; j += 1) {

                    if (field[a][j] != char(219)) {

                        field[a][b] = char(32);
                        b = j;
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

                            if (field[i][b] != char(219)) {

                                field[a][b] = char(32);
                                a = i;
                                b = j;
                                pol = 1;
                                break;
                            }

                        }

                    }

                    if (pol == 0) {

                        for (int i = 1; i < n + 2; i += 1)
                        {
                            for (int j = 1; j < m + 2; j += 1) {

                                if (pol) continue;

                                if (field[i][b] != char(219)) {

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

            if (menu == 4) {

                if (step == 0) {

                    int x = snake_1[0][0];
                    int y = snake_1[0][1] + 1;

                    for (int k = 0; k < snake_2_cnt; k++) {

                        if (snake_2[k][0] == x && snake_2[k][1] == y) {

                            finish = 1;
                            continue;

                        }

                    }

                    if (y == m + 1 || field[x][y] == char(219)) {

                        finish = 1;
                        continue;

                    }

                    int cnt = 1;

                    while (cnt < snake_1_cnt) {

                        snake_1[snake_1_cnt - cnt][0] = snake_1[snake_1_cnt - cnt - 1][0];
                        snake_1[snake_1_cnt - cnt][1] = snake_1[snake_1_cnt - cnt - 1][1];

                        cnt++;

                    }

                    snake_1[0][0] = x;
                    snake_1[0][1] = y;

                    step = 1;
                    continue;

                }

                else {

                    int x = snake_2[0][0];
                    int y = snake_2[0][1] - 1;

                    for (int k = 0; k < snake_1_cnt; k++) {

                        if (snake_1[k][0] == x && snake_1[k][1] == y) {

                            finish = 1;
                            continue;

                        }

                    }

                    if (y == 0 || field[x][y] == char(219)) {

                        finish = 1;
                        continue;

                    }

                    int cnt = 1;

                    while (cnt < snake_2_cnt) {

                        snake_2[snake_2_cnt - cnt][0] = snake_2[snake_2_cnt - cnt - 1][0];
                        snake_2[snake_2_cnt - cnt][1] = snake_2[snake_2_cnt - cnt - 1][1];

                        cnt++;

                    }

                    snake_2[0][0] = x;
                    snake_2[0][1] = y;

                    step = 0;
                    continue;

                }

                continue;
            }
        }

        if (key == 72 || key == 150 || key == 230 || key == 119) { // �����

            if (finish == 1) continue;

            if (menu != 3) operation -= 1;

            if (menu == 1) {

                if (operation == 0) operation = 2;
            }

            if (menu == 2) {

                if (operation == 2) operation = 6;

            }

            if ((menu == 4) && cnt < n * m) {

                lock = 1;

                for (int i = a - 1; i >= 1; i -= 1) {

                    if (field[i][b] != char(219)) {

                        field[a][b] = char(32);
                        a = i;
                        lock = 0;
                        break;
                    }
                }

                if (lock) {
                    pol = 0;
                    for (int i = a - 1; i >= 1; i -= 1)
                    {
                        for (int j = 1; j < m + 1; j += 1) {

                            if (pol) continue;

                            if (field[i][b] != char(219)) {

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

                                if (field[i][b] != char(219)) {

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

            if (menu == 4) {

                if (step == 0) {

                    int x = snake_1[0][0] - 1;
                    int y = snake_1[0][1];

                    for (int k = 0; k < snake_2_cnt; k++) {

                        if (snake_2[k][0] == x && snake_2[k][1] == y) {

                            finish = 1;
                            continue;

                        }

                    }

                    if (x == 0 || field[x][y] == char(219)) {

                        finish = 1;
                        continue;

                    }

                    int cnt = 1;

                    while (cnt < snake_1_cnt) {

                        snake_1[snake_1_cnt - cnt][0] = snake_1[snake_1_cnt - cnt - 1][0];
                        snake_1[snake_1_cnt - cnt][1] = snake_1[snake_1_cnt - cnt - 1][1];

                        cnt++;

                    }

                    snake_1[0][0] = x;
                    snake_1[0][1] = y;

                    step = 1;
                    continue;

                }

                else {

                    int x = snake_2[0][0] - 1;
                    int y = snake_2[0][1];

                    for (int k = 0; k < snake_1_cnt; k++) {

                        if (snake_1[k][0] == x && snake_1[k][1] == y) {

                            finish = 1;
                            continue;

                        }

                    }

                    if (x == 0 || field[x][y] == char(219)) {

                        finish = 1;
                        continue;

                    }

                    int cnt = 1;

                    while (cnt < snake_2_cnt) {

                        snake_2[snake_2_cnt - cnt][0] = snake_2[snake_2_cnt - cnt - 1][0];
                        snake_2[snake_2_cnt - cnt][1] = snake_2[snake_2_cnt - cnt - 1][1];

                        cnt++;

                    }

                    snake_2[0][0] = x;
                    snake_2[0][1] = y;

                    step = 0;
                    continue;

                }
                continue;
            }

            continue;
        }

        // Esc

        if (key == 27) break;

    };
    return 0;
}