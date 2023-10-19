#include "monty.h"
glob global = {NULL, NULL};
/**
 * main - the main function
 * @argc: argc
 * @argv: argv
 * Return: int
 */

int main(int argc, char **argv)
{
	char *token = NULL;
	unsigned int line_number = 0;
	size_t n = 0;
	stack_t *head = NULL;

	if (argc != 2)
	{
		err("Usage: "), err(argv[0]);
		fclose(global.file);
		return (EXIT_FAILURE);
	}
	global.file = fopen(argv[1], "r");
	if (global.file == NULL)
	{
		err("Error: Can't open file "), err(argv[1]);
		fclose(global.file);
		return (EXIT_FAILURE);
	}
	while ((getline(&(global.saged), &n, global.file) != -1))
	{
		line_number++;
		token = strtok(global.saged, "\r\t\n ");
		if (!token)
			continue;
		if (token[0] == '#')
			continue;
		selectf(&head, token, line_number);
	}
	free(global.saged), fclose(global.file);
	free_stack(head);
	return (EXIT_SUCCESS);
}
