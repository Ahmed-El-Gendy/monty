#include "monty.h"
#include<stdio.h>
/**
 * main - the main function
 * @argc: argc
 * @argv: argv
 * Return: int
 */

int main(int argc, char *argv[])
{
	char *line, *token = NULL;
	unsigned int line_number = 0;
	FILE *file;
	stack_t *head = NULL;
	size_t bufsize = 1000;

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
	while ((getline(&line, &bufsize, file)) != -1)
	{
		line_number++;
		token = strtok(line, "\r\t\n ");
		if (!token)
			continue;
		selectf(&head, token, line_number);
	}
	fclose(file);
	free_stack(head);
	free(line);
	return (EXIT_SUCCESS);
}
