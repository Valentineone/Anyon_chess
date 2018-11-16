#ifndef _GAME__H_
#define _GAME__H_
#pragma onc
#define ROW 10
#define COL 10
#include <string.h>
void Menu();
void ShowBoard(char a[][COL], int R, int C);
void InitBoard(char a[][COL], int R, int C);
void Game(char a[][COL]);
void PlayerMove(char a[][COL]);
//char IsWin(char a[][COL]);
void ComputerMove(char a[][COL]);
char IsWinTwo(char a[][COL], int amount);
#endif