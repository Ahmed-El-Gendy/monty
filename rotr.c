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

	line = line;
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
		temp2 = (*stack);
		while (temp1->next)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		temp2->next = NULL;
		temp1->next = (*stack);
		*stack = temp1;
	}
}


