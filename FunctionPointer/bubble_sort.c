/*
* �ص��������Ƶ�Ӧ�ã�
* ʵ��һ��bubble_sort(ð������)��������ɲ�ͬ�������ݵ�����
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

	if (len < 2) //���鳤��С��2������Ҫ����
		return;

	for (i = 0; i<len; ++i)
	{
		for (j = 0; j<len - 1 - i; ++j)
		{
			char *elemj = (char*)arr + j*width;  //��j��Ԫ���׵�ַ
			char *elemjnext = (char*)arr + (j + 1)*width; //��j+1��Ԫ���׵�ַ

			//�Ƚ�arr[j]��arr[j+1]�Ĵ�С
			if ((*compare)(elemj, elemjnext)>0)
			{
				//����
				swap(elemj, elemjnext, width);
			}

		}
	}
}