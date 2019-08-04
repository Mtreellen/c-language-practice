#include <stdio.h>
#include "BTree.h"

#if 0
// 这是演示栈溢出的，真正的求，带公式
// 1. 栈的空间有限，不好控制，默认比较小
// 2. ** 递归比较慢
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