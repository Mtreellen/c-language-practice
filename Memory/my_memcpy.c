#include <stdio.h>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS 1

void *my_memcpy( void *dest, const void *src, size_t count )
{
	void *ret = dest;
	while(count--)
	{
		*((char*)dest)++ = *((char*)src)++;
	}
	return ret;
}


int main()
{
	char arr1[] = "abcde";
	char arr2[6] = "";
	my_memcpy(arr2, arr1, sizeof(arr1));
	printf("%s", arr2);
	system("pause");
	return 0;
}