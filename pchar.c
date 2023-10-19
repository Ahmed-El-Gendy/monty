#include"monty.h"
/**
 * pchar - p
 * @top: top
 * @line: line
 */
void pchar(stack_t **top, unsigned int line)
{
	char s, *st = to_st(line);
	if (*top)
	{
		s = (*top)->n;
		_putchar(s);
		_putchar('\n');
	}
	else
	{
		err("L"), err(st), err(": can't pchar, value out of range\n");
		exit(EXIT_FAILURE);
	}
	free(st);
}
