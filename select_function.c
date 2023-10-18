#include"monty.h"
/**
 * select - selrct the function required
 * @array: array of strings
 * @line_num: line number of the file
 */
void selectf(char **array, unsigned int line_num)
{
	int i = 0;
	char *line = tost(line_num);
	instruction_t arr[] = {
		{"push", push}, 
		{"pall", pall}
	};
	for (i = 0; i < 2; i++)
	{
		if (cmp(arr[i].opcode, array[0]))
		{
			arr[i].f(array, line_num);
			free(line);
			return;
		}
	}
	write(2, "L", 1);
	write(2, line, _strlen(line));
	write(2,": unknown instruction ", 22);
	write(2, array[0], _strlen(array[0]));
	write(2, "\n", 1);
	free(line);
	exit(EXIT_FAILURE);
}
