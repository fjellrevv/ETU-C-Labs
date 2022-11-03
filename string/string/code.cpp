#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h> 
using namespace std;

long str_len(char str[]) {

    int cnt = 0;

    while (str[cnt] != '\0') {
        cnt++;
    }

    return cnt;

}

long str_clr(char str[]) {

    for (int i = 0; i < 20; i++) str[i] = '\0';

    return 1;

}

long str_copy(char str1[], char str2[]) {

    int i = 0;

    str_clr(str1);
    while (str2[i] != '\0') {
        str1[i] = str2[i];
        i++;
    }

    return 1;

}

long str_cat(char str1[], char str2[], long cnt) {

    int i = 0;
    cnt++;

    while (cnt < 20 && str2[i] != '\0') {
        str1[cnt] = str2[i];
        str1[cnt + 1] = '\0';
        cnt++;
        i++;
    }

    return 1;

}

long str_n_cat(char str1[], char str2[], long cnt, long N) {

    int i = 0;
    cnt++;
    int n = 0;

    while (cnt < 20 && str2[i] != '\0' && n < N) {
        str1[cnt] = str2[i];
        str1[cnt + 1] = '\0';
        cnt++;
        i++;
        n++;
    }

    return 1;

}

long str_reverse(char str[], long cnt) {

    int i = 0;
    int cnt_rev = cnt; 

    char mas[21] = "\0";
    str_copy(mas, str);

    i = 0;
    while (str[i] != '\0' || cnt_rev > -1) {
        str[i] = mas[cnt_rev];
        cnt_rev--;
        i++;
    }
    return 1;

}

long str_lower_case(char str[]) {

    int i = 0;

    while (str[i] != '\0') {
        if (str[i] <= char(90) && str[i] >= char(65)) str[i] = str[i] + 32;
        i++;
    }

    return 1;

}

long str_upper_case(char str[]) {

    int i = 0;

    while (str[i] != '\0') {
        if (str[i] <= char(122) && str[i] >= char(97)) str[i] = str[i] - 32;
        i++;
    }

    return 1;

}

