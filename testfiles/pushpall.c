#include "monty.h"

/**
 * push - this function push an int on top of the stack
 * @stack:ouble pointer to the stack.
 * @line_number: line number.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *token;

	token = strtok(NULL, " \t\n"); /*convert this with atoi*/
	(void)token;
	(void)stack;
	(void)line_number;
}

/**
 * pall - this function push an int on top of the stack
 * @stack:ouble pointer to the stack.
 * @line_number: line number.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
