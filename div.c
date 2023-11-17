#include "monty.h"

/**
 * stack_div - div the first two elements of the stack
 * @stack: pointer to stack
 * @line_number: current line number
 * Definition - divides the second top element of the stack
 * by the top element of the stack.
 * Return: void
*/
void stack_div(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(fptr);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d:  division by zero\n", line_number);
		fclose(fptr);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
}
