#include "monty.h"

/**
 * _sub_operation - This function subtracts the value of the top two elements
 * @_stack: The stack
 * @_line_number: The line number
 */
void _sub_operation(stack_t **_stack, unsigned int _line_number)
{
	int diff;
	stack_t *top, *second;

	if (*_stack == NULL || (*_stack)->next == NULL)
	{
		fprintf(stderr, "L%d: cannot sub elements\n", _line_number);
		exit(EXIT_FAILURE);
	}

	top = *_stack;
	second = top->next;

	diff = second->n - top->n;

	*_stack = second;
	second->prev = NULL;

	free(top);

	(*_stack)->n = diff;
}
