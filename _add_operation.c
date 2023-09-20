#include "monty.h"

/**
 * _add_operation -This function helps to adds the
 * value of the top two elements
 * @_stack: parameter1
 * @_line_number: parameter2
 * Return: Void
 */
void _add_operation(stack_t **_stack, unsigned int _line_number)
{
	int _sum;
	stack_t *_top, *_second;

	if (*_stack == NULL || (*_stack)->next == NULL)
	{
		fprintf(stderr, "L%d: cannot add elements, insufficient values\n",
_line_number);
		exit(EXIT_FAILURE);
	}

	_top = *_stack;
	_second = _top->next;

	_sum = _top->n + _second->n;

	/* Remove the top element */
	*_stack = _second;
	_second->prev = NULL;

	free(_top);

	/* Update the new top element with the sum */
	(*_stack)->n = _sum;
}
