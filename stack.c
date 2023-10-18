#include "monty.h"

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
	char **arr;


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
		arr = malloc(sizeof(char *) * 10);
		line_number++;
		token = strtok(line, " \t\n");
		if (token == NULL)
			continue;
		arr[0] = token;
		token = strtok(NULL, " \t\n");
		arr[1] = token;
		select(arr, line_number);
	}
	fclose(file);
	free(stack), free(line);
	return (EXIT_SUCCESS);
}
