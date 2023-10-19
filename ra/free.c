#include "monty.h"
/**
 * free_stack - free
 * @stack: top
 */
void free_stack(stack_t *stack)
{
	stack_t *temp = stack->next;

	while (temp)
	{
		free(stack);
		stack = temp;
		temp = temp->next;
	}
	free(stack);
}
