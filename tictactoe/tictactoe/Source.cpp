#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <stdlib.h>

using namespace std;

char check(char vec [14*2+1][14*2+1], long x, long i, long j, char z, int a, int b) { // �㭪�� �஢�ન �먣���

    char g; // ᨬ���
    int cnt = 1;
    bool win = 0;
    int x1 = i;
    int y1 = j;

    // ���������� ᨬ��� �� ��砫� i ��ப� ����

    g = z;

    // �஢�ઠ �� ��ਧ��⠫�
    for (int k = 3; k < 2 * b + 1; k += 2) {
        if (vec[i][k] != vec[i][k - 2]) {
            cnt = 1;
        }
        else {
            if (vec[i][k] == z) cnt++;
            if (cnt == x) {
                win = 1;
                break;
            }
        }
    }

    cnt = 1;

    // �஢�ઠ �� ���⨪���
    for (int k = 3; k < 2*a+1; k += 2) {
        if (vec[k][j] != vec[k - 2][j]) {
            cnt = 1;
        }
        else {
            if (vec[k][j] == z) cnt++;
            if (cnt == x) {
                win = 1;
                break;
            }
        }
    }

    cnt = 1;

    // �஢�ઠ �� �᭮���� ���������
    while (i != 1 && j > 1) {
        j -= 2;
        i -= 2;
    }
    for (int k = i + 2; k < 2*a+1; k += 2) {
        if (j + 2 < 2*b+1) {
            j += 2;
            if (vec[k][j] != vec[k - 2][j - 2]) {
                cnt = 1;
            }
            else {
                if (vec[k][j] == z) cnt++;
                if (cnt == x) {
                    win = 1;
                    break;
                }
            }
        }
    }

    i = x1;
    j = y1;

    cnt = 1;

    // �஢�ઠ �� ����筮� ���������
    while (i != 1 && j < 2*b-1) {
        j += 2;
        i -= 2;
    }
    for (int k = i + 2; k < 2*a+1; k += 2) {
        if (j - 2 >= 1) {
            j -= 2;
            if (vec[k][j] != vec[k - 2][j + 2]) {
                cnt = 1;
            }
            else {
                if (vec[k][j] == z) cnt++;
                if (cnt == x) {
                    win = 1;
                    break;
                }
            }
        }
    }

    if (win) return g;

    cnt = 1;

    return ' ';
}

