#include "main.h"
/**
 * specifer_check - check the validty of the printf secifier
 * and call the related function.
 * @spec: Specifier to be checked to determine return function.
 * Return: pinter to a function that returns( int) and takes a
 * (va_list) as arguments.
*/
specifier_handler specifer_check(char spec)
{
	if (spec != '\0')
	{
		int i;

		handler handlers[5] = {{'i', handle_int}, {'s', handle_str}, {'c', handle_char}, {'d', handle_dec}, {'\0', NULL}};

		for (i = 0; handlers[i].c != '\0'; i++)
		{
			if (handlers[i].c == spec)
			{
				return (handlers[i].handler_type);
			}
		}
		return (NULL);
	}
	return (NULL);
}

/**
 * _printf - Replication of the std printf
 * @input: string to be printed.
 * Return: no of chars printed.
*/
int _printf(const char *input, ...)
{
	specifier_handler handler;
	int count = 0, i = 0;
	va_list args;
	va_start(args, input);

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
			if (input[i] == '%')
			{
				count += handle_cent();
			} else
			{
				handler = specifer_check(input[i]);
				count += handler(args);
			}

			i++;
		}
	}
	va_end(args);
	return (count);
}
