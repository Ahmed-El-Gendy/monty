#include "monty.h"

/**
 * main - the main function
 * @argc: argc
 * @argv: argv
 * Return: int
 */

int main(int argc, char *argv[])
{
	char *line, *token;
	unsigned int line_number = 0;
	FILE *file;
	ssize_t read, len = 0;
	stack_t *head;

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
	while ((read = getline(&line, &len, file)) != -1)
	{
		
		line_number++;
		token = strtok(line, " \t\n");
		if (token == NULL)
			continue;
		selectf(head, token, line_number);
	}
	fclose(file);
	free(stack), free(line);
	return (EXIT_SUCCESS);
}