int main(void) {

    bool step = 0; // 室 ��ப�
    bool lose = 1;
    bool lock = 1;
    bool pol = 1;
    int key; // ��� ������
    int cnt = 1;
    short operation = 1; // �㭪� ����
    long n = 2; // ����� ���ᨢ�
    long m = 2; // �ਭ� ���ᨢ�
    long a = 1, b = 1;
    long menu = 1; // ����� ����
    long x_cnt = 3, o_cnt = 3;
    long win = 0;

    char field[14*2+1][14*2+1];
    for (int i = 0; i < 14*2+1; i++) {
        for (int j = 0; j < 14*2+1; j++) field[i][j] = ' ';
    }

    char ans = ' ';

    while (1) {

        system("cls");

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // �����塞 梥�
        SetConsoleTextAttribute(hConsole, 242);
        cout <<
            " �¿��Ŀ  �¿�Ŀ�Ŀ  �¿�Ŀ�Ŀ\n"
            "  � ��     � �Ĵ�     � � �ô \n"
            "  � ����   � � ����   � ������\n" << endl; // ���������

        SetConsoleTextAttribute(hConsole, 240); // �����頥� 梥�

        if (menu == 1) { // ���⮢�� ����

            cout << " ���� ";
            if (operation == 1) printf("%c", 17);
            cout << "\n\n ��室 ";
            if (operation == 2) printf("%c", 17);
        }

        if (menu == 2) { // �롮� �᫮���

            cout << " ������ ࠧ��� ���� � ������⢮ X � O ��� �먣���.\n\n ��ࠢ��� �����蠬� " << char(27)
                << " � " << char(26) << " (A � D) ��� ��������� ���祭��: \n\n\n";
            if (operation == 3) printf(" %c  ����� ����   %c  %d  %c\n\n", 249, 17, (int)n, 16);
            else printf("    ����� ����   %c  %d  %c\n\n", 17, (int)n, 16);

            if (operation == 4) printf(" %c ��ਭ� ����   %c  %d  %c\n\n", 249, 17, (int)m, 16);
            else printf("   ��ਭ� ����   %c  %d  %c\n\n", 17, (int)m, 16);

            if (operation == 5) printf("\t   %c X   %c  %d  %c\n\n", 249, 17, (int)x_cnt, 16);
            else printf("\t     X   %c  %d  %c\n\n", 17, (int)x_cnt, 16);

            if (operation == 6) printf("\t   %c O   %c  %d  %c\n\n", 249, 17, (int)o_cnt, 16);
            else printf("\t     O   %c  %d  %c\n\n", 17, (int)o_cnt, 16);


            cout << "\n\n ����� ���� ";
            if (operation == 7) cout << char(17) << "\n" << endl;
            else cout << "\n" << endl;


            cout << " ����� ";
            if (operation == 8) cout << char(17) << "\n\n" << endl;
            cout << "\n\n" << endl;


        }

        if (menu == 3) { // ���

           //  ����஥��� ����
            for (int i = 0; i < 2*n+1; i++) {
                for (int j = 0; j < 2*m+1; j++) {

                    if (i == 0 && j == 0) field[i][j] = char(218);
                    if (i == 2 * n && j == 2 * m) field[i][j] = char(217);
                    if (i == 0 && j == 2 * m) field[i][j] = char(191);
                    if (i == 2 * n && j == 0) field[i][j] = char(192);

                    if (j % 2 == 1 && i % 2 == 0) field[i][j] = char(196);
                    if (j % 2 == 0 && i % 2 == 1) field[i][j] = char(179);

                    if (j != 2*m && j != 0 && j % 2 == 0 && i == 2*n) field[i][j] = char(193);
                    if (j != 2*m && j != 0 && j % 2 == 0 && i == 0) field[i][j] = char(194);

                    if (j == 0 && i % 2 == 0 && i != 0 && i != 2*n) field[i][j] = char(195);
                    if (j == 2*m && i != 2*n && i % 2 == 0 && i != 0 && i < 2*n+1 && j < 2*m+1) field[i][j] = char(180);

                    if (i != 2*n && i != 0 && i % 2 == 0 && j != 2*m && j % 2 == 0 && j != 0 && i < 2 * n + 1 && j < 2 * m + 1) field[i][j] = char(197);
                }
            }

            // 室 X
            if (step == 0 && ans != char(88) && ans != char(79)) {

                if (cnt <= n * m) {
                    cout << " �롥�� ��������� ��� � � ������ Enter (��� ������ - ��������� �� " << x_cnt << " ᨬ�����)" << endl;
                    cout << "\n �ᯮ���� ��५�� �� ��������� ��� ������ WASD ��� ��६�饭��:\n\n";
                    if (ans != char(88) && ans != char(79)) field[a][b] = char(88); // ⥪�饥 ��������� �
                }

            }

            // 室 �
            else if (step == 1 && ans != char(88) && ans != char(79)) {

                if (cnt <= n * m) {
                    cout << " �롥�� ��������� ��� � � ������ Enter (��� ������ - ��������� �� " << o_cnt << " ᨬ�����)" << endl;
                    cout << "\n �ᯮ���� ��५�� �� ��������� ��� ������ WASD ��� ��६�饭��:\n\n";
                    field[a][b] = char(79); // ⥪�饥 ��������� �
                }

            }
            // �뢮��� ⥪�饥 ��������� � ��� �
            for (int i = 0; i < 2*n+1; i++)
            {
                cout << ' ';

                for (int j = 0; j < 2*m+1; j++) {

                    if (field[i][j] == char(88)) { // �᫨ 室�� �
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, 244);
                        cout << field[i][j];
                    }
                    else if (field[i][j] == char(79)) { // �᫨ 室�� �

                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, 245);
                        cout << field[i][j];
                    }
                    else {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, 240);
                        cout << field[i][j];
                    }

                }
                cout << endl;
            }

            if (ans == char(88) || ans == char(79)) { // �᫨ ��।��� ������⥫�

                cout << "\n\n ��� ����祭�!\n\n �⮣: ";
                if (ans == char(88)) cout << "������ �" << endl;
                if (ans == char(79)) cout << "������ O" << endl;

                win = 1;
            }
            else if (ans == ' ' && cnt == n * m + 1) { // �᫨ ������⥫� ���
                cout << "\n\n ��� ����祭�!\n\n �⮣: �����" << endl;
            }

            cout << "\n\n 1. � �롮�� �᫮��� (����� �ண���)\n" << endl;

            cout << " 2. ������� ����\n" << endl;

        }

        key = _getch(); // ���� ������

        if (key == 49) { // 1

            if (menu == 3) { // � ���� 2 �� ���� 3

                menu = 2;
                operation = 3;

                a = 1;
                b = 1;
                cnt = 1;
                win = 0;
                step = 0;
                ans = ' ';
                for (int i = 0; i < 14; i++) {
                    for (int j = 0; j < 14; j++) field[i][j] = ' ';
                }
                continue;

            }

        }

        if (key == 50) { // 2

            if (menu == 3) { // � ���� 1 �� ���� 3

                menu = 1;
                operation = 1;

                a = 1;
                b = 1;
                cnt = 1;
                win = 0;
                ans = ' ';
                step = 0;
                for (int i = 0; i < 14; i++) {
                    for (int j = 0; j < 14; j++) field[i][j] = ' ';
                }
                continue;

            }

        }

        if (key == 13) { // Enter

            if (menu != 3) {

                if (operation == 1) { // � ���� 2 �� ���� 1

                    menu = 2;
                    operation = 3;
                    continue;

                }

                if (operation == 2) { // ��室

                    return 0;
                    break;

                }

                if (operation == 8) { // � ���� 1 �� ���� 2

                    menu = 1;
                    operation = 1;
                    continue;

                }

                if (operation == 7) { // � ���� 3 �� ���� 2

                    menu = 3;
                    win = 0;
                    operation = 9;
                    continue;

                }
            }

            else {

                if (win) continue; // �� ॠ���㥬 �᫨ 㦥 �먣ࠫ�

                if (cnt >= n * m + 1 || ans != ' ') continue;

                else if (step == 0 && ans != char(88) && ans != char(79)) {

                    step = 1;
                    ans = check(field, x_cnt, a, b, char(88), n, m);
                    cnt++;

                }
                else if (step == 1 && ans != char(88) && ans != char(79)) {

                    step = 0;
                    ans = check(field, o_cnt, a, b, char(79), n, m);
                    cnt++;

                }

                for (int i = 0; i < n*2+1; i++)
                {
                    for (int j = 0; j < m*2+1; j++) {
                        if (field[i][j] != char(88) && field[i][j] != char(79) && i % 2 == 1 && j % 2 == 1) {
                            a = i;
                            b = j;
                            break; break;
                        }
                    }
                    cout << endl;
                }

            }
        }

        if (key == 80 || key == 155 || key == 235 || key == 115) { // ����

            if (win) continue; // �� ॠ���㥬 �᫨ 㦥 �먣ࠫ�

            if (menu != 3) operation += 1;

            if (menu == 1) {

                if (operation == 3) operation = 1;

            }

            if (menu == 2) {

                if (operation == 9) operation = 3;

            }

            if (menu == 3 && cnt < n * m) {

                lock = 1;

                for (int i = a + 2; i < n*2+1; i += 2) { // �饬 ����� �祩�� ᭨��

                    if (field[i][b] != char(88) && field[i][b] != char(79)) {

                        field[a][b] = char(32);
                        a = i;
                        lock = 0;
                        break;
                    }
                }

                if (lock) { // ���� �⮫��� ᭨�� �����
                    pol = 0;

                    for (int i = a + 2; i < n*2+1; i += 2)
                    {
                        for (int j = 1; j < m*2+1; j += 2) {

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
                    if (pol == 0) { // ��⠫��� ⮫쪮 �祩�� ᢥ���
                        for (int i = 1; i < n*2+1; i += 2)
                        {
                            for (int j = 1; j < m*2+1; j += 2) {

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

            if (win) continue; // �� ॠ���㥬 �᫨ 㦥 �먣ࠫ�

            if (menu == 2) {

                if (operation == 3) {
                    if (n - 1 == 1) n = 14;
                    else n--;
                }

                if (operation == 4) {
                    if (m - 1 == 1) m = 14;
                    else m--;
                }

                if (operation == 5) {
                    if (x_cnt - 1 == 2) x_cnt = 14;
                    else x_cnt--;
                }

                if (operation == 6) {
                    if (o_cnt - 1 == 2) o_cnt = 14;
                    else o_cnt--;
                }

                a = 2*n - 1;
                b = 1;
                for (int i = 0; i < 2 * 14 + 1; i++) {
                    for (int j = 0; j < 2 * 14 + 1; j++) field[i][j] = ' ';
                }
                continue;
            }

            if (menu == 3 && cnt < n * m) {

                lock = 1;

                for (int j = b - 2; j >= 1; j -= 2) { // �饬 ����� ������ ᫥��

                    if (field[a][j] != char(88) && field[a][j] != char(79)) {

                        field[a][b] = char(32);
                        b = j;
                        lock = 0;
                        break;
                    }
                }

                if (lock) { // ᫥�� ��� �����

                    pol = 0;
                    if (a != 1) {
                        for (int i = a - 2; i >= 1; i -= 2) // �饬 �祩�� ᢥ��� �ࠢ� ������
                        {
                            for (int j = 2 * m - 1; j >= 1; j -= 2) {

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
                    if (pol == 0) { // �᫨ �����, ��� � ����

                        for (int i = 2 * n - 1; i >= 1; i -= 2)
                        {
                            for (int j = 2 * m - 1; j >= 1; j -= 2) {

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

            if (win) continue; // �� ॠ���㥬 �᫨ 㦥 �먣ࠫ�

            if (menu == 2) {

                if (operation == 3) {

                    if (n + 1 == 15) n = 2;
                    else n++;

                }

                if (operation == 4) {

                    if (m + 1 == 15) m = 2;
                    else m++;

                }

                if (operation == 5) {

                    if (x_cnt + 1 == 15) x_cnt = 3;
                    else x_cnt++;

                }

                if (operation == 6) {

                    if (o_cnt + 1 == 15) o_cnt = 3;
                    else o_cnt++;

                }

                a = 2*n-1;
                b = 1;
                for (int i = 0; i < 2*14+1; i++) {
                    for (int j = 0; j < 2 * 14 + 1; j++) field[i][j] = ' ';
                }
                continue;

            }

            if (menu == 3 && cnt < n * m) {

                lock = 1;

                for (int j = b + 2; j < 2*m+1; j += 2) { // ᬮ�ਬ ������ �ࠢ�

                    if (field[a][j] != char(88) && field[a][j] != char(79)) {

                        field[a][b] = char(32);
                        b = j;
                        lock = 0;
                        break;
                    }
                }
                if (lock) { // �ࠢ� ��� �����

                    pol = 0;

                    for (int i = a + 2; i < 2*n+1; i += 2) // �饬 �祩�� ᭨�� ᫥�� ���ࠢ�
                    {
                        for (int j = 1; j < 2*m+1; j += 2) {

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

                        for (int i = 1; i < 2 * n + 1; i += 2) // �饬 �祩�� � ��砫�
                        {
                            for (int j = 1; j < 2 * m + 1; j += 2) {

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

            if (win) continue; // �� ॠ���㥬 �᫨ 㦥 �먣ࠫ�

            if (menu != 3) operation -= 1;

            if (menu == 1) {

                if (operation == 0) operation = 2;
            }

            if (menu == 2) {

                if (operation == 2) operation = 8;

            }

            if (menu == 3 && cnt < n * m) {

                lock = 1;

                for (int i = a - 2; i >= 0; i -= 2) { // �饬 ������ �祩�� ᢥ���

                    if (field[i][b] != char(88) && field[i][b] != char(79)) {

                        field[a][b] = char(32);
                        a = i;
                        lock = 0;
                        break;
                    }
                }

                if (lock) { // �᫨ �����, �饬 ������ �祩�� ᫥�� ���ࠢ� ᢥ���
                    pol = 0;
                    for (int i = a - 2; i >= 0; i -= 2)
                    {
                        for (int j = 1; j < 2*m+1; j += 2) {

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
                    if (pol == 0) { // ��⠫��� ⮫쪮 �祩�� ᭨��
                        for (int i = 2*n-1; i >= 1; i -= 2) {
                            for (int j = 2*m-1; j >= 1; j -= 2) {

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