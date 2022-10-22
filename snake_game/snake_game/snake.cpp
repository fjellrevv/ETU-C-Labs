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
                    if (i == n+1 && j == m+1) field[i][j] = char(217);
                    if (i == 0 && j == m+1) field[i][j] = char(191);
                    if (i == n+1 && j == 0) field[i][j] = char(192);

                    if (j != 0 && j != m+1 && (i == 0 || i==n+1)) field[i][j] = char(196);
                    if ((j == 0 || j == m+1) && i != 0 && i != n+1) field[i][j] = char(179);

                }
            }

            for (int i = 0; i < n+2; i++) // �뢮� ����
            {

                cout << ' ';

                for (int j = 0; j < m+2; j++) {

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

            if (cnt <= n * m) {
                    cout << " ��⠭���� �����. " << endl;
                    cout << "\n �ᯮ���� ��५�� �� ��������� ��� ������ WASD ��� ��६�饭��. \n\n ��� ��࠭���� ������ Enter:\n\n";
                    if (field[a][b] == ' ') field[a][b] = char(219); 

            }

            for (int i = 0; i < n+2; i++) // �뢮� ����
            {
                cout << ' ';

                for (int j = 0; j < m+2; j++) {

                        cout << field[i][j];
                    }

                cout << endl;
            }


            cout << "\n\n " << char (249) << " ������ 1, �⮡� ����� ����.\n" << endl;

            cout << ' ' << char(249) << " ������ 2, �⮡� �������� � ����஥��� ����.\n" << endl;

        }

        if (menu == 4) { // ���

            for (int i = 0; i < n+2; i++) { // �뢮� ����

                cout << ' ';

                for (int j = 0; j < m+2; j++) {

                    cout << field[i][j];

                }
                cout << endl;
            }
        }

        key = _getch(); // ������ �������

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

        if (key == 80 || key == 155 || key == 235 || key == 115) { // ����

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

        if (key == 75 || key == 148 || key == 228 || key == 97) { // �����

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

        if (key == 77 || key == 130 || key == 162 || key == 100) { // ��ࠢ�

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

        if (key == 72 || key == 150 || key == 230 || key == 119) { // �����

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