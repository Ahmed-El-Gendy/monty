#include"monty.h"
/**
 * mods - mod
 * @stack: top
 * @line_num: line
 */
void mods(stack_t **stack, unsigned int line_num)
{
        char *st = to_st(line_num);
        stack_t *temp2;

        if (len_stack(stack) < 2)
        {
                err("L"), err(st), err(": can't mod, stack too short\n");
                free(st);
                free_stack(*stack);
                exit(EXIT_FAILURE);
        }
	if ((*stack)->n == 0)
	{
		err("L"), err(st), err(": division by zero");
		free(st);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
        free(st);
        temp2 = (*stack)->next;
        temp2->n = temp2->n % (*stack)->n;
        free(*stack);
        *stack = temp2;
}

