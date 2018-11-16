#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void Menu()
{
	printf(" 任意子棋游戏 \n");
	printf(" ___________ \n");
	printf("| 1.play    |\n");
	printf("| 0.exit    |\n");
	printf("|___________|\n");
}
void InitBoard(char a[][COL], int R, int C)
{
	memset(a, ' ', R*C);
}
void Game(char a[][COL])
{
	int amount = 0;
	srand((unsigned int)time(NULL));
	printf("请输入你想玩几子棋：>");
	scanf("%d", &amount);
	system("cls");
	ShowBoard(a, ROW, COL);
	while (1)
	{
		char judge;
		int jud;
		PlayerMove(a);
		system("cls");
		//judge = IsWin(a);
		judge = IsWinTwo(a, amount);
		jud = Judge(judge);
		ShowBoard(a, ROW, COL);
		if (jud == 1)
		{
			printf("玩家赢！\n");
			exit(0);
		}
		else if (jud == 2)
		{
			printf("平局！");
			exit(0);
		}
		ComputerMove(a);
		//	judge = IsWin(a);
		judge = IsWinTwo(a, amount);
		jud = Judge(judge);
		ShowBoard(a, ROW, COL);
		if (jud)
		{
			printf("电脑赢！\n");
			exit(0);
		}
	}
}
int Judge(char judge)
{
	if (judge == 'X')
	{
		return 1;
	}
	else if (judge == '*')
	{
		return 1;
	}
	else if (judge == '#')
	{
		return 2;
	}
	else if (judge == ' ')
	{
		return 0;
	}
}
void  ShowBoard(char a[][COL], int  R, int C)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < C; i++)
	{
		if (i == 0)
		{
			printf("     %d  ", i + 1);
		}

		else
		{
			printf(" %-2d ", i + 1);
		}

	}
	printf("\n");
	for (i = 0; i < C; i++)
	{
		if (i == 0)
		{
			printf("    ___");
		}
		else
		{
			printf("____");
		}

	}
	printf("\n");
	for (i = 0; i < R; i++)
	{
		printf("%2d", i + 1);
		for (j = 0; j < C; j++)
		{
			if (j == 0)
			{
				printf(" | %c |", a[i][j]);
			}
			else
			{
				printf(" %c |", a[i][j]);
			}

		}
		printf("\n");
		if (i == R - 1)
		{
			for (i = 0; i < C; i++)
			{
				if (i == 0)
				{
					printf("   ￣￣");
				}
				else
				{
					printf("￣￣");
				}

			}
			printf("\n");
		}
		else
		{
			for (j = 0; j < C; j++)
			{
				if (j == 0)
				{
					printf("   |");
				}
				{
					printf("---|");
				}
			}
			printf("\n");
		}

	}

}
void PlayerMove(char a[][COL])
{
	int x = 0;
	int y = 0;
	while (1)
	{

		printf("玩家走(输入坐标1-3)：>");
		scanf("%d %d", &x, &y);
		if (x > ROW || y > COL)
		{
			printf("非法输入，请重新输入\n");
		}
		else
		{
			//if (a[x - 1][y - 1] == '*'||a[x - 1][y - 1] == 'X')
			if (a[x - 1][y - 1] != ' ')
			{
				printf("走错了，重新走\n");
			}
			else
			{
				a[x - 1][y - 1] = 'X';
				break;
			}
		}

	}
}


void ComputerMove(char a[][COL])
{
	int x = 0;
	int y = 0;
	system("cls");

	printf("电脑走\n");
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (a[x][y] == ' ')
		{
			a[x][y] = '*';
			break;
		}
	}
}
char IsWinTwo(char a[][COL], int amount)
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (a[i][j] != ' ')
			{
				for (k = 0; k < amount - 1; k++)
				{
					if ((a[i][j + k] == a[i][j + k + 1] && a[i][j + k] != ' '))
					{
						if (j + k + 1 > COL)
						{
							break;
						}
						continue;
					}
					else
					{
						break;
					}
				}
				if (k == amount - 1)
				{
					return a[i][j];
				}



				for (k = 0; k < amount - 1; k++)
				{
					if (a[i + k][j] == a[i + k + 1][j] && a[i + k][j] != ' ')
					{
						if (i + k + 1 > ROW)
						{
							break;
						}
						continue;
					}
					else
					{
						break;
					}
				}
				if (k == amount - 1)
				{
					return a[i][j];
				}


				for (k = 0; k < amount - 1; k++)
				{
					if (a[i + k][j - k] == a[i + k + 1][j - k - 1] && a[i + k][j - k] != ' ')
					{
						if (j - k - 1 < 0)
						{
							break;
						}
						continue;
					}
					else
					{
						break;
					}
				}
				if (k == amount - 1)
				{
					return a[i][j];
				}

				for (k = 0; k < amount - 1; k++)
				{
					if (a[i + k][j + k] == a[i + k + 1][j + k + 1] && a[i + k][j + k] != ' ')
					{
						if (i + k + 1 < 0)
						{
							break;
						}
						continue;
					}
					else
					{
						break;
					}
				}
				if (k == amount - 1)
				{
					return a[i][j];
				}

			}
		}
	}
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (a[i][j] == ' ')
				return ' ';
		}
	}
	return '#';
}
//
//char IsWin(char a[][COL])
//{
//	int i = 0;
//	int j = 0;
//	/*for (i = 0; i < ROW; i++)
//	{
//
//		if ((a[i][0] == a[i][1] && a[i][1] == a[i][2] )&&a[i][0] != ' ')
//			return a[i][0];
//	}
//	if ((a[0][0] == a[1][1] && a[1][1] == a[2][2])|| (a[0][2] == a[1][1]&& a[1][1] == a[2][0]))
//	{
//		return a[1][1];
//	}
//	for(i = 0;i<COL;i++)
//	{ 
//		if ((a[0][i] == a[1][i] && a[1][i] == a[2][i]) && a[0][i] != ' ')
//			return a[0][i];
//	}
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = 0; j < COL; j++)
//		{
//			if (a[i][j] == ' ')
//				return ' ';
//		}
//	}
//	return '#';*/
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = 0; j < COL; j++)
//		{
//			if (a[i][j] != ' ')
//			{
//				if ((a[i][j] == a[i][j + 1] && a[i][j + 1] == a[i][j + 2]))
//				{
//					return a[i][j];
//				}
//
//				if ((a[i][j] == a[i + 1][j] && a[i + 1][j] == a[i + 2][j]))
//				{
//					return a[i][j];
//				}
//				if (a[i][j] == a[i + 1][j + 1] && a[i + 1][j + 1] == a[i + 2][j + 2])
//				{
//					return a[i][j];
//				}
//				if (a[i][j] == a[i - 1][j - 1] && a[i - 1][j - 1] == a[i - 2][j - 2])
//				{
//					return a[i][j];
//				}
//			}
//		}
//	}
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = 0; j < COL; j++)
//		{
//			if (a[i][j] == ' ')
//				return ' ';
//		}
//	}
//	return '#';
//}