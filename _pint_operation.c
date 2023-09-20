#include "monty.h"
/**
 * _pint_operation -This function print value from the top
 * @_stack: parameter1
 * @_line_number: parameter2
 * Return: Void
 */
void _pint_operation(stack_t **_stack, unsigned int _line_number)
{
	(void)_line_number;

	if (*_stack == NULL)
	{
		fprintf(stderr, "L%d: cannot perform pint, the stack empty\n", _line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*_stack)->n);
}
