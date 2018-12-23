#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define N 5

char* Names[N] = { "����", "������", "���", "�������", "�����"};
int Codes[N] = { 234, 1235, 1236, 1237, 1238};
int Prices[N] = { 0 };
int Discounts[N] = { 0 };
int Count[N] = { 0 };

void Scan() {
	int i = 0, flag = 0, Code = 0;
	printf("������� �����-��� ������: #");
	scanf("%d", &Code);
	for (i = 0; i < N; i++) {
		if (Codes[i] == Code) flag = i + 1;
	}
	if (flag != 0) {
		printf("#");
		if (Codes[flag - 1] < 10) {
			printf("000%d", Codes[flag - 1]);
		}
		else if (Codes[flag - 1] < 100) {
			printf("00%d", Codes[flag - 1]);
		}
		else if (Codes[flag - 1] < 1000) {
			printf("0%d", Codes[flag - 1]);
		}
		else {
			printf("%d", Codes[flag - 1]);
		}
		printf("   ");
		fputs(Names[flag - 1], stdout);
		printf("   %d �   %d ��������� \n", Prices[flag - 1], Discounts[flag - 1]);
	}
	else {
		printf("������ ������ �� ���������� \n");
	}
}

void AddToCheck() {
	int i, flag = 0, Code = 0;
	printf("\n������� �����-��� ������, ������� �� ������ ��������: #");
	scanf("%d", &Code);
	for (i = 0; i < N; i++) {
		if (Codes[i] == Code) flag = i + 1;
	}
	if (flag != 0) {
		printf("\n����� ���������� ������ �� ������ ��������? (������� 0, ���� �� ������ ���������) \n");
		scanf("%d", &Count[flag - 1]);
		if(Count[flag - 1] != 0)
			printf("\n����� ������� ��������\n");
	}
	else {
		printf("\n������ ������ �� ����������\n");
	}
}

void Print() {
	int i, TotalPrice = 0, TotalDiscount = 0, flag = 0;
	for (i = 0; i < N; i++) {
		if (Count[i] > 0) flag = 1;
	}
	if (flag > 0) {
		printf("\n=====���=====\n");
		for (i = 0; i < N; i++) {
			if (Count[i] != 0) {
				TotalPrice += Prices[i] * Count[i];
				TotalDiscount += Prices[i] * Count[i] * Discounts[i] / 100;
				fputs(Names[i], stdout);
				printf("   %d   %d   %d \n", Prices[i], Count[i], Prices[i] * Count[i]);
			}
		}
		printf("����� ���������: %d � \n", TotalPrice);
		printf("��������� ������: %d � \n", TotalDiscount);
		printf("�������� ���������: %d � \n \n", TotalPrice - TotalDiscount);
	}
	else {
		printf("������� �����, ������� ��� ����������");
	}
}

void main() {
	int i, j = 0;
	setlocale(LC_ALL, "Russian");
	srand((unsigned int)time(0));
	for (i = 0; i < N; i++) {
		Prices[i] = 50 + rand() % 3000;
		Discounts[i] = 1 + rand() % 50;
		Count[i] = 0;
	}
	do {
		printf(" ������� 1, ����� ������������� ����� \n ������� 2, ����� �������� ����� � ������� \n ������� 3, ����� ���������� ��� \n ������� 0, ����� ����� \n");
		scanf("%d", &j);
		if (j == 1)
			Scan();
		else if (j == 2)
			AddToCheck();
		else if (j == 3)
			Print();
	} while (j != 0);
}