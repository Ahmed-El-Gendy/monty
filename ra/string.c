#include "monty.h"
/**
 * _strlen - count the length og the string
 * @s:  is the string that will use for the argument of the function
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i;
	int cnt = 0;

	for (i = 0;; i++)
	{
		if (s[i] == '\0')
		{
			break;
		}
		cnt++;
	}
	return (cnt);
}
/**
 * _puts - function that prints a string, followed by a new line
 * @str:  is the string that will use for the argument of the function
 * Return: NULL
 */
void _puts(char *str)
{
	size_t i;

	for (i = 0;; i++)
	{
		if (str[i] == '\0')
		{
			break;
		}
		_putchar(str[i]);
	}
}
/**
 * rep - remove the "\n"
 * @input: the input
 * Return: 1 if true 0 if false
 */
int rep(char *input)
{
	int i;

	for (i = 0; input[i] != '\n'; i++)
		;
	input[i] = '\0';
	if (_strlen(input) == 0)
		return (1);
	return (0);
}
/**
 * cmp - compare between tow strings
 * @input1: first string
 * @input2: second string
 * Return: 1 if they equal 0 if not
 */
int cmp(char *input1, char *input2)
{
	int i;

	if (_strlen(input1) != _strlen(input2))
		return (0);
	for (i = 0; input1[i] != '\0'; i++)
	{
		if (input1[i] != input2[i])
			return (0);
	}
	return (1);
}
/**
 * print_int - Print integer using putchar
 * @n: The numper
 * Return: void
 */
void print_int(int n)
{
	int x = 1;

	while (n / x)
	{
		x *= 10;
	}
	x /= 10;
	while (x)
	{
		_putchar((n / x) % 10 + '0');
		x /= 10;
	}
	_putchar(':');
	_putchar(' ');
}
