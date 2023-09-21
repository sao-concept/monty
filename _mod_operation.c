#include "monty.h"

/**
 * _mod_operation - This function calculates the modulo of the top two elements
 * @_stack: The stack
 * @_line_number: The line number
 */
void _mod_operation(stack_t **_stack, unsigned int _line_number)
{
	int modulo;
	stack_t *top, *second;

	if (*_stack == NULL || (*_stack)->next == NULL || (*_stack)->n == 0)
	{
		fprintf(stderr, "L%d: cannot mod elements, insufficient values
or modulo by zero\n", _line_number);
		exit(EXIT_FAILURE);
	}

	top = *_stack;
	second = top->next;

	modulo = second->n % top->n;

	*_stack = second;
	second->prev = NULL;

	free(top);

	(*_stack)->n = modulo;
}
