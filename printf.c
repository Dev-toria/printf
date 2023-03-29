#include "main.h"
/**
 * specifier-check - check the validty of the printf secifier
 * and call the related function.
 * @spec: Specifer to be checked to determine return function.
 * Return: pinter to a function that returns( int) and takes a
 * (va_list) as arguments.
*/
specifier_handler specifer_check(char spec)
{
	if (spec != '\0')
	{
		int i;

		handler int_handler = {'i',handle_int};
		handler str_handler = {'s', handle_str};
		handler char_handler = {'c', handle_char};
		handler cent_handler = {'%', handle_cent};
		handler dec_handler = {'d', handle_dec};
		handler null_handler = {'\0', NULL};

		handler handlers[] = {char_handler, str_handler, cent_handler, dec_handler, int_handler, null_handler};
		for(i = 0; handlers[i].c != '\0'; i++)
		{
			if (handlers[i].c == spec)
			{
				return (handlers[i].handler_type);
			}
		}
		return (NULL);
	}
}

/**
 * _printf - Replication of the std printf
 * @input: string to be printed.
 * Return: no of chars printed.
*/
int _printf (const char *input, ...)
{
	int count = 0, i = 0;
	va_list args;
	va_start(args, input);
	specifier_handler handler;

	while (input[i])
	{
		if (input[i] != '%')
		{
			count += write(1, &input[i], 1);
			i++;
		}
		if (input[i] == '%')
		{
			i++;
			handler = specifer_check(input[i]);
			count += handler(args);
			i++;
		}
	}
	va_end(args);
	return (count);
}
