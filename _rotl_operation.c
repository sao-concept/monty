#include "monty.h"

/**
 * _rotl_operation - This function rotates the stack to the top
 * @_stack: The stack
 * @_line_number: The line number
 */
void _rotl_operation(stack_t **_stack, unsigned int _line_number)
{
stack_t *end;
	stack_t *top = *_stack;
	(void)_line_number;

if (top == NULL || top->next == NULL)
    /* Nothing to rotate */
return;

	/* move the top element to the end of the stack */
	*_stack = top->next;
	top->next->prev = NULL;

	/* find the end of the stack */
	end = top->next;
	while (end->next != NULL)
		end = end->next;

	/* connect the old top element to the end */
	end->next = top;
	top->prev = end;
	top->next = NULL;
}
