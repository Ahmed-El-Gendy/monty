#include <stdio.h>
#include "monty.h"

/**
 * main - the main function
 * @argc: argc
 * @argv: argv
 * Return: int
 */

int main(int argc, char *argv[])
{
	char *line = NULL, *token = NULL;
	unsigned int line_number = 0;
	FILE *file;
	unsigned long int read, len = 0;
	stack_t *head = NULL;

	if (argc != 2)
	{
		err("Usage: "), err(argv[0]);
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		err("Error: Can't open file "), err(argv[1]);
		return (EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		token = strtok(line, "\r\t\n ");
		if (!token)
			continue;
		selectf(&head, token, line_number);
	}
	free(line);
	fclose(file);
	free_stack(head);
	return (EXIT_SUCCESS);
}
