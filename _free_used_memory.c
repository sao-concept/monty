#include "monty.h"

/**
 * _free_used_stack -This function help to free the stack use
 * @head: pointer to linked-list head
 */
void _free_used_stack(stack_t *head)
{
	stack_t *current = head;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
