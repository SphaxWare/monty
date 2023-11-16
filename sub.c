#include "monty.h"

/**
 * sub - adds the first two elements of the stack
 * @stack: pointer to stack
 * @line_number: current line number
 * Definition - subtract the values of the top elements in the stack,
 * from the second top elment.
 * and deletes the first nodei
 * Return: void
*/
void sub(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
}
