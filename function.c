#include "monty.h"
/**
 * pint - print the top
 * @line: line numper
 * Return: void
 */
void pint(int line)
{
	char *c;

	if (head == NULL)
	{
		c = to_st(line);
		err("L"), err(c), err(": can't pint, stack empty\n");
		free(c);
		exit(EXIT_FAILURE);
	}
	printf("%d/n", (*head)->n);
}

/**
 * pop - pop the top
 * @line: line numper
 * Return: void
 */
void pop(int line)
{
	char *c;
	stack_t *curr = *head;

	if (head == NULL)
	{
		c = to_st(line);
		err("L"), err(c), err(": can't pop an empty stack\n");
		free(c);
		exit(EXIT_FAILURE);
	}
	curr->prev->next = NULL;
	free(current);
}
/**
 * pall - print the stack
 * @line: line numper
 * Return: void
 */
void pall(int line)
{
	char *c;
	stack_t *curr = *head;

	while (curr)
	{
		printf("%d\n", h->n);
		curr = curr->prev;
	}
}
