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
		printf("choose：>");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 1:
			Game(&a[0][0]);
			break;
		case 0:
			printf("游戏结束！");
		default:
			printf("输入有错，重新输入！");
			Menu();
		}
	} while (input);

}