#include "monty.h"
/**
 * pop - this function prints the value at the top of the stack.
 * @stack:ouble pointer to the stack.
 * @line_number: line number.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->prev->next = NULL;
	tmp = tmp->prev;
}
