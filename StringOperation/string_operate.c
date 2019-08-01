typedef unsigned int size_t;
#include <stdio.h>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS 1

char* my_strcpy(char *dst, const char *src)  //字符串拷贝函数
{
	assert(dst);
	assert(src);

	char *copyDst = dst;
	while (*copyDst++ = *src++);
	return dst;
}

size_t my_strlen(const char *str)  //字符串长度的函数
{
	assert(str);

	//方法1：
	/*
	const char *copyStr = str;
	size_t count = 0;
	while (*copyStr++)
	{
		count++;
	}
	return count;
	*/

	//方法二：仿照库文件实现
	const char *copyStr = str;
	while ( *copyStr++ );
	return ( copyStr - str - 1 );
}

char* my_strcat(char *dst, const char *src)  //字符串连接函数：连接两个字符串
{
	assert(dst);
	assert(src);

	char *copyDst = dst;

	while (*copyDst)
	{
		copyDst++;
	}

	while (*copyDst++ = *src++);
	return dst;
}

int my_strcmp(const char *str1,const char *str2)
{
	assert(str1);
	assert(str2);

	while (*str1 || *str2)
	{
		if (*str1 > *str2)
		{
			return 1;
		}
		else if (*str1 < *str2)
		{
			return -1;
		}
		str1++;
		str2++;
	}
	if (*str1 == 0 && *str2 == 0)
	{
		return 0;
	}
	if (*str1 == 0)
	{
		return -1;
	}
	return 1;
}

char* my_strchr(const char *str, char c)
{
	assert(str);

	while (*str)
	{
		if (*str == c)
		{
			return (char *)str;
		}
		str++;
	}
	return NULL;
}

char* my_strstr(const char *str1, const char *str2)
{
	assert(str1);
	assert(str2);

	const char *cp1 = NULL;
	const char *cp2 = NULL;

	while (*str1)
	{
		cp1 = str1;
		cp2 = str2;

		while ( *cp1 && *cp2 && (*cp1 == *cp2) )
		{
			cp1++;
			cp2++;
		}
		if (*cp2 == '\0')
		{
			return (char *)str1;
		}

		str1++;

	}
	return NULL;
}