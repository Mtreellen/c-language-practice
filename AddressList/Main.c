/**
* 实现一个通讯录；
* 通讯录可以用来存储1000个人的信息，每个人的信息包括：
* 姓名、性别、年龄、电话、住址
*
* 提供方法：
* 1.	添加联系人信息
* 2.	删除指定联系人信息
* 3.	查找指定联系人信息
* 4.	修改指定联系人信息
* 5.	显示所有联系人信息
* 6.	清空所有联系人
* 7.	以名字排序所有联系人
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "AddressList.h"
#define _CRT_SECURE_NO_WARNINGS 1

void face()
{
	printf("************通讯录************\n");
	printf("* 1.    添加联系人信息       *\n");
	printf("* 2.	删除指定联系人信息   *\n");
	printf("* 3.	查找指定联系人信息   *\n");
	printf("* 4.	修改指定联系人信息   *\n");
	printf("* 5.	显示所有联系人信息   *\n");
	printf("* 6.	清空所有联系人       *\n");
	printf("* 7.	以名字排序所有联系人 *\n");
	printf("* 8.    退出通讯录           *\n");
	printf("******************************\n");
	printf("请输入要操作的序号：");
}
int main()
{
	Book book;
	int ch;
	book.size = 0;

	while (1)
	{

		AAA:face();
		scanf("%d", &ch);
		system("cls");
		switch (ch)
		{
		case 1:
			Insert(&book);
			break;
		case 2:
			Delete(&book);
			break;
		case 3:
			Search(&book);
			break;
		case 4:
			Change(&book);
			break;
		case 5:
			Show(&book);
			break;
		case 6:
			Clear(&book);
			break;
		case 7:
			SortByName(&book);
			break;
		case 8:
			exit(0);
		default:
			printf("输入有误，请重新输入：");
			goto AAA;
			break;
		}
		printf("\n");
	}

	system("pause");
	return 0;
}