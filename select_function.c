#include"monty.h"
/**
 * selectf - select the function required
 * @s: array of strings
 * @token: string
 * @li: int
 * @line_num: line number of the file
 */
void selectf(stack_t **s, char *token, unsigned int line_num, char *li)
{
	int i = 0;
	char *line = to_st(line_num);

	instruction_t arr[] = {
		{"push", pushs},
		{"pall", palls},
		{"pint", pints},
		{"pop", pops},
		{"swap", swap},
		{"add", add},
		{"nop", nops},
		{"sub", sub},
		{"mul", mul},
		{"div", divs},
		{"mod", mods}
	};

	for (i = 0; i < 11; i++)
	{
		if (cmp(arr[i].opcode, token))
		{
			arr[i].f(s, line_num);
			free(line);
			return;
		}
	}
	write(2, "L", 1);
	write(2, line, _strlen(line));
	write(2, ": unknown  instruction ", 22);
	write(2, token, _strlen(token));
	write(2, "\n", 1);
	free(li);
	free_stack(*s);
	free(line);
	exit(EXIT_FAILURE);
}
