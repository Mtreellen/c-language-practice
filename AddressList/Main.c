/**
* ʵ��һ��ͨѶ¼��
* ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ������
* �������Ա����䡢�绰��סַ
*
* �ṩ������
* 1.	�����ϵ����Ϣ
* 2.	ɾ��ָ����ϵ����Ϣ
* 3.	����ָ����ϵ����Ϣ
* 4.	�޸�ָ����ϵ����Ϣ
* 5.	��ʾ������ϵ����Ϣ
* 6.	���������ϵ��
* 7.	����������������ϵ��
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "AddressList.h"
#define _CRT_SECURE_NO_WARNINGS 1

void face()
{
	printf("************ͨѶ¼************\n");
	printf("* 1.    �����ϵ����Ϣ       *\n");
	printf("* 2.	ɾ��ָ����ϵ����Ϣ   *\n");
	printf("* 3.	����ָ����ϵ����Ϣ   *\n");
	printf("* 4.	�޸�ָ����ϵ����Ϣ   *\n");
	printf("* 5.	��ʾ������ϵ����Ϣ   *\n");
	printf("* 6.	���������ϵ��       *\n");
	printf("* 7.	����������������ϵ�� *\n");
	printf("* 8.    �˳�ͨѶ¼           *\n");
	printf("******************************\n");
	printf("������Ҫ��������ţ�");
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
			printf("�����������������룺");
			goto AAA;
			break;
		}
		printf("\n");
	}

	system("pause");
	return 0;
}