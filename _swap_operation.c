#include "monty.h"

/**
 * _swap_operation -This function helps swap element value
 * @_stack: parameter1
 * @_line_number: parameter2
 * Return: Void
 */
void _swap_operation(stack_t **_stack, unsigned int _line_number)
{
	int temp;
	stack_t *_top, *_second;

	if (*_stack == NULL || (*_stack)->next == NULL)
	{
		fprintf(stderr, "L%d: cannot swap element, insufficient values\n",
_line_number);
		exit(EXIT_FAILURE);
	}

	_top = *_stack;
	_second = _top->next;

	temp = _top->n;
	_top->n = _second->n;
	_second->n = temp;
}
