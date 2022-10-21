#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h> 

int main(void) {

    setlocale(LC_ALL, "Rus");

    int key; // номер клавиши
    short operation = 1; // пункт меню
    long a = 0; 
    long b = 0;

    short overflow = 0;

    while (1) {

        system("cls");

        printf("A. Длина массива: %d (A)", (int)a);

        if (operation == 1) printf("<---\n");
        else printf("\n");

        printf("B. Ширина массива: %d (B)", (int)b);

        if (operation == 2) printf("<---\n\n");
        else printf("\n\n");

        printf("Выберите тип заполнения массива:\n\n");

        printf("1. К центру от верхнего левого края ");

        if (operation == 3) printf("<---\n");
        else printf("\n");

        printf("2. К центру от верхнего правого края ");

        if (operation == 4) printf("<---\n");
        else printf("\n");

        printf("3. Из центра к верхнему левому краю ");

        if (operation == 5) printf("<---\n");
        else printf("\n");

        printf("4. Из центра к верхнему правому краю ");

        if (operation == 6) printf("<---\n");
        else printf("\n");

        printf("\n5. Перестановка длины и ширины ");

        if (operation == 7) printf("<---\n");
        else printf("\n");

        printf("\n6. Выход из программы ");

        if (operation == 8) printf("<---\n");
        else  printf("\n");

        if (operation >= 3 && operation <= 8) 
            printf("\n\nВыберите номер операции от 1 до 6.\nЧтобы заменить длину или ширину массива, нажмите А или B соответственно. \n\n");

        if (operation == 1) 
            printf("\nВведите число, не большее 12, с клавиатуры.\nЧтобы стереть последнюю цифру, нажмите BackSpace\n\n");

        if (operation == 2) 
            printf("\nВведите число, не большее 12, с клавиатуры.\nЧтобы стереть последнюю цифру, нажмите BackSpace\n\n");

        if (operation == 3 || operation == 4) { // заполнение начиная от верха

            int mas[12][12] = { 0 };

                int border = 0;
            	int x = 1;
            	int i = 0;
             	int j = 0;
            	while (x <= a * b) {

            	mas[i][j] = x;

           		if (i == border && j < b - border - 1) 
                    j++;

           		else if (j == b - border - 1 && i < a - border - 1) 
                    i++;

            	else if (i == a - border - 1 && j > border) 
                    j--;

            	else i--;

            	if ((i == border + 1) && (j == border) && (border != b - border - 1)) 
                    border++;

            	x++;

        	}
                if (operation == 3) { // вывод с левого края

                    for (int i = 0; i < 12; i++) {

                        for (int j = 0; j < 12; j++) 
                            if (mas[i][j] != 0) printf("%3d ", mas[i][j]);
                        printf("\n");

                    }

                }

                else {

                    for (int i = 0; i < 12; i++) { // вывод с правого края

                        for (int j = 11; j >= 0; j--) 
                            if (mas[i][j] != 0) printf("%3d ", mas[i][j]);
                        printf("\n");
                    }

                }
        }
       
        if (operation == 5 || operation == 6) { // заполнение массива "из центра"

            int mas[12][12] = { 0 };
            int border = 0;
            int x = a * b;
            int i = 0;
            int j = 0;
            while (x >= 1) {

                mas[i][j] = x;

                if (i == border && j < b - border - 1) 
                    j++;

                else if (j == b - border - 1 && i < a - border - 1) 
                    i++;

                else if (i == a - border - 1 && j > border) 
                    j--;

                else i--;

                if ((i == border + 1) && (j == border) && (border != b - border - 1)) 
                    border++;

                x--;
            }
            if (operation == 5) { // вывод из центра к левому краю

                for (int i = 0; i < 12; i++) {

                    for (int j = 0; j < 12; j++) if (mas[i][j] != 0) 
                        printf("%3d ", mas[i][j]);

                    printf("\n");
                }
            }
            else {
                for (int i = 0; i < 12; i++) { // вывод из центра к правому краю

                    for (int j = 11; j >= 0; j--) 
                        if (mas[i][j] != 0) printf("%3d ", mas[i][j]);

                    printf("\n");
                }
            }
        }

        if (operation == 7) printf("\nНажмите Enter для того, чтобы поменять длину и ширину массива местами:\n\n");

        if (operation == 8) printf("\nНажмите Enter для выхода из программы: \n\n");

        if (overflow == 1 && operation != 1 && operation != 2 && operation != 7 && operation != 8) 
            printf("Результат выходит за пределы допустимых значений!\n");

        key = _getch();

        if (key == 8) {   // BackSpace
            if (operation == 1) {
                a = a / 10;
                continue;
            }
            if (operation == 2) {
                b = b / 10;
                continue;
            }
        }

        if (key == 13) { // Enter
            if (operation == 7) {
                long c = a;
                a = b;
                b = c;
                operation = 1;
                continue;
            }
            // выход
            if (operation == 8) {
                printf("\n\nВыход из программы...\n");
                return 0;
                break;
            }
        }

        // нажаты цифры
        if (key >= 48 && key <= 57) {
            long inpnum = key - 48;

            if (operation == 1) {
                if (a * 10 + inpnum <= 12) a = a * 10 + inpnum;
                continue;
            }

            else if (operation == 2) {
                if (b * 10 + inpnum <= 12) b = b * 10 + inpnum;
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

            // стрека вниз
            if (inp2 == 80) {
                operation += 1;
                if (operation == 9) operation = 1;
                continue;
            }
            // стрелка вверх
            if (inp2 == 72) {
                operation -= 1;
                if (operation == 0) operation = 8;
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
    };
    return 0;
}