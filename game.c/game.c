#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void Init(char arr[ROWS][COLS], int rows, int cols, const char ch)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            arr[i][j] = ch;
        }
    }
}

//随机埋雷 SetMine()
void SetMine(char str[ROWS][COLS], int rows, int cols, int cot)
{
    int x = 0;
    int y = 0;
    while (cot > 0)
    {
        x = rand() % 9 + 1;
        y = rand() % 9 + 1;
        if (str[x][y]=='0')
        {
            str[x][y] = '1';
            cot--;
        }
    }
}

//显示棋盘 Display（） 
void Display(char str[ROWS][COLS], int rows, int cols)
{
    int i = 0;
    int j = 0;
    for (i = -1; i < rows; i++)
    {
        printf("%3d", i+1);
    }
    printf("\n");
    for (i = 1; i <=rows; i++)
    {
        printf("%3d", i); 
        for (j = 1; j <= cols; j++)
        {
            printf("%3c", str[i][j]);
        }
        printf("\n");
    }
}


//输入坐标,判断周围的雷数，并回馈数字，为0时递归SearchMine() 
int SearchMind(char str[ROWS][COLS], int* x, int* y, int rows,int cols)
{
    int number = 0;
    //判断是否踩到雷
    if (str[*x][*y] == '1')
    {
        return -1;
    }
    number = str[*x - 1][*y - 1] + str[*x - 1][*y] + str[*x - 1][*y + 1]
        + str[*x][*y - 1] + str[*x][*y + 1]
        + str[*x + 1][*y - 1] + str[*x + 1][*y] + str[*x + 1][*y + 1] - 8 * '0';
        //if (number == 0)
        //{
        //  //改变x,y的值实现爆炸效果

        //  number = SearchMind(str, &x, &y, rows, cols);
        //}//递归
        return number;
}

//判断输赢 Distinguish()