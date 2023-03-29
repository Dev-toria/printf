#include "main.h"
/**
 * handle_char - function to handle char specifer
 * 
*/
int handle_char(va_list args)
{
	char s = va_arg(args, int);

	write(1, &s, 1);

	return (1);
}

/**
 * handle_str - function to handle string specifer
 * 
*/
int handle_str(va_list args)
{
	char *s = va_arg(args, char*);
	int tmp = 0;
	
	tmp += _printf(s);

	return (tmp);
}

/**
 * handle_cent - function to handle percent specifer
 * 
*/
int handle_cent(va_list args)
{
	write(1, "%", 1);
	return (1);
}

/**
 * handle_dec - function to handle decimal specifer
 * 
*/
int handle_dec(va_list args)
{
	int num = va_arg(args, int);
	char str[11];
	sprintf(str, "%d", num);
	int tmp = 0;
	
	tmp += _printf(str);

	return (tmp);
}

/**
 * handle_int - function to handle integer specifer
 * 
*/
int handle_int(va_list args)
{
	int num = va_arg(args, int);
	char str[11];
	sprintf(str, "%d", num);
	int tmp = 0;
	
	tmp += _printf(str);

	return (tmp);
}