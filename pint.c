#include "monty.h"
/**
 * pints - print the top
 * @top: top
 * @line: line number
 */
void pints(stack_t **top, unsigned int line)
{
	char *st = to_st(line);

	if (!(*top))
	{
		write(2, "L", 1);
		write(2, st, _strlen(st));
		write(2, ": can't pint, stack empty\n", 26);
		free(st);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	free(st);
	st = NULL;
	st = to_st((*top)->n);
	write(1, st, _strlen(st));
	write(1, "\n", 1);
	free(st);
}
