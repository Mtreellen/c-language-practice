#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 1

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}
void Menu()
{
	printf("��ѡ����Ҫִ�еĲ�����\n");
	printf("  1.��        2.��\n");
	printf("  3.��        4.��\n");
	printf("       0.�˳�\n");
}

void Calculate()
{
	int search = 1;
	int(*pfun_arr[5])(int, int) = { 0, &Add, &Sub, &Mul, &Div };

	while (search)
	{
		Menu();
		scanf("%d", &search);
		if (search >= 1 && search <= 4)
		{
			int num1 = 0;
			int num2 = 0;
			int ret = 0;
			printf("������Ҫ�������������\n");
			scanf("%d%d", &num1, &num2);
			ret = (*pfun_arr[search])(num1, num2);
			printf("%d\n", ret);
		}
		else if (search == 0)
		{
			exit(0);
		}
		else
		{
			printf("������������������.\n");
		}

	}


}
int main()
{
	Calculate();
	system("pause");
	return 0;
}