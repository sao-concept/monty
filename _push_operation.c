#include "monty.h"

/**
 * _push_operation -This function help to push elements to stack
 * @_stack: parameter1
 * @_line_number: parameter2
 * Return: Void
 */
void _push_operation(stack_t **_stack, unsigned int _line_number)
{
	stack_t *new;
	int n;

	if (_operand == NULL || _atoi(_operand, &n) == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", _line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc operation failed\n");
		_free_used_stack(*_stack);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	new->next = *_stack;

	if (*_stack != NULL)
		(*_stack)->prev = new;

	*_stack = new;
}