int main(void) {

    setlocale(LC_ALL, "Russian");

    int key; // номер клавиши
    char sym = '0'; // символ
    short operation = 1; // пункт меню
    char str_1[21] = { "\0" };
    char str_2[21] = { "\0" };
    long str_1_cnt = -1;
    long str_2_cnt = -1;
    long end_sym = 0;
    long flag = 0;
    long N = 0;
    long* num;

    while (1) {

        system("cls");
            
    //   for (int i = 0; i <= 255; i++) cout << char(i) << i << endl;

        for (int i = 0; i <= 35; i++) cout << char(45);
        cout << endl;

        cout << " Строка 1: " << str_1 << ' ';

        if (operation == 1) cout << char(17) << endl;
        else printf("\n");

        cout << "\n Строка 2: " << str_2 << ' ';

        if (operation == 2) cout << char(17) << endl;
        else printf("\n");

        for (int i = 0; i <= 35; i++) cout << char(45);
        cout << endl;



        printf("\n 1. Длины строк ");

        if (operation == 3) cout << char(17) << endl;
        else printf("\n");

        printf("\n 2. Объединить строки ");

        if (operation == 4) cout << char(17) << endl;
        else printf("\n");

        printf("\n 3. Копировать одну строку в другую ");

        if (operation == 5) cout << char(17) << endl;
        else printf("\n");

        printf("\n 4. Инвертировать порядок символов в строке ");

        if (operation == 6) cout << char(17) << endl;
        else printf("\n");

        printf("\n 5. Преобразовать строку в верхний регистр ");

        if (operation == 7) cout << char(17) << endl;
        else printf("\n");

        printf("\n 6. Преобразовать строку в нижний регистр ");

        if (operation == 8) cout << char(17) << endl;
        else printf("\n");

        printf("\n 7. Добавить N символов одной строки к другой ");

        if (operation == 9) cout << char(17) << endl;
        else printf("\n");

        printf("\n 8. Очистить строку ");

        if (operation == 10) cout << char(17) << endl;
        else printf("\n");

        printf("\n 9. Выход из программы ");

        if (operation == 11) cout << char(17) << "\n\n";
        else  printf("\n\n");

        for (int i = 0; i <= 70; i++) cout << char(45);
        cout << endl;

        if (operation == 1)
            printf("\n Введите символы с клавиатуры.\n\n Чтобы стереть последний символ, нажмите BackSpace.\n\n");


        if (operation == 2)
            printf("\n Введите символы с клавиатуры.\n\n Чтобы стереть последний символ, нажмите BackSpace.\n\n");


        if (operation == 3) { 

            cout << "\n Длина строки 1: " << str_len(str_1) << "\n\n";
            cout << " Длина строки 2: " << str_len(str_2) << "\n\n";

        }

        if (operation == 4) {

            printf("\n Нажмите 1, чтобы сохранить результат объединения в строку 1. \n");
            printf("\n Нажмите 2, чтобы сохранить результат объединения в строку 2. \n\n");

        }

        if (operation == 5) {

            printf("\n Нажмите 1, чтобы скопировать строку 1 в строку 2. \n");
            printf("\n Нажмите 2, чтобы скопировать строку 2 в строку 1. \n\n");

        }

        if (operation == 6) {

            printf("\n Нажмите 1, чтобы инвертировать строку 1. \n");
            printf("\n Нажмите 2, чтобы инвертировать строку 2. \n");
            printf("\n Нажмите 3, чтобы инвертировать обе строки. \n\n");

        }

        if (operation == 7) {

            printf("\n Нажмите 1, чтобы преобразовать строку 1. \n");
            printf("\n Нажмите 2, чтобы преобразовать строку 2. \n");
            printf("\n Нажмите 3, чтобы преобразовать обе строки. \n\n");

        }

        if (operation == 8) {

            printf("\n Нажмите 1, чтобы преобразовать строку 1. \n");
            printf("\n Нажмите 2, чтобы преобразовать строку 2. \n");
            printf("\n Нажмите 3, чтобы преобразовать обе строки. \n\n");

        }

        if (operation == 9) {

            if (flag == 0) {
                printf("\n Нажмите 1, чтобы взять символы из строки 1 и поместить в строку 2. \n");
                printf("\n Нажмите 2, чтобы взять символы из строки 2 и поместить в строку 1. \n\n");
            }
            if (flag == 1) printf("\n Введите количество копируемых символов (не больше %d) и нажмите Enter: %d\n\n", str_1_cnt+1, N);
            else if (flag == 2) printf("\n Введите количество копируемых символов (не больше %d) и нажмите Enter: %d\n\n", str_2_cnt+1, N);

        }


        if (operation == 10) {

            printf("\n Нажмите 1, чтобы очистить строку 1. \n");
            printf("\n Нажмите 2, чтобы очистить строку 2. \n");
            printf("\n Нажмите 3, чтобы очистить обе строки. \n\n");

        }

        if (operation == 11) printf("\n Нажмите Enter для выхода из программы: \n\n");

        for (int i = 0; i <= 70; i++) cout << char(45);
        cout << endl;

        printf("\n Примечание: управление осуществляется стрелками на клавиатуре.\n\n");

        key = _getch();
            
        if (key == 27) { // escape

            system("cls");
            printf("\n Выход из программы...\n");
            return 0;
            break;

        }

        if (key == 13) { // Enter

            // выход
            if (operation == 11) {

                system("cls");
                printf("\n Выход из программы...\n");
                return 0;
                break;

            }

            if (operation == 9) {

                if (flag == 2) {
                    str_n_cat(str_1, str_2, str_1_cnt, N);
                    str_1_cnt += N;
                    flag = 0;
                    N = 0;
                    continue;
                }

                if (flag == 1) {
                    str_n_cat(str_2, str_1, str_2_cnt, N);
                    str_2_cnt += N;
                    flag = 0;
                    N = 0;
                    continue;
                }
            }


        }

        // нажали стрелку
        else if (key == 224) {

                int inp2 = _getch();
              
                // стрелка вниз
                if (inp2 == 80) {

                    flag = 0;
                    N = 0;
                    operation += 1;
                    if (operation == 12) operation = 1;
                    continue;

                }
                // стрелка вверх
                if (inp2 == 72) {

                    flag = 0;
                    N = 0;
                    operation -= 1;
                    if (operation == 0) operation = 11;
                    continue;

                }
        }

        else {

            if (key < 127) {
          
                if (operation == 1) {

                    if (key == 8) { // backspace

                        if (str_1_cnt > -1) {

                            str_1_cnt--;
                            end_sym = str_1_cnt + 1;
                            str_1[end_sym] = '\0';

                            continue;
                        }
                        
                    }

                    else if (str_1_cnt < 19) { // ввод символов

                        str_1_cnt++;
                        str_1[str_1_cnt] = char(key);
                        end_sym = str_1_cnt + 1;
                        str_1[end_sym] = '\0';

                        continue;

                    }
                    
                }

                if (operation == 2) {

                    if (key == 8) { // backspace

                        if (str_2_cnt > -1) {

                            str_2_cnt--;
                            end_sym = str_2_cnt + 1;
                            str_2[end_sym] = '\0';

                            continue;
                        }

                    }

                    else if (str_2_cnt < 19) { // ввод символов

                        str_2_cnt++;
                        str_2[str_2_cnt] = char(key);
                        end_sym = str_2_cnt + 1;
                        str_2[end_sym] = '\0';
                        continue;

                    }
                }

                if (operation == 4) {

                    if (key == 49) { // сохранение в строку 1

                        str_cat(str_1, str_2, str_1_cnt);
                        if (str_1_cnt + str_2_cnt + 1 > 19) str_1_cnt = 19;
                        else str_1_cnt += str_2_cnt + 1;
                        
                    }
                    else if (key == 50) { // сохранение в строку 2

                        str_cat(str_2, str_1, str_2_cnt);
                        if (str_1_cnt + str_2_cnt + 1 > 19) str_2_cnt = 19;
                        else str_2_cnt += str_1_cnt + 1;

                    }

                    continue;
                }

                if (operation == 5) {

                    if (key == 49) {

                        str_copy(str_2, str_1);
                        str_2_cnt = str_1_cnt;

                    }
                    else if (key == 50) {

                        str_copy(str_1, str_2);
                        str_1_cnt = str_2_cnt;

                    }
                    
                    continue;
                }

                if (operation == 6) {

                    if (key == 49) {

                        str_reverse(str_1, str_1_cnt);

                    }
                    else if (key == 50) {

                        str_reverse(str_2, str_2_cnt);

                    }
                    else if (key == 51) {

                        str_reverse(str_1, str_1_cnt);
                        str_reverse(str_2, str_2_cnt);

                    }

                    continue;
                }

                if (operation == 7) {

                    if (key == 49) {

                        str_upper_case(str_1);

                    }
                    else if (key == 50) {

                        str_upper_case(str_2);

                    }
                    else if (key == 51) {

                        str_upper_case(str_1);
                        str_upper_case(str_2);

                    }

                    continue;
                }

                if (operation == 8) {


                    if (key == 49) {

                        str_lower_case(str_1);

                    }
                    else if (key == 50) {

                        str_lower_case(str_2);

                    }
                    else if (key == 51) {

                        str_lower_case(str_1);
                        str_lower_case(str_2);

                    }

                    continue;
                }

                if (operation == 9) {

                    if (key == 49 && flag == 0) {

                        flag = 1;
                        continue;

                    }
                    else if (key == 50 && flag == 0) {

                        flag = 2;
                        continue;

                    }

                    if (flag == 1) {

                        if (key >= 48 && key <= 57) {

                            long inpnum = key - 48;
                            if (N * 10 + inpnum <= str_1_cnt + 1) N = N * 10 + inpnum;

                        }

                        if (key == 8) {

                            N = N / 10;
                            continue;

                        }

                    }

                    if (flag == 2) {

                        if (key >= 48 && key <= 57) {

                            long inpnum = key - 48;
                            if (N * 10 + inpnum <= str_2_cnt + 1) N = N * 10 + inpnum;

                        }

                        if (key == 8) {
                                N = N / 10;
                                continue;

                        }

                    }

                    continue;
                }

                if (operation == 10) {

                    if (key == 49) {

                        str_clr(str_1);
                        str_1_cnt = -1;

                    }
                    else if (key == 50) {

                        str_clr(str_2);
                        str_2_cnt = -1;

                    }
                    else if (key == 51) {

                        str_clr(str_1);
                        str_1_cnt = -1;
                        str_clr(str_2);
                        str_2_cnt = -1;

                    }

                    continue;
                }
            }
        }
                
    };
    return 0;
}