#define _CRT_SECURE_NO_WARNINGS 1

#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROWS 11
#define COLS 11
#define ROW 9
#define COL 9
#define count 10

void Init(char arr[ROWS][COLS],int rows, int cols, const char ch);
void SetMine(char str[ROWS][COLS], int rows, int cols, int cot);
void Display(char str[ROWS][COLS], int rows, int cols);
int SearchMind(char str[ROWS][COLS], int* x, int* y, int rows, int cols);
#endif