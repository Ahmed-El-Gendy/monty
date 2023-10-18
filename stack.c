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
	int stack[STACK_SIZE], top = -1;
	char line[MAX_LINE_LENGTH], *token;
	int line_number = 0;
	FILE *file;

	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
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
				printf("L%d: usage: push integer\n", line_number);
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
			printf("L%d: unknown instruction %s\n", line_number, token);
			return (EXIT_FAILURE);
		}
	}
	fclose(file);
	return (EXIT_SUCCESS);
}
