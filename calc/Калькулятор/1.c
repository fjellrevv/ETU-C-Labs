//#include <stdio.h> 
//#include <math.h> 
//#include <stdlib.h>
//#include <conio.h>
//#include <locale.h>
//#include <limits.h>
//#include <string.h> 
//long ans;
//long num;
//long a, b;
//char input_max[10] = "2147483647";
//char input_min[11] = "-2147483648";
//char input_min_pr[11] = { "." };
//char input_max_pr[10] = { "." };
//char cnt[11] = { '-', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
//int key, flag, err, zam;
//char input_max_pr1[10] = { "." };
//char input_min_pr1[11] = { "." };
//double maxx = 2147483647;
//
//long getNumber(const char* message) {
//	int n;
//	char input_num[500];
//	printf("%s\n",message);
//	do {
//		err = 0;
//		gets(input_num);
//		for (int i = 0; input_num[i] != NULL; i++) {
//			if (err == 1) continue;
//			flag = 0;
//			for (int j = 0; j < 11; j++) { // корректность ввода
//				if (input_num[i] == cnt[j]) flag = 1; continue; 
//			}
//			if (i > 0 && input_num[i] == cnt[0]) flag = 0; 
//			if (input_num[0] == '0' && strlen(input_num) != 1 || (input_num[0] == '-' && input_num[1] == '0')) flag = 0;
//			if (flag == 0) {
//				err = 1;
//				system("cls");
//				printf("Некорректный ввод! Введите число:  ");
//			}
//		}
//		if (err == 0) {
//			if (input_num[0] != '-') {
//				if (strlen(input_num) > strlen(input_max)) {
//					err = 1;
//					system("cls");
//					printf("Число слишком большое! Введите число: ");
//				}
//				if (strlen(input_num) == strlen(input_max)) { // проверка равных по длине n>0
//					for (int i = 0; i < 11; i++) {
//						if (input_num[i] <= input_max[i]) {
//							input_max_pr[i] = input_num[i];
//							input_max_pr1[i] = input_max[i];
//						}
//						else {
//							if (atoi(input_max_pr) == atoi(input_max_pr1)) { //равны по длине знаку и по первым цифрам
//								err = 1;
//								system("cls");
//								printf("Число слишком большое! Введите число: ");
//							}
//							else if (atoi(input_max_pr) < atoi(input_max_pr1)) {
//								input_max_pr[i] = input_num[i];
//								input_max_pr1[i] = input_max[i];
//							}
//						}
//					}
//				}
//			}
//			else if (input_num[0] == '-') {
//				if (strlen(input_num) > strlen(input_min)) {
//					err = 1;
//					system("cls");
//					printf("Число слишком маленькое! Введите число: ");
//				}
//				else if (strlen(input_num) == strlen(input_min)) { // проверка равных по длине n<0
//					for (int i = 1; i < 12; i++) {
//						if (input_num[i] <= input_min[i]) {
//							input_min_pr[i] = input_num[i];
//							input_min_pr1[i] = input_min[i];
//						}
//						else {
//							if (atoi(input_min_pr) == atoi(input_min_pr1)) { //равны по длине знаку и по первым цифрам
//								err = 1;
//								system("cls");
//								printf("Число слишком маленькое! Введите число: ");
//							}
//							else if (atoi(input_min_pr) < atoi(input_min_pr1)) {
//								input_min_pr[i] = input_num[i];
//								input_min_pr1[i] = input_min[i];
//							}
//						}
//					}
//				}
//			}
//		}
//	} while (err != 0);
//	n = atoi(input_num);
//	return n;
//}
//int main() {
//	setlocale(LC_ALL, "Rus");
//	long exitKey;
//	const char* get1 = "Введите число A: ";
//	const char* get2 = "Введите число B: ";
//	a = getNumber(get1);
//	b = getNumber(get2);
//	system("cls");
//	do {
//		int operation;
//		do {
//			operation = 0;
//			num = 1;
//			while (1) {
//				printf("Вы ввели числа: \nA = %d\nB = %d\n", a, b);
//				printf("\nКалькулятор выполняет следующие операции: ");
//				printf("\n1. A + B ");
//				if (num == 1) printf("<--");
//				printf("\n2. A - B ");
//				if (num == 2) printf("<--");
//				printf("\n3. A * B ");
//				if (num == 3) printf("<--");
//				printf("\n4. A / B ");
//				if (num == 4) printf("<--");
//				printf("\n5. Возведение A в степень В ");
//				if (num == 5) printf("<--");
//				printf("\n6. Извлечение корня B степени из A ");
//				if (num == 6) printf("<--");
//				printf("\n7. Замена числа А ");
//				if (num == 7) printf("<--");
//				printf("\n8. Замена числа В ");
//				if (num == 8) printf("<--");
//				printf("\n9. Перестановка чисел A и В ");
//				if (num == 9) printf("<--");
//				printf("\n10. Выход из программы ");
//				if (num == 10) printf("<--");
//				printf("\n\nВыберите номер операции от 1 до 10: \n");
//				key = _getch();
//				switch (key) {
//					case 25: continue;
//					case 35: continue;
//					case 33: continue;
//					case 49: operation = 1; break;
//					case 50: operation = 2; break; 
//					case 51: operation = 3; break;
//					case 52: operation = 4; break;
//					case 53: operation = 5; break;
//					case 54: operation = 6; break;
//					case 55: operation = 7; break;
//					case 56: operation = 8; break;
//					case 57: operation = 9; break;
//					case 58: operation = 10; break;
//					case 13: operation = num; break;
//					case 75: num -= 2; // left
//					case 77: num += 2; // right
//					case 72: num -= 2; // up
//					case 80: num += 1; // down
//					if (num > 8) num = 1;
//					else if (num < 1) num = 8;
//				}
//				if ((operation >= 1) && (operation <= 8)) break;
//				system("cls");
//			}
//			if (operation == 1) {
//				if (((a >= 0) && (b >= 0) && (INT_MAX - b > a)) || ((a <= 0) && (b <= 0) && (INT_MIN - b < a)) || (a <= 0) && (b >= 0) || (a >= 0) && (b <= 0)) {
//					ans = a + b;
//					printf("\nВы выбрали A + B \n");
//					printf("\nОтвет = %d\n", ans);
//					break;
//				}
//				else {
//					printf("\nРезультат выходит за пределы допустимых значений!\n");
//					break;
//				}
//			}
//			else if (operation == 2) {
//				if (((a >= 0) && (b <= 0) && (INT_MAX + b > a)) || ((a <= 0) && (b >= 0) && (INT_MIN + b < a)) || (a <= 0) && (b <= 0) || (a >= 0) && (b >= 0)) {
//					ans = a - b;
//					printf("\nВы выбрали A - B \n");
//					printf("\nОтвет = %d\n", ans);
//					break;
//				}
//				else {
//					printf("\nРезультат выходит за пределы допустимых значений!\n");
//					break;
//				}
//			}
//			else if (operation == 3) {
//				ans = a * b;
//				if ((b<=sqrt(maxx) && (a<=b)) || (a <= sqrt(maxx) && (b <= a))) {
//					ans = a * b;
//					printf("\nВы выбрали A * B \n");
//					printf("\nОтвет = %d\n", ans);
//					break;
//				}
//				else {
//					printf("\nРезультат выходит за пределы допустимых значений!\n");
//					break;
//				}
//			}
//			else if (operation == 4) {
//				if (b == 0) {
//					printf("\nОтвета нет\n");
//					break;
//				}
//				else if ((a / b <= INT_MAX) && (a / b >= INT_MIN)) {
//					ans = a / b;
//					printf("\nВы выбрали A / B \n");
//					printf("\nОтвет = %d\n", ans);
//					break;
//				}
//				else {
//					printf("\nРезультат выходит за пределы допустимых значений!\n");
//					break;
//				}
//			}
//			else if (operation == 5) {
//				if ((pow(a, b) <= INT_MAX) && (pow(a, b) >= INT_MIN)) {
//					ans = pow(a, b);
//					printf("\nВы выбрали возведение A в степень В \n");
//					printf("\nОтвет = %d\n", ans);
//					break;
//				}
//				else {
//					printf("\nРезультат выходит за пределы допустимых значений!\n");
//					break;
//				}
//			}
//			else if (operation == 6) {
//				float a1 = a;
//				float b1 = b;
//				if (b1 <= 0 || (a1 <= 0 && b % 2 == 0 && a < b)) {
//					printf("\nОтвета нет\n");
//					break;
//				}
//				
//			}
//			if (operation == 7) {
//				const char* get3 = "Введите новое число A: ";
//				a = getNumber(get3);
//				break;
//			}
//			if (operation == 8) {
//				const char* get4 = "Введите новое число B: ";
//				b = getNumber(get4);
//				break;
//			}
//			if (operation == 9) {
//				printf("\nВы выбрали перестановку чисел\n");
//				zam = a;
//				a = b;
//				b = zam;
//				break;
//			}
//			else if (operation == 10) {
//				printf("\n\nВыход из программы...\n");
//				return 0;
//				break;
//			}
//		} while (!((operation >= 1) && (operation <= 10)) || (key != 13));
//		printf("\nДля продолжения нажмите 1\nДля выхода нажмите любую другую цифру\n");
//		while ((scanf_s("%d", &exitKey) != 1)) {
//			system("cls");
//			printf("Некорректный ввод. Для продолжения нажмите 1\nДля выхода нажмите любую другую цифру\n");
//			while (getchar() != '\n');
//		}
//		system("cls");
//		} while (exitKey == 1);
//	return 0;
//}