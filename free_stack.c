#include "monty.h"

/**
 * free_stack - frees the stack
 * @head: pointer to first node in stack
 * Description - frees stack in form of a doubly linked list
 * Return: void
*/

void free_stack(stack_t *head)
{
	stack_t *iter;
	stack_t *store_next;

	iter = head;
	while (iter != NULL)
	{
		store_next = iter->next;
		free(iter);
		iter = store_next;
	}
}
