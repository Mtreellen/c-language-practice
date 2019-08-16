#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void Menu()
{
    printf("=======================================================================\n");
    printf("************************		1.PLAY        *************************\n");
	printf("************************		0.EXIT		  *************************\n");
    printf("=======================================================================\n");
}



int Game()
{
    int x = 0;
    int y = 0;
    int i = 0;
    int j = 0;
    int ret = 0;
    int num = count;
    char real[ROWS][COLS] = {'0'};
    char show[ROWS][COLS] = {'*'};
    srand((unsigned)time(NULL));
    Init(real,ROWS, COLS, '0');
    Init(show, ROWS, COLS, '*');
    SetMine(real, ROWS, COLS, count);
    Display(show, ROW, COL);
    printf("Pelase Input x and y :\n");
    scanf_s("%d%d", &x, &y);
    if (real[x][y] == '1')//保证第一次不踩到雷
    {
        do
        {
            SetMine(real, ROWS, COLS, count);
        } while (real[x][y] == '1');
    }
    show[x][y] = SearchMind(real, &x, &y, ROWS, COLS) + '0';
    for (i = 0; i <ROWS; i++)//管理员监视器模块
    {
        //printf("%3d", i); 
        for (j = 0; j < COLS; j++)
        {
            printf("%3c", real[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    Display(show, ROW, COL);
    while ((ROW*COL) > (ROW*COL - num))
    {
        printf("Pelase Input x and y :\n");
        scanf_s("%d%d", &x, &y);
        ret = SearchMind(real, &x, &y, ROWS, COLS) + 1;
        if (ret!=0)//不是踩到雷的情况进入
        {
            show[x][y] = SearchMind(real, &x, &y, ROWS, COLS) + '0';//转化成字符型
            Display(show, ROW, COL);
        }
        if (ret == 0)//踩到雷的情况进入
        {
            return 0;
        }
        num--;
    }
    return 1;
}

int main()
{

    Menu();
    while (1)
    {
        int m = 0;
        scanf_s("%d", &m);
        switch (m)
        {
        case 1:
        {
            if (Game())
            {
                printf("恭喜你，胜利通关！！\n");
            }
            else
            {
                printf("失败啦，再来一局吧！！\n");
                Menu();
            }
            break; 
        }
        case 2:
            return 0;
            break;
        default:
            printf("请重新输入\n");
            break;
        }
    }
}
