#include "monty.h"

/**
 * pint - this function prints the value at the top of the stack.
 * @stack: pointer to the stack.
 * @line_number: line number.
 * Description - prints the integer value at the top of the stack.
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		return;
	}
	printf("%d\n", (*stack)->n);
}
