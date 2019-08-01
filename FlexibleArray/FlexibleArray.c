#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/*
* 柔性数组：(flexible array) C99中引入
* 结构体中的最后一个元素允许是未知大小的数组。
*/
typedef struct flexible
{
	int i;
	int a[]; //C99支持这种，有些编译器将int a[0];作为非标准来支持。
}flexible;

int main()
{
//	printf("%d\n", sizeof(flexible));  //4 sizeof返回的这种结构体大小不包含柔性数组。

	flexible *f= (flexible* )malloc(sizeof(flexible) + 100*sizeof(int));

	/*
	    结构体的大小不包含柔性数组的大小，柔性数组只是在使用时将它作为结构体的一个成员，其	实它算不得结构体的正式成员。
	*/
	printf("%d\n", sizeof(flexible)); //4  
	printf("%d\n", sizeof(*f)); //4  
	
	system("pause");
	return 0;

}