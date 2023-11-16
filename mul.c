#include "monty.h"

/**
 * stack_mul - multiplies the second top element of the stack
 * by the top element of the stack.
 * @stack: pointer to stack
 * @line_number: current line number
 * Return: void
 */
void stack_mul(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
}
