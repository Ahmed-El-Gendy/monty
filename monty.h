#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void mods(stack_t **stack, unsigned int line_num);
void divs(stack_t **stack, unsigned int line_num);
void mul(stack_t **stack, unsigned int line_num);
void add(stack_t **stack, unsigned int line_num);
int len_stack(stack_t **head);
void swap(stack_t **stack, unsigned int line_num);
void pushs(stack_t **stack, unsigned int line);
void pint(int line);
void pop(int line);
void palls(stack_t **stack, unsigned int line);
char *to_st(int now);
int _strlen(char *s);
int _putchar(char c);
void _puts(char *str);
int cmp(char *input1, char *input2);
void err(char *st);
int _atoi(char *string);
void selectf(stack_t **st, char *token, unsigned int line_num, char *li, FILE *file);
int len(char **array);
int check(char *st);
void free_stack(stack_t *stack);
void free_input(void);
void pints(stack_t **top, unsigned int line);
void pops(stack_t **top, unsigned int line);
void nops(stack_t **top, unsigned int line);
void sub(stack_t **stack, unsigned int line_num);


#endif
