#include "monty.h"
/**
 * pint - print the top
 * @line: line numper
 * Return: void
 */
void pint(stack_t **stack, unsigned int line)
{
	char *c;

	if (head == NULL)
	{
		c = to_st(line);
		err("L"), err(c), err(": can't pint, stack empty\n");
		free(c);
		exit(EXIT_FAILURE);
	}
	printf("%d/n", (*stack)->n);
}

/**
 * pop - pop the top
 * @line: line numper
 * Return: void
 */
void pop(stack_t **stack, unsigned int line)
{
	char *c;
	stack_t *curr = *stack;

	if (*stack == NULL)
	{
		c = to_st(line);
		err("L"), err(c), err(": can't pop an empty stack\n");
		free(c);
		exit(EXIT_FAILURE);
	}
	curr->prev->next = NULL;
	free(curr);
}
/**
 * pall - print the stack
 * @line: line numper
 * Return: void
 */
void pall(stack_t **stack, unsigned int line)
{
	char *c;
	stack_t *curr = *stack;

	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->prev;
	}
}
/**
 * push - push
 * @value: value
 * @line: line
 * Return: void
 */
void push(stack_t **stack, unsigned int line)
{
	stack_t *node, *new;

	new = malloc(sizeof(stack_t));
	/*new->n = _atoi(value);
	new->next = NULL;
	node = *stack;
	*stack = new;
	new->prev = node;*/
}
