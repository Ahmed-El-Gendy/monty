#include "monty.h"
/**
 * len_stack - the length of the stack
 * @head: the head
 * Return: int
 */
int len_stack(stack_t **head)
{
	stack_t *h = *head;
	int i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * swap - swap
 * @head: head
 * @line_num: int
 */
void swap(stack_t **stack, unsigned int line_num)
{
	char *st = to_st(line);
	stack_t *temp, *temp2;

	if (len_stack(stack) < 2)
	{
		err("L"), err(st), err(": can't add, stack too short\n");
		free(st);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	free(st);
	temp2 = (*stack)->next;
	temp = (*stack)->next->next;
	(*stack)->next->next = (*stack);
	(*stack)->next = temp;
	*stack = temp2;
}
