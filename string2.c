#include "monty.h"
/**
 * to_st - to_st
 * @now: n
 * Return: st
 */
char *to_st(int now)
{
	char *st, *str;
	int i = 0, j;

	st = malloc(sizeof(char) * 20);
	while (now != 0)
	{
		st[i] = (now % 10) + '0';
		now /= 10;
		i++;
	}
	st[i] = '\0';
	str = malloc(sizeof(char) * 20);
	for (j = _strlen(st) - 1, i = 0; j >= 0; i++, j--)
		str[i] = st[j];
	str[i] = '\0';
	free(st);
	return (str);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * err - print error
 * @st: string
 * Return: void
 */
void err(char *st)
{
	write(2, st, _strlen(st));
}
