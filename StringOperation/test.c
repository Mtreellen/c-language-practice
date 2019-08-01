#include <stdio.h>
#include <stdlib.h>
#include <windos.h>
#define _CRT_SECURE_NO_WARNINGS 1

extern char* my_strcpy(char *dst, const char *src);
extern size_t my_strlen(const char *str);
extern char* my_strcat(char *dst, const char *src);
extern int my_strcmp(const char *str1, const char *str2);
extern char* my_strchr(const char *str, char c);
extern char* my_strstr(const char *str1, const char *str2);


void Test_strcpy()
{
	char str1[] = "abcde";
	char str2[10] = "";

	my_strcpy(str2, str1);
	printf("%s\n", str1);
	printf("%s\n", str2);
}

void Test_strlen()
{
	char str1[] = "abcde\0";
	char str2[] = "abcde\0abc";
	char str3[] = "abcde'0'";
	char str4[] = "abcde0";

	printf("%d\n", my_strlen(str1));//5
	printf("%d\n", my_strlen(str2));//5
	printf("%d\n", my_strlen(str3));//8
	printf("%d\n", my_strlen(str4));//6

}

void Test_strcat()
{
	char str1[10] = "abc";
	char str2[] = "def";
	my_strcat(str1, str2);

	printf("%s\n", str1);
}

void Test_strcmp()
{
	char str1[] = "abcd";
	char str2[] = "abcd";
	char str3[] = "abce";
	char str4[] = "abcde";


	printf("%d\n", my_strcmp(str1, str2));
	printf("%d\n", my_strcmp(str1, str3));
	printf("%d\n", my_strcmp(str3, str1));
	printf("%d\n", my_strcmp(str1, str4));
	printf("%d\n", my_strcmp(str4, str1));

}

void Test_strchr()
{
	char ch = 'c';
	char str1[] = "abcd";
	char str2[] = "abde";

	printf("%s\n", my_strchr(str1, ch));
	printf("%s\n", my_strchr(str2, ch));

}

void Test_strstr()
{
	char str1[] = "cbcdabce";
	char str2[] = "bce";


	printf("%s\n", my_strstr(str1, str2));
	printf("%s\n", my_strstr(str2, str1));


}
int main()
{
//	Test_strcpy();
//	Test_strlen();
//	Test_strcat();
//	Test_strcmp();
//	Test_strchr();
	Test_strstr();
	
	system("pause");
	return 0;
}