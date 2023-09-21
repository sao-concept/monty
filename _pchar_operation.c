#include "monty.h"

/**
 * _pchar_operation - This function prints the character
 * at the top of the stack
 * @_stack: The stack
 * @_line_number: The line number
 */
void _pchar_operation(stack_t **_stack, unsigned int _line_number)
{
int value;
	if (*_stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", _line_number);
		exit(EXIT_FAILURE);
	}
value = (*_stack)->n;

	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", _line_number);
		exit(EXIT_FAILURE);
	}

	putchar(value);
	putchar('\n');
}
