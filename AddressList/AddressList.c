#include "AddressList.h"
#define _CRT_SECURE_NO_WARNINGS 1

void Insert(Book* pbook)    //1.�����ϵ����Ϣ
{
	if (pbook->size > MAX_SIZE)
	{
		printf("book is fulled!");
		return;
	}
	printf("please enter name:\n");
	scanf("%s", pbook->data[pbook->size].name);
	printf("please enter sex:\n");
	scanf("%s", pbook->data[pbook->size].sex);
	printf("please enter age:\n");
	scanf("%d", &pbook->data[pbook->size].age);
	printf("please enter telephone:\n");
	scanf("%s", pbook->data[pbook->size].tele);
	printf("please enter adddress:\n");
	scanf("%s", pbook->data[pbook->size].address);

	pbook->size++;
}
void Delete(Book* pbook)    //2.ɾ��ָ����ϵ��
{
	int ret = 0;
	if (pbook->size == 0)
	{
		printf("book is empty");
		return;
	}
	ret = Search(pbook);
	if (ret != -1)
	{
		int del = 0;
		printf("��ȷ��Ҫɾ��������ɾ���밴1��ȡ���밴0\n");
		scanf("%d", &del);
		if (del == 1)
		{
			unsigned  i = 0;
			for (i = ret; i < pbook->size - 1; i++)
			{
				pbook->data[i] = pbook->data[i + 1];
			}
			pbook->size--;
			printf("��ɾ��\n");
		}
	}
}

int Search(const Book* pbook)  //3.����ָ����ϵ����Ϣ
{
	char name[20];
	unsigned  i = 0;
	printf("������������\n");
	scanf("%s", name);
	for (i = 0; i<pbook->size; i++)
	{
		if (strcmp(name, pbook->data[i].name) == 0)
		{
			printf("name:%s sex:%s age:%d tele:%s adddress:%s\n",
				pbook->data[i].name, pbook->data[i].sex, pbook->data[i].age,
				pbook->data[i].tele, pbook->data[i].address);
			return i;
		}
	}
	printf("No find!\n");
	return -1;
}

void Change(Book* pbook)  //4.�޸�ָ����ϵ����Ϣ
{
	int change = Search(pbook);
	if (change != -1)
	{
		printf("please enter name:\n");
		scanf("%s", pbook->data[change].name);
		printf("please enter sex:\n");
		scanf("%s", pbook->data[change].sex);
		printf("please enter age:\n");
		scanf("%d", &pbook->data[change].age);
		printf("please enter telephone:\n");
		scanf("%s", pbook->data[change].tele);
		printf("please enter adddress:\n");
		scanf("%s", pbook->data[change].address);
		printf("���޸�");
	}
}


void Show(const Book* pbook)  //5.��ʾ������ϵ����Ϣ
{
	unsigned  i = 0;
	if (pbook->size == 0)
	{
		printf("book is empty\n");
		return;
	}
	for (i = 0; i<pbook->size; i++)
	{
		printf("name:%s sex:%s age:%d tele:%s adddress:%s\n",
			pbook->data[i].name, pbook->data[i].sex, pbook->data[i].age,
			pbook->data[i].tele, pbook->data[i].address);
	}
}


void Clear(Book* pbook)     //6.���������ϵ��
{
	pbook->size = 0;
}

void SortByName(Book* pbook)  //7.����������������ϵ��
{
	unsigned  i = 0;
	for (i = 0; i < pbook->size - 1; i++)
	{
		if (strcmp(pbook->data[i].name, pbook->data[i + 1].name) > 0)
		{
			Person tmp;
			strcpy(tmp.name, pbook->data[i].name);
			strcpy(tmp.sex, pbook->data[i].sex);
			tmp.age = pbook->data[i].age;
			strcpy(tmp.tele, pbook->data[i].tele);
			strcpy(tmp.address, pbook->data[i].address);

			strcpy(pbook->data[i].name, pbook->data[i + 1].name);
			strcpy(pbook->data[i].sex, pbook->data[i + 1].sex);
			pbook->data[i].age = pbook->data[i + 1].age;
			strcpy(pbook->data[i].tele, pbook->data[i + 1].tele);
			strcpy(pbook->data[i].address, pbook->data[i + 1].address);

			strcpy(pbook->data[i + 1].name, tmp.name);
			strcpy(pbook->data[i + 1].sex, tmp.sex);
			pbook->data[i + 1].age = tmp.age;
			strcpy(pbook->data[i + 1].tele, tmp.tele);
			strcpy(pbook->data[i + 1].address, tmp.address);
		}
	}
	Show(pbook);
}