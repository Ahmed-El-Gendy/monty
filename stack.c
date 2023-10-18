#include "monty.h"

/**
 * main - the main function
 * @argc: argc
 * @argv: argv
 * Return: int
 */

int main(int argc, char *argv[])
{
	int *stack;
	char *line, *token;
	unsigned int line_number = 0;
	FILE *file;
	char **arr;
	ssize_t read, len = 0;

	stack = malloc(sizeof(int) * 1000);

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
		printf("%s\n", line);
		arr = malloc(sizeof(char *) * 10);
		line_number++;
		token = strtok(line, " \t\n");
		if (token == NULL)
			continue;
		arr[0] = token;
		token = strtok(NULL, " \t\n");
		value = token;
		selectf(arr, line_number);
	}
	fclose(file);
	free(stack), free(line);
	return (EXIT_SUCCESS);
}
