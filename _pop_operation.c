#include "monty.h"

/**
 * _pop_operation -This function helps remove element from the top
 * @_stack: parameter1
 * @_line_number: parameter2
 * Return: Void
 */
void _pop_operation(stack_t **_stack, unsigned int _line_number)
{
	stack_t *temp;

	if (*_stack == NULL)
	{
		fprintf(stderr, "L%d: cannot perform pop operation,the stack is empty\n"
, _line_number);
		exit(EXIT_FAILURE);
	}

	temp = *_stack;
	*_stack = (*_stack)->next;
	if (*_stack != NULL)
		(*_stack)->prev = NULL;
	free(temp);
}
