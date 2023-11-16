#include "monty.h"

/**
 * push - pushes an item unto the stack
 * @stack: doubly linked list or stack
 * @line_number: line number
 * Definition - pushes an integer unto the stack
 * Return: void
*/

void push(stack_t **stack, unsigned int line_number)
{
	char *token;
	stack_t *iter;
	stack_t *new;
	int n_value;

	(void)line_number;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(NULL, " \t\n");
	n_value = atoi(token);

	new->next = NULL;
	new->prev = NULL;
	new->n = n_value;
	iter = *stack;
	if (iter == NULL)
		*stack = new;
	else
	{
		*stack = new;
		new->next = iter;
		iter->prev = new;
	}
}

/**
 * pall - prints items in a stack from top to bottom
 * @stack: stack to be printed
 * @line_number: line number
 * Definition - prints values in a stack
 * Return: void
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *iter;

	iter = *stack;
	(void)line_number;

	while (iter != NULL)
	{
		printf("%d\n", iter->n);
		iter = iter->next;
	}
}
