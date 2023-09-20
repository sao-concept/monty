#include "monty.h"
/**
 * _execute_monty - Execute Monty bytecode instructions from a file
 * @_filename: The name of the Monty script file
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
char *_operand;
int _execute_monty(const char *_filename)
{
	stack_t *_stack = NULL;
	line_t *_lines;
	char *_content, **_line;
	void (*_func)(stack_t **, unsigned int);
	int _line_number = 1;

	_lines = _text_file_reader(_filename);
	if (!_lines)
	{
		fprintf(stderr, "Error: Cannot open this file %s\n", _filename);
		return (EXIT_FAILURE);
	}
	while (_lines[_line_number - 1]._content)
	{
		_content = _lines[_line_number - 1]._content;
		_line = _line_spliter(_content);

		if (!_line || !_line[0])
		{
			fprintf(stderr, "Error: memory allocation failed\n");
			_free_used_stack(_stack);
			_free_used_lines(_lines);
			return (EXIT_FAILURE);
		}
		 _operand = _line[1];
		_func = _fetch_operator_func(_line[0]);

		if (!_func)
		{
			fprintf(stderr, "L%d: instruction not known %s\n", _line_number, _line[0]);
			free(_line);
			_free_used_stack(_stack);
			_free_used_lines(_lines);
			return (EXIT_FAILURE);
		}
		_func(&_stack, _line_number++);
		free(_line);
	}
	_free_used_stack(_stack);
	_free_used_lines(_lines);
	return (EXIT_SUCCESS);
}
