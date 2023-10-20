#include"monty.h"
/**
 * pops - pop top
 * @top: top
 * @line: line number
 */
void pops(stack_t **top, unsigned int line)
{
	char *st = to_st(line);
	stack_t *temp;

	if (!(*top))
	{
		write(2, "L", 1);
		write(2, st, _strlen(st));
		write(2, ": can't pop an empty stack\n", 27);
		free(st);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	free(st);
	temp = *top;
	*top = (*top)->next;
	free(temp);
}
