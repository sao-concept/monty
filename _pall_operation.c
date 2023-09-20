#include "monty.h"
/**
 * _pall_operation -This function helps prints nodes data
 * @_stack: parameter1
 * @_line_number: parameter2
 * Return: Void
 */
void _pall_operation(stack_t **_stack, unsigned int _line_number)
{
	stack_t *temp;
	(void)_line_number;

	temp = *_stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
