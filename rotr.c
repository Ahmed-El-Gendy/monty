#include"monty.h"
/**
 * rotr - rotate
 * @stack: top
 * @line: line number
 */
void rotr(stack_t **stack, unsigned int line)
{
	stack_t *temp1, *temp2;
	int i = 0;

	if (*stack)
	{
		temp1 = *stack;
		while (temp1)
		{
			i++;
			temp1 = temp1->next;
		}
		if (i == 1)
			return;
		temp1 = (*stack)->next;
		temp2 = NULL;
		while (temp1)
		{
			(*stack)->next = temp2;
			temp2 = *stack;
			*stack = temp1;
			temp1 = temp1->next;
		}
		(*stack)->next = temp2;
	}
}


