#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS 1

void BubbleSort(int* arr, int len)
{
	int i = 0;
	int j = 0;
	int flag1 = 0;
	int flag2 = 0;
	int k = len-1;                    //用k来记录每趟排序的比较次数
	for(i = 0; i < len-1; i++)        //需要排len-1趟
	{
		flag1 = 0;
		for(j = 0; j < k; j++)        
		{
			if(arr[j] > arr[j+1])
			{
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
				flag1 = 1;
				flag2 = j;
			}
		}
		k = flag2;
		if(flag1 == 0)
		{
			return;
		}
	}
}

int main()
{
	int i = 0;
	int array[7] = {4,3,2,5,6,7,8};
	BubbleSort(array, 7);
	for(i = 0; i<7; i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	
	system("pause");
	return 0;
}