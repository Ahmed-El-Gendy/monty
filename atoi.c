#include "monty.h"
/**
* _atoi - Convert string to an integer.
* @string: Pointer to a character string.
*
* Return: void.
*/

int _atoi(char *string)
{
	int sign = 1;
	unsigned int number = 0;
	char *final = string;

	if (*final == '-')
	{
		sign = -1;
		final++;
	}

	while (*final >= '0' && *final <= '9')
	{
		number = number * 10 + (*final - '0');
		final++;
	}

	return (number * sign);
}
