#include "monty.h"
/**
 * mul - mul
 * @stack: stack
 * line_num: num
 */
void mul(stack_t **stack, unsigned int line_num)
{
	char *st = to_st(line_num);
	stack_t *temp2;

	if (len_stack(stack) < 2)
	{
		err("L"), err(st), err(": can't mul, stack too short\n");
		free(st);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	free(st);
	temp2 = (*stack)->next;
	temp2->n *= (*stack)->n;
	free(*stack);
	*stack = temp2;
}

/**
 * divs - div 2 elements
 * @stack: head
 * @line_num: int
 */
void divs(stack_t **stack, unsigned int line_num)
{
	char *st = to_st(line_num);
	stack_t *temp2;

	if (len_stack(stack) < 2)
	{
		err("L"), err(st), err(": can't div, stack too short\n");
		free(st);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		err("L"), err(st), err(": division by zero\n");
		free(st), free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	free(st);
	temp2 = (*stack)->next;
	temp2->n /= (*stack)->n;
	free(*stack);
	*stack = temp2;
}
