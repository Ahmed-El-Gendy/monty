#include"monty.h"
/**
 * select - selrct the function required
 * @array: array of strings
 * @line_num: line number of the file
 */
void selectf(stack_t **s, char *token, unsigned int line_num)
{
	int i = 0;
	char *line = to_st(line_num);
	instruction_t arr[] = {
		{"push", pushs}, 
		{"pall", palls}, 
		{"pint", pints}, 
		{"pop", pops}
	};
	for (i = 0; i < 4; i++)
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
	write(2,": unknown instruction ", 22);
	write(2, token, _strlen(token));
	write(2, "\n", 1);
	free(line);
	exit(EXIT_FAILURE);
}