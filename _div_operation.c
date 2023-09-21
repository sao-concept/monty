#include "monty.h"
/**
 * _div_operation - This function divides the top two elements
 * @_stack: The stack
 * @_line_number: The line number
 */
void _div_operation(stack_t **_stack, unsigned int _line_number)
{
	int result;
	stack_t *top, *second;

	if (*_stack == NULL || (*_stack)->next == NULL || (*_stack)->n == 0)
	{
		fprintf(stderr, "L%d: cannot div elements\n", _line_number);
		exit(EXIT_FAILURE);
	}

	top = *_stack;
	second = top->next;

	result = second->n / top->n;

	*_stack = second;
	second->prev = NULL;

	free(top);

	(*_stack)->n = result;
}
