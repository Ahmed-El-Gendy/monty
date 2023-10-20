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
 * @stack: head
 * @line_num: int
 */
void swap(stack_t **stack, unsigned int line_num)
{
	char *st = to_st(line_num);
	stack_t *temp, *temp2;

	if (len_stack(stack) < 2)
	{
		err("L"), err(st), err(": can't swap, stack too short\n");
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
/**
 * add - add 2 elements
 * @stack: head
 * @line_num: int
 */
void add(stack_t **stack, unsigned int line_num)
{
	char *st = to_st(line_num);
	stack_t *temp2;

	if (len_stack(stack) < 2)
	{
		err("L"), err(st), err(": can't add, stack too short\n");
		free(st);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	free(st);
	temp2 = (*stack)->next;
	temp2->n += (*stack)->n;
	free(*stack);
	*stack = temp2;
}

/**
 * pstr - print string
 * @stack: head
 * @line_num: num
 */
void pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *h = *stack;
	int i = line_num;
	char c;

	while (h)
	{
		if (h->n > 0 && h->n <= 127)
		{
			c = h->n;
			_putchar(c);
		}
		else
			break;
		h = h->next;
	}
	_putchar('\n');
}
