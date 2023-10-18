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
	printf("%d/n", head->n);
}

/**
 * pop - pop the top
 * @line: line numper
 * Return: void
 */
void pop(int line)
{
	char *c;
	stack_t *curr = head;

	if (head == NULL)
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
	stack_t *curr = head;

	*stack = head;

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

	*stack = head;
	new = malloc(sizeof(stack_t));
	new->n = _atoi(value);
	new->next = NULL;
	node = head;
	head = new;
	new->prev = node;
}
