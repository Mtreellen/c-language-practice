#pragma once

#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_SIZE 1000

typedef struct Person
{
	char name[20];    //姓名
	char sex[2];      //性别
	int age;          //年龄
	char tele[15];    //电话
	char address[25]; //地址
}Person;

typedef struct Book
{
	Person data[MAX_SIZE]; //存储每个人信息的结构体数组
	size_t size;           //当前已存储的人数
}Book;

void Insert(Book* pbook);
void Delete(Book* pbook);
int Search(const Book* pbook);
void Change(Book* pbook);
void Show(const Book* pbook);
void Clear(Book* pbook);
void SortByName(Book* pbook);