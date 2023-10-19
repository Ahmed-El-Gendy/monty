#include "monty.h"
void free_stack(stack_t *stack);
glob global = {NULL, NULL};
/**
 * free_stack - free
 * @stack: top
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
