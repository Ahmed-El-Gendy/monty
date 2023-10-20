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
	char *line = NULL, *token = NULL, *errr;
	unsigned int line_number = 0;
	FILE *file;
	size_t n = 0;
	int i;
	stack_t *head = NULL;

	if (argc != 2)
	{
		err("USAGE: ");
		errr = malloc(sizeof(char) * _strlen(argv[0]));
		for (i = 2; i < _strlen(argv[0]); i++)
			errr[i - 2] = argv[0][i];
		errr[i - 2] = '\0';
		err(errr), free(errr);
		err(" file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		err("Error: Can't open file "), err(argv[1]), err("\n");
		return (EXIT_FAILURE);
	}
	while ((getline(&line, &n, file) != -1))
	{
		line_number++;
		token = strtok(line, "\r\t\n ");
		if (!token)
			continue;
		if (token[0] == '#')
			continue;
		if (cmp(token, "queue"))
			continue;
		selectf(&head, token, line_number, line);
	}
	free(line);
	fclose(file);
	free_stack(head);
	return (EXIT_SUCCESS);
}
