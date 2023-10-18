#include "monty.h"

/**
 * push - push elements to stack
 * @value: the value
 * Return: void
 */
void push(int value, int (*stack)[], int *top)
{
	if ((*top) < 1000 - 1)
	{
		(*stack)[++(*top)] = value;
	}
	else
	{
		printf("Error: Stack overflow\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - print all elements from stack
 * Return: void
 */
void pall(int stack[], int top)
{
	int i;

	for (i = top; i >= 0; i--)
	{
		printf("%d\n", stack[i]);
	}
}
