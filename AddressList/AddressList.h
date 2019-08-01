#pragma once

#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_SIZE 1000

typedef struct Person
{
	char name[20];    //����
	char sex[2];      //�Ա�
	int age;          //����
	char tele[15];    //�绰
	char address[25]; //��ַ
}Person;

typedef struct Book
{
	Person data[MAX_SIZE]; //�洢ÿ������Ϣ�Ľṹ������
	size_t size;           //��ǰ�Ѵ洢������
}Book;

void Insert(Book* pbook);
void Delete(Book* pbook);
int Search(const Book* pbook);
void Change(Book* pbook);
void Show(const Book* pbook);
void Clear(Book* pbook);
void SortByName(Book* pbook);