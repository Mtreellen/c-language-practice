/*
* 回调函数机制的应用：
* 实现一个bubble_sort(冒泡排序)，可以完成不同类型数据的排序。
*/
#define _CRT_SECURE_NO_WARNINGS 1

void swap(char *a, char *b, int width)
{
	if (a != b)
	{
		while (width--)
		{
			char tmp = *a;
			*a = *b;
			*b = tmp;
			a++;
			b++;
		}
	}
}

void BubbleSort(void *arr, int len, int width, int(*compare) (void *elem1, void *elem2))
{
	int i = 0;
	int j = 0;

	if (len < 2) //数组长度小于2，则不需要排序
		return;

	for (i = 0; i<len; ++i)
	{
		for (j = 0; j<len - 1 - i; ++j)
		{
			char *elemj = (char*)arr + j*width;  //第j个元素首地址
			char *elemjnext = (char*)arr + (j + 1)*width; //第j+1个元素首地址

			//比较arr[j]与arr[j+1]的大小
			if ((*compare)(elemj, elemjnext)>0)
			{
				//交换
				swap(elemj, elemjnext, width);
			}

		}
	}
}