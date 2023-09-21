#include "monty.h"

/**
 * _rotr_operation - This function rotates the stack to the bottom
 * @_stack: The stack
 * @_line_number: The line number
 */
void _rotr_operation(stack_t **_stack, unsigned int _line_number)
{
	stack_t *end = *_stack;
	(void)_line_number;

	if (end == NULL || end->next == NULL)
     /* nothing to rotate */
		return;

	/* find the end of the stack */
	while (end->next != NULL)
		end = end->next;

	/* move the end element to the top */
	end->prev->next = NULL;
	end->prev = NULL;
	end->next = *_stack;
	(*_stack)->prev = end;
	*_stack = end;
}
