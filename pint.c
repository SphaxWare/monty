#include "monty.h"
/**
 * pint - this function prints the value at the top of the stack.
 * @stack:ouble pointer to the stack.
 * @line_number: line number.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	int top;
	stack_t *tmp = *stack;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		return;
	}
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	top = tmp->n;
	printf("%d\n", top);
}
