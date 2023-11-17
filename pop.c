#include "monty.h"
/**
 * pop - this function prints the value at the top of the stack.
 * @stack:ouble pointer to the stack.
 * @line_number: line number.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(fptr);
		free_stack(*stack);
		*stack = NULL;
		exit(EXIT_FAILURE);
	}
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	else
		free(tmp);
}
