#include "monty.h"
/**
 * palls - print all stack
 * @head: address of the head
 * @line_number: line number
 */
void palls(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;
	char *st;

	line_number = line_number;
	while (temp != NULL)
	{
		st = to_st(temp->n);
		write(1, st, _strlen(st));
		write(1, "\n", 1);
		free(st);
		temp = temp->next;
	}
}
