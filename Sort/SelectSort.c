#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS 1

void SelectSort(int* arr, int len)
{
	int i = 0;
	int j = 0;
	for(i = 0; i < len-1; i++)      //控制选择的趟数
	{
		int tmp;                
		int min = i;
		for(j = i+1; j < len; j++)  //控制每趟选择比较的次数
		{
			if(arr[min] > arr[j])
			{
				min = j;
			}
		}
		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
	}
}
int main()
{
	int i = 0;
	int array[10] = {9, 3, 2, 5, 4, 7, 6, 0, 1, 8};
	SelectSort(array, sizeof(array)/sizeof(int));

	for(i = 0; i < sizeof(array)/sizeof(int); i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}