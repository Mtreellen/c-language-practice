/*
* 使用qsort排序一个整型数组，一个浮点型数组，一个字符串数组。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS 1

int CompareInt(const void *elem1, const void *elem2)
{
	return *(int*)elem1 - *(int*)elem2;
}

int CompareFloat(const void *elem1, const void *elem2)
{
	if (*(float*)elem1 > *(float*)elem2)
	{
		return 1;
	}
	else if (*(float*)elem1 == *(float*)elem2)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int CompareStr(const void *elem1, const void *elem2)
{
	return strcmp(*(char**)elem1, *(char**)elem2);
}

void TestArr_int()
{
	int arr_int[] = { 10, 2, 8, 4, 3, 6, 7, 5, 9, 1 };
	int len = sizeof(arr_int) / sizeof(arr_int[0]);
	qsort(arr_int, len, sizeof(arr_int[0]), &CompareInt);
	//打印数组
	{
		int i = 0;
		for (i = 0; i < len; i++)
		{
			printf("%d ", arr_int[i]);
		}
		printf("\n");
	}
}

void TestArr_float()
{
	float arr_float[] = { 9.0f, 7.7f, 3.3f, 4.9f, 2.3f, 8.4f };
	int len = sizeof(arr_float) / sizeof(arr_float[0]);
	qsort(arr_float, len, sizeof(arr_float[0]), &CompareFloat);
	//打印数组
	{
		int i = 0;
		for (i = 0; i < len; i++)
		{
			printf("%f ", arr_float[i]);
		}
		printf("\n");
	}
}

void TestArr_str()
{
	char* arr_str[] = { "aaaa", "cccc", "fffff", "zzzz", "dddd" };
	int len = sizeof(arr_str) / sizeof(arr_str[0]);
	qsort(arr_str, len, sizeof(arr_str[0]), &CompareStr);
	//打印数组
	{
		int i = 0;
		for (i = 0; i < len; i++)
		{
			printf("%s ", arr_str[i]);
		}
		printf("\n");
	}
}

int main()
{
	TestArr_int();
	TestArr_float();
	TestArr_str();
	return 0;
}