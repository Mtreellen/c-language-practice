#include <stdio.h>
#include "BTree.h"

#if 0
// ������ʾջ����ģ��������󣬴���ʽ
// 1. ջ�Ŀռ����ޣ����ÿ��ƣ�Ĭ�ϱȽ�С
// 2. ** �ݹ�Ƚ���
int Sum(int n)
{
	if (n == 1) {
		return 1;
	}

	return Sum(n - 1) + n;
}

#endif

int main()
{
	//printf("%d\n", Sum(1000000));
	Test();

	return 0;
}