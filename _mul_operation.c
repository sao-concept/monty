#include "monty.h"

/**
 * _mul_operation - This function multiplies the top two elements
 * @_stack: The stack
 * @_line_number: The line number
 */
void _mul_operation(stack_t **_stack, unsigned int _line_number)
{
	int product;
	stack_t *top, *second;

	if (*_stack == NULL || (*_stack)->next == NULL)
	{
		fprintf(stderr, "L%d: cannot mul elements\n", _line_number);
		exit(EXIT_FAILURE);
	}

	top = *_stack;
	second = top->next;

	product = second->n * top->n;

	*_stack = second;
	second->prev = NULL;

	free(top);

	(*_stack)->n = product;
}
