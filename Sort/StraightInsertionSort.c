#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS 1

void StraightInsertionSort(int* arr, int len)
{
	int i = 0;
	for(i = 1; i < len; i++) //记录要插入的数
	{
		//比较前面序列的最后一个数和要插入的数，如果没序，则需要插入
		if(arr[i]<arr[i-1])     
		{
			int j = 0;
			int tmp = arr[i];   //记录要插入的这个数

			//当前面的序列中的数目大于0个 且 前面的数大于要插入的这个数时进入循环
			for(j = i-1; j>=0 && arr[j]>tmp; j--)
			{
				arr[j+1] = arr[j];  //将前面的数向后移动
			}
			arr[j+1] = tmp;//将记录的要插入的数插入
		}
	}
}

int main()
{
	int i = 0;
	int array[5] = {5,3,2,4,1};

	StraightInsertionSort(array, sizeof(array)/sizeof(int));

	for(i = 0; i < sizeof(array)/sizeof(int); i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	
	system("pause");
	return 0;
}