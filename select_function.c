#include"monty.h"
/**
 * selectf - selrct the function required
 * @s: array of strings
 * @line_num: line number of the file
 * @token: tok
 */
void selectf(stack_t **s, char *token, unsigned int line_num)
{
	int i = 0;
	char *line = to_st(line_num);
	instruction_t arr[] = {
<<<<<<< HEAD
	{"push", pushs},
	{"pall", palls},
	{"pint", pints},
	{"pop", pops}
=======
		{"push", pushs}, 
		{"pall", palls}, 
		{"pint", pints}, 
		{"pop", pops}, 
		{"nop", nops} 
>>>>>>> c412f43a80db98886e2ebc6fa0023c0b86cc485d
	};
	for (i = 0; i < 5; i++)
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
	write(2, ": unknown instruction ", 22);
	write(2, token, _strlen(token));
	write(2, "\n", 1);
	free(line);
	exit(EXIT_FAILURE);
}
