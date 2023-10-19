#include "monty.h"
/**
 * pushs - push element
 * @stack: array of strings
 * @num: line number of the file
 */
void pushs(stack_t **stack, unsigned int num)
{
	stack_t *new;
	int k;
	char *l = to_st(num), *val;

	val = strtok(NULL, "\r\t\n ");
	if (!val)
	{
		write(2, "L", 1), write(2, l, _strlen(l));
		write(2, ": usage: push integer", _strlen(": usage: push integer"));
<<<<<<< HEAD
		write(2, "\n", 1);
		free(val);
		free(l);
		free_stack(*stack);
		exit(EXIT_FAILURE);
=======
		write(2, "\n", 1), free(l), exit(EXIT_FAILURE);
>>>>>>> 50b9c2b3999b8f3862accd3939012b455dc4d9fc
	}
	else if (!check(val))
	{
		write(2, "L", 1), write(2, l, _strlen(l));
		write(2, ": usage: push integer", _strlen(": usage: push integer"));
<<<<<<< HEAD
		write(2, "\n", 1);
		free(val);
		free(l);
		free_stack(*stack);
		exit(EXIT_FAILURE);
=======
		write(2, "\n", 1), free(l), exit(EXIT_FAILURE);
>>>>>>> 50b9c2b3999b8f3862accd3939012b455dc4d9fc
	}
	else
	{
		new = malloc(sizeof(stack_t));
		if (!new)
		{
			write(2, "Error: malloc failed", _strlen("Error: malloc failed"));
			write(2, "\n", 1), exit(EXIT_FAILURE);
		}
		k = _atoi(val), new->n = k;
		if (!(*stack))
			(*stack) = new, new->next = NULL;
		else
			new->next = (*stack), (*stack) = new;
	}
	free(l);
}
/**
 * len - len of array
 * @array: array
 * Return: int
 */
int len(char **array)
{
	int i = 0;

	while (array[i])
		i++;
	return (i);
}
/**
 * check - check integer
 * @st: string
 * Return: 1 if int 0 for non
 */
int check(char *st)
{
	int i = 0;

	for (i = 0; st[i]; i++)
	{
		if (st[i] == '-' && i == 0)
			continue;
		if (st[i] < '0' || st[i] > '9')
			return (0);
	}
	return (1);
}
