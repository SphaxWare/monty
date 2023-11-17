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

	token = strtok(NULL, " \t\n");
	if (!token || (check_if_integer(token) == 0))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		*stack = NULL;
		/*
		 * All memory leaks have been handled except what happens here
		 * when the program exits without closing the file. Needs
		 * pointer to file or a way to communicate to main to close the
		 * file. Should we make use of child processes?
		 */
		fclose(fptr);
		exit(EXIT_FAILURE);
	}
	n_value = atoi(token);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(fptr);
		exit(EXIT_FAILURE);
	}
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

/**
 * check_if_integer - checks if a string can be converted to an integer
 * @str: string to be checked
 * Description - checks if a string contains non-digit characters
 * Return: 1, if string can be converted to integer, 0 if not.
*/

int check_if_integer(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}
