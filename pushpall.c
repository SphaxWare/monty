#include "monty.h"

/**
 * push - this function push an int on top of the stack
 * @stack:ouble pointer to the stack.
 * @line_number: line number.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *token;

	token = strtok(NULL, " \t\n");
	printf("from push :%s\n", token);
	(void)stack;
	(void)line_number;
}

void pall(stack_t **stack, unsigned int line_number)
{
	printf("from pall : print all values on the stack\n");
	(void)stack;
	(void)line_number;
}
