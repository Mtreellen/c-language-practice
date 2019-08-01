/*
利用可变参数列表，模拟实现简单的printf函数功能。
*/

#include <stdio.h>
#include <stdarg.h>
#define _CRT_SECURE_NO_WARNINGS 1
void my_printf(const char *format, ...)
{
	va_list arg_ptr;
	va_start(arg_ptr, format);
	while (*format)
	{
		char ch = *format;

		if (ch == '%')
		{
			format++;
			ch = *format;
			switch (ch)
			{
			case 'c':
			{
						char c = va_arg(arg_ptr, char);
						putchar(c);
			}
				break;
			case 's':
			{
						char *str = va_arg(arg_ptr, char*);
						while (*str)
						{
							putchar(*str);
							str++;
						}
			}
				break;
			default:
				putchar(*(format - 1));
				putchar(ch);
				break;
			}
		}
		else
		{
			putchar(ch);
		}
		format++;
	}
}

int main()
{
	char ch = 'a';
	char *str = "hello";
	my_printf("%s\t%c\n", str, ch);

	return 0;
}