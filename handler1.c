#include "main.h"
/**
 * handle_char - function to handle char specifer
 * @args: variadic argument list.
 * Return: int
*/
int handle_char(va_list args)
{
	char s = (char)va_arg(args, int);

	if (s)
	{
		write(1, &s, 1);
		return (1);
	}
	return (0);
}

/**
 * handle_str - function to handle string specifer
 * @args: variadic argument list.
 * Return: int
*/
int handle_str(va_list args)
{
	char *s = va_arg(args, char*);
	int tmp = 0;

	if (s != NULL && s != (char *)0)
	{
		tmp += _printf(s);
		return (tmp);
	} else
	{
		tmp += _printf("(null)");
		return (tmp);
	}
}

/**
 * handle_cent - function to handle percent specifer
 * Return: int
*/
int handle_cent(void)
{
	write(1, "%", 1);
	return (1);
}

/**
 * handle_dec - function to handle decimal specifer
 * @args: variadic argument list.
 * Return: int
*/
int handle_dec(va_list args)
{
	return (handle_int(args));
}

/**
 * handle_int - function to handle integer specifer
 * @args: variadic argument list.
 * Return: int
*/
int handle_int(va_list args)
{
	int num = va_arg(args, int);
	char str[11];
	int tmp = 0;

	sprintf(str, "%d", num);
	tmp += _printf(str);

	return (tmp);
}
