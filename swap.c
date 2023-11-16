#include "monty.h"

/**
 * swap - swaps the first two elements of the stack
 * @stack: pointer to stack
 * @line_number: current line number
 * Definition - swaps the values of the first two nodes in the stack
 * Return: void
*/

void swap(stack_t **stack, unsigned int line_number)
{
	int swap_val;
	stack_t *stack_p = *stack;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(fptr);
		exit(EXIT_FAILURE);
	}
	swap_val = stack_p->n;
	stack_p->n = (stack_p->next)->n;
	(stack_p->next)->n = swap_val;
}

/**
 * stack_len - computes the number of elements in the stack
 * @stack: pointer to stack
 * Definition - computes number of elements in stack
 * Return: number of elements in stack
*/

int stack_len(stack_t *stack)
{
	const stack_t *i;
	int count;

	i = stack;
	count = 0;

	while (i != NULL)
	{
		count++;
		i = i->next;
	}
	return (count);
}
