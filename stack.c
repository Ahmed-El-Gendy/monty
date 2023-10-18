#include "monty.h"
#define STACK_SIZE 1000
#define MAX_LINE_LENGTH 100

/**
 * main - the main function
 * @argc: argc
 * @argv: argv
 * Return: int
 */

int main(int argc, char *argv[])
{
	int *stack, top = -1;
	char *line, *token;
	int line_number = 0;
	FILE *file;

	stack = malloc(sizeof(int) * 1000);
	line = malloc(sizeof(char) * 100);

	if (argc != 2)
	{
		err("Usage: "), err(argv[0]);
		free(stack), free(line);
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		err("Error: Can't open file "), err(argv[1]);
		free(stack), free(line);
		return (EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		token = strtok(line, " \t\n");
		if (token == NULL)
			continue;
		if (cmp(token, "push") == 1)
		{
			token = strtok(NULL, " \t\n");
			if (token == NULL)
			{
				err("L"), err(to_st(line_number)), err(": usage: push integer\n");
				free(stack), free(line);
				return (EXIT_FAILURE);
			}
			push(atoi(token), &stack, &top);
		}
		else if ((cmp(token, "pall") == 1) || (cmp(token, "pall$") == 1))
		{
			pall(stack, top);
		}
		else
		{
			err("L"), err(to_st(line_number)), err("d: unknown instruction ");
			err(token), err("\n");
			free(stack), free(line);
			return (EXIT_FAILURE);
		}
	}
	fclose(file);
	free(stack), free(line);
	return (EXIT_SUCCESS);
}
