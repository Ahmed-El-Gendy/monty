#include "main.h"
/**
* _atoi - Convert string to an integer.
* @string: Pointer to a character string.
*
* Return: void.
*/

int _atoi(char *string)
{
	int sign;
	unsigned int number;
	char *final;

	final = s;
	number = 0;
	sign = 1;
	while (*final != '\0' && (*final < '0' || *final > '9'))
	{
		if (*final == '-')
			sign *= -1;
		final++;
	}
	if (*final != '\0')
	{
		do {
			number = number * 10 + (*final - '0');
			final++;
		} while (*final >= '0' && *final <= '9');
	}
	return (number * sign);
}
