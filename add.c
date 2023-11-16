#include "monty.h"

/**
 * add - adds the first two elements of the stack
 * @stack: pointer to stack
 * @line_number: current line number
 * Definition - adds the values of the first two elements in the stack,
 * stores sum in the second node
 * and deletes the first node
 * Return: void
*/

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *i;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
		line_number);
		exit(EXIT_FAILURE);
	}
	i = *stack;
	*stack = (*stack)->next;
	(*stack)->n += i->n;
	(*stack)->prev = NULL;
	free(i);
}
