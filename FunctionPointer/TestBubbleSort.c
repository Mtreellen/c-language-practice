#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 1

extern void BubbleSort(void *arr, int len, int width,
	int(*compare) (void *elem1, void *elem2));

int Compare_int(void *elem1, void *elem2)
{
	return *(int*)elem1 - *(int*)elem2;
}

void TestArr_int()
{
	int arr_int[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int len = sizeof(arr_int) / sizeof(arr_int[0]);
	BubbleSort(arr_int, len, sizeof(arr_int[0]), &Compare_int);
	//´òÓ¡Êý×é
	{
		int i = 0;
		for (i = 0; i<len; i++)
		{
			printf("%d ", arr_int[i]);
		}
	}
}
int main()
{
	TestArr_int();
	system("pause");
	return 0;
}