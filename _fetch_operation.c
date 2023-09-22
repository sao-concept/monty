#include "monty.h"

/**
 * _fetch_operator_func -This function help to fetch
 * the operation to be carried out.
 * @_s: operator argument
 * Return: function pointer corresponding to the operator given
 */
void (*_fetch_operator_func(char *_s))(stack_t **, unsigned int)
{
instruction_t ops[] = {
{"push", _push_operation},
{"pall", _pall_operation},
{"pint", _pint_operation},
{"pop", _pop_operation},
{"swap", _swap_operation},
{"add", _add_operation},
{"nop", _nop_operation},
{"sub", _sub_operation},
{"sub", _div_operation},
{"sub", _mul_operation},
{"sub", _mod_operation},
{"pchar", _pchar_operation},
{"pstr", _pstr_operation},
{"rotl", _rotl_operation},
{"rotr", _rotr_operation},/* Add new functions here */
{NULL, NULL}
};
	int i = 0;

	while (ops[i].opcode != NULL)
	{
		if (_strcmp(ops[i].opcode, _s) == 0)
			return (ops[i].f);
		i++;
	}

	fprintf(stderr, "Error: Unknown instruction %s\n", _s);
	exit(EXIT_FAILURE);
}
