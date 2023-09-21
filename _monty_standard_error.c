#include "monty.h"
/**
 * print_error - This function helps to print error messages.
 * @_message: message parameter
 * @_line: line parameter
 * Return: Void
 */
void print_error(const char *_message, int _line)
{
fprintf(stderr, "L%d: %s\n", _line, _message);
}

/**
 * monty_error - This function helps to printy monty error.
 * @error: pointer to printed error
 * Return: Void
 */
void monty_error(const MontyError *error)
{
switch (error->error_code)
{
case MONTY_ERROR_INVALID_OPCODE:
print_error("unknown instruction", error->_line_number);
break;
case MONTY_ERROR_PUSH_MISSING_ARG:
case MONTY_ERROR_PUSH_INVALID_ARG:
print_error("usage push integer", error->_line_number);
break;
case MONTY_ERROR_POP_EMPTY:
print_error("can't pop an empty stack", error->_line_number);
break;
case MONTY_ERROR_PINT_EMPTY:
print_error("can't %s, stack empty", error->_line_number);
break;
default:
print_error("unknown error", error->_line_number);
}
}
