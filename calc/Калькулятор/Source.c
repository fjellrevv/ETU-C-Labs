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
    short operation = 1; // пункт меню
    long a = 0; 
    long b = 0; 

    short overflow = 0; 
    short error = 0; 

    long long ans = 0; 

    while (1) {

        system("cls");

        printf("A) Число A: %d (A) ", (int)a);
        if (operation == 1) printf("<---\n");
        else printf("\n");

        printf("B) Число B: %d (B) ", (int)b);
        if (operation == 2) printf("<---\n\n");
        else printf("\n\n");

        printf("Калькулятор выполняет следующие операции:\n\n");

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

        printf("5. Возведение A в степень В ");
        if (operation == 7) printf("<---\n");
        else  printf("\n");

        printf("6. Извлечение корня B степени из A ");
        if (operation == 8) printf("<---\n");
        else printf("\n");

        printf("7. Перестановка чисел A и В ");
        if (operation == 9) printf("<---\n");
        else printf("\n");

        printf("8. Выход из программы (Escape) ");
        if (operation == 10) printf("<---\n");
        else printf("\n");

        if (operation != 1 && operation != 2) 
            printf("\n\nВыберите номер операции от 1 до 8.\nЧтобы заменить число, нажмите А или B. \n");

        if (operation == 1) 
            printf("\nВведите цифры с клавиатуры.\n\nНажмите BackSpace, чтобы стереть последнюю цифру.\nНажмите минус на клавиатуре для изменения знака числа.\n\n");

        if (operation == 2) 
            printf("\nВведите цифры с клавиатуры.\n\nНажмите BackSpace, чтобы стереть последнюю цифру.\nНажмите минус на клавиатуре для изменения знака числа.\n\n");

        if (operation == 3) {

            printf("\n%d + %d = \n\n", (int)a, (int)b); 

            if (b != 0 && a / b >= 0) { // одинаковый знак +

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

                if (a < 0) { // одинаковый знак -

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

            else { // разный знак

                ans = a + b;
                overflow = 0;
                error = 0;

            }
        }

        if (operation == 4) { // вычитание

            printf("\n%d - %d = \n\n", (int)a, (int)b);

            if (b != 0 && a / b >= 0) { // если одинаковый знак

                overflow = 0;
                error = 0;
                ans = a - b;

            }

            else { // если разный

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

        if (operation == 5) { // умножение

            printf("\n%d * %d = \n\n", (int)a, (int)b);

            long long prom = (long long)a * b;

            if (prom > LONG_MAX || prom < LONG_MIN) { // результат выходит за пределы

                overflow = 1;
                ans = 0;

            }

            else {

                ans = a * b;
                error = 0;
                overflow = 0;

            }
        }

        if (operation == 6) { // деление

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

        if (operation == 7) { // степень

            overflow = 0;

            printf("\n%d ^ %d = \n\n", (int)a, (int)b);

            double cnt = pow((double)a, (double)b);

            if (cnt > LONG_MAX || cnt < LONG_MIN) { // результат выходит за пределы

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

        if (operation == 8) { // корень

            overflow = 0;

            printf("\n%d ^ (1 / %d) = \n\n", (int)a, (int)b);

                double a1 = a;
                double b1 = b;

                if (b1 <= 0 || (a1 <= 0 && b % 2 == 0 && a < b)) { // корень отрицательной степени

                    overflow = 0;
                    error = 1;

                }

                else if (a1 < 0) { // число из которого извлекаем корень отрицательное 

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
        if (operation == 9) printf("\nНажмите Enter для того, чтобы поменять числа A и B местами:\n\n");

        if (operation == 10) printf("\nНажмите Enter для выхода из программы: \n\n");

        if (overflow == 1 && operation != 1 && operation != 2 && operation != 9 && operation != 10) printf("Результат выходит за пределы допустимых значений!\n");

        else if (error == 1 && operation != 1 && operation != 2 && operation != 9 && operation != 10) printf("Невозможно сделать действие\n");

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

            //перестановка
            if (operation == 9) {
                long c = a;
                a = b;
                b = c;
                ans = 0;
                overflow = 0;
                operation = 1;
                continue;
            }

            //выход
            if (operation == 10) { 
                printf("\n\nВыход из программы...\n");
                return 0;
                break; 
            }
        }
        
        // если нажаты цифры от 0 до 9

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
        // нажали стрелку
        if (key == 224) {
            int inp2 = _getch();

            // стрелка вниз
            if (inp2 == 80) {
                operation += 1;
                if (operation == 11) operation = 1;
                continue;
            }
            // стрелка вверх
            if (inp2 == 72) {
                operation -= 1;
                if (operation == 0) operation = 10;
                continue;
            }
        }
        // A на различных раскладках
        if (key == 97 || key == 65 || key == 228 || key == 148) {
            operation = 1;
            continue;
        }
        // B на различных раскладках
        if (key == 98 || key == 66 || key == 136 || key == 168) {
            operation = 2;
            continue;
        }
        // Esc
        if (key == 27) break;
    };
    return 0;
}