#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
#include <stdlib.h>
#include <Windows.h>
int main()
{

	int a[ROW][COL];
	int input;
	InitBoard(a, ROW, COL);
	Menu();
	do
	{
		printf("choose��>");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 1:
			Game(&a[0][0]);
			break;
		case 0:
			printf("��Ϸ������");
		default:
			printf("�����д��������룡");
			Menu();
		}
	} while (input);

}