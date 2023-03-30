#include "main.h"
/**
 * handle_binary - function that convert unsigned int to binary
 * @args: varriadic argument list
 * Return: int
 */
int handle_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int tmp = 0;
	int j = 0;
	char binary[32];
	char temp;
	int i = 0;

	while (num > 0)
	{
		binary[i++] = (num % 2) + '0';
		num /= 2;
	}
	binary[i] = '\0';
	i--;

	while (j < i)
	{
		temp = binary[j];
		binary[j] = binary[i];
		binary[i] = temp;
		j++;
		i--;
	}
	tmp += _printf(binary);
	return (tmp);
}
