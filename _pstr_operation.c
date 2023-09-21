#include "monty.h"

/**
 * _pstr_operation - This function prints the string starting
 * at the top of the stack
 * @_stack: The stack
 * @_line_number: The line number
 */
void _pstr_operation(stack_t **_stack, unsigned int _line_number)
{
	stack_t *current = *_stack;
	(void)_line_number;

	while (current != NULL && current->n != 0)
	{
		if (current->n < 0 || current->n > 127)
			break;

		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}
