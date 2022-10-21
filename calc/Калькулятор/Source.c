#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h> 

int main(void) {

    setlocale(LC_ALL, "Rus");

    int key; 
    short operation = 1; // ����� ����
    long a = 0; 
    long b = 0; 

    short overflow = 0; 
    short error = 0; 

    long long ans = 0; 

    while (1) {

        system("cls");

        printf("A) ����� A: %d (A) ", (int)a);
        if (operation == 1) printf("<---\n");
        else printf("\n");

        printf("B) ����� B: %d (B) ", (int)b);
        if (operation == 2) printf("<---\n\n");
        else printf("\n\n");

        printf("����������� ��������� ��������� ��������:\n\n");

        printf("1. A + B ");
        if (operation == 3) printf("<---\n");
        else printf("\n");

        printf("2. A - B ");
        if (operation == 4) printf("<---\n");
        else printf("\n");

        printf("3. A * B ");
        if (operation == 5) printf("<---\n");
        else printf("\n");

        printf("4. A / B ");
        if (operation == 6) printf("<---\n");
        else printf("\n");

        printf("5. ���������� A � ������� � ");
        if (operation == 7) printf("<---\n");
        else  printf("\n");

        printf("6. ���������� ����� B ������� �� A ");
        if (operation == 8) printf("<---\n");
        else printf("\n");

        printf("7. ������������ ����� A � � ");
        if (operation == 9) printf("<---\n");
        else printf("\n");

        printf("8. ����� �� ��������� (Escape) ");
        if (operation == 10) printf("<---\n");
        else printf("\n");

        if (operation != 1 && operation != 2) 
            printf("\n\n�������� ����� �������� �� 1 �� 8.\n����� �������� �����, ������� � ��� B. \n");

        if (operation == 1) 
            printf("\n������� ����� � ����������.\n\n������� BackSpace, ����� ������� ��������� �����.\n������� ����� �� ���������� ��� ��������� ����� �����.\n\n");

        if (operation == 2) 
            printf("\n������� ����� � ����������.\n\n������� BackSpace, ����� ������� ��������� �����.\n������� ����� �� ���������� ��� ��������� ����� �����.\n\n");

        if (operation == 3) {

            printf("\n%d + %d = \n\n", (int)a, (int)b); 

            if (b != 0 && a / b >= 0) { // ���������� ���� +

                if (a >= 0) {

                    if ((LONG_MAX - a > b)) {

                        ans = a + b;
                        overflow = 0;
                        error = 0;

                    }
                    else {

                        overflow = 1;
                        ans = 0;
                        error = 0;

                    }
                }

                if (a < 0) { // ���������� ���� -

                    if ((LONG_MIN - a < b)) {

                        ans = a + b;
                        overflow = 0;
                        error = 0;

                    }
                    else {

                        overflow = 1;
                        error = 0;
                        ans = 0;

                    }
                }
            }

            else { // ������ ����

                ans = a + b;
                overflow = 0;
                error = 0;

            }
        }

        if (operation == 4) { // ���������

            printf("\n%d - %d = \n\n", (int)a, (int)b);

            if (b != 0 && a / b >= 0) { // ���� ���������� ����

                overflow = 0;
                error = 0;
                ans = a - b;

            }

            else { // ���� ������

                if (a >= 0) {

                    if ((LONG_MAX - a > -1 * b)) {

                        ans = a - b;
                        overflow = 0;
                        error = 0;
                    }

                    else {

                        overflow = 1;
                        ans = 0;
                        error = 0;

                    }
                }
                if (a < 0) {

                    if ((LONG_MIN - a < -1 * b)) {

                        ans = a - b;
                        overflow = 0;
                        error = 0;

                    }

                    else {

                        error = 0;
                        overflow = 1;
                        ans = 0;

                    }
                }
            }
        }

        if (operation == 5) { // ���������

            printf("\n%d * %d = \n\n", (int)a, (int)b);

            long long prom = (long long)a * b;

            if (prom > LONG_MAX || prom < LONG_MIN) { // ��������� ������� �� �������

                overflow = 1;
                ans = 0;

            }

            else {

                ans = a * b;
                error = 0;
                overflow = 0;

            }
        }

        if (operation == 6) { // �������

            printf("\n%d / %d = \n\n", (int)a, (int)b);

            if (b == 0) {

                error = 1;
            }

            else {

                ans = a / b;
                error = 0;
                overflow = 0;

            }
        }

        if (operation == 7) { // �������

            overflow = 0;

            printf("\n%d ^ %d = \n\n", (int)a, (int)b);

            double cnt = pow((double)a, (double)b);

            if (cnt > LONG_MAX || cnt < LONG_MIN) { // ��������� ������� �� �������

                overflow = 1;
                ans = 0;

            }

            else if (b < 0) {

                overflow = 0;
                ans = 0;
                error = 0;

            }

            else {

                ans = (long)round(pow(a, b));
                error = 0;
                overflow = 0;

            }

        }

        if (operation == 8) { // ������

            overflow = 0;

            printf("\n%d ^ (1 / %d) = \n\n", (int)a, (int)b);

                double a1 = a;
                double b1 = b;

                if (b1 <= 0 || (a1 <= 0 && b % 2 == 0 && a < b)) { // ������ ������������� �������

                    overflow = 0;
                    error = 1;

                }

                else if (a1 < 0) { // ����� �� �������� ��������� ������ ������������� 

                    a1 *= -1;
                    ans = pow(a1, (1 / b1));
                    ans *= -1;

                }
                else if (a1 >= 0) {
                    b1 = 1 / b1;
                    ans = pow(a1, b1);

                }
                else {

                    overflow = 0;
                    error = 1;

            }
        }
        if (operation == 9) printf("\n������� Enter ��� ����, ����� �������� ����� A � B �������:\n\n");

        if (operation == 10) printf("\n������� Enter ��� ������ �� ���������: \n\n");

        if (overflow == 1 && operation != 1 && operation != 2 && operation != 9 && operation != 10) printf("��������� ������� �� ������� ���������� ��������!\n");

        else if (error == 1 && operation != 1 && operation != 2 && operation != 9 && operation != 10) printf("���������� ������� ��������\n");

        else if (operation != 1 && operation != 2 && operation != 9 && operation != 10) printf("%d\n", (int)ans);

        key = _getch();
      
        if (key == 8) {   //BackSpace

            if (operation == 1) {
                a = a / 10;
                continue;
            }
            if (operation == 2) {
                b = b / 10;
                continue;
            }
        }

        if (key == 45) { // -

            if (operation == 1) {
                a = -1 * a;
                continue;
            }
            if (operation == 2) {
                b = -1 * b;
                continue;
            }
        }

        if (key == 13) { //Enter

            //������������
            if (operation == 9) {
                long c = a;
                a = b;
                b = c;
                ans = 0;
                overflow = 0;
                operation = 1;
                continue;
            }

            //�����
            if (operation == 10) { 
                printf("\n\n����� �� ���������...\n");
                return 0;
                break; 
            }
        }
        
        // ���� ������ ����� �� 0 �� 9

        if (key >= 48 && key <= 57) {
            long inpnum = key - 48;

            if (operation == 1) {
                if (a >= 0) {
                    if ((LONG_MAX) / 10 > a) a = a * 10 + inpnum;
                    else if (LONG_MAX / 10 == a && inpnum <= 7) a = a * 10 + inpnum;
                }
                else {
                    if ((LONG_MIN) / 10 < a) a = a * 10 - inpnum;
                    else if (LONG_MIN / 10 == a && inpnum <= 8) a = a * 10 - inpnum;
                }
                continue;
            }

            else if (operation == 2) {
                if (b >= 0) {
                    if ((LONG_MAX) / 10 > b) b = b * 10 + inpnum;
                    else if (LONG_MAX / 10 == b && inpnum <= 7) b = b * 10 + inpnum;
                }
                else {
                    if ((LONG_MIN) / 10 < b) b = b * 10 - inpnum;
                    else if (LONG_MIN / 10 == b && inpnum <= 8) b = b * 10 - inpnum;
                }
                continue;
            }

            else if (inpnum != 0) {
                operation = inpnum + 2;
                continue;
            }
        }
        // ������ �������
        if (key == 224) {
            int inp2 = _getch();

            // ������� ����
            if (inp2 == 80) {
                operation += 1;
                if (operation == 11) operation = 1;
                continue;
            }
            // ������� �����
            if (inp2 == 72) {
                operation -= 1;
                if (operation == 0) operation = 10;
                continue;
            }
        }
        // A �� ��������� ����������
        if (key == 97 || key == 65 || key == 228 || key == 148) {
            operation = 1;
            continue;
        }
        // B �� ��������� ����������
        if (key == 98 || key == 66 || key == 136 || key == 168) {
            operation = 2;
            continue;
        }
        // Esc
        if (key == 27) break;
    };
    return 0;
}