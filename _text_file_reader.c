#include "monty.h"
/**
 * _text_file_reader - This function reads text file
 * @_filename: file pointer
 * Return: a pointer
 */
line_t *_text_file_reader(const char *_filename)
{
	FILE *_file;
	char *_lineBuffer = NULL;
	size_t _size = 0;
	int _lineNumber = 0;
	line_t *_lines = NULL;

	if (_filename == NULL)
		return (NULL);
	_file = fopen(_filename, "r");
	if (_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", _filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&_lineBuffer, &_size, _file) != -1)
	{
		line_t *tmp = realloc(_lines, sizeof(line_t) * (_lineNumber + 1));

		if (tmp == NULL)
		{
			fclose(_file);
			free(_lineBuffer);
			free(_lines);
			return (NULL);
		}
		_lines = tmp;
		_lines[_lineNumber]._content = strdup(_lineBuffer);
		_lines[_lineNumber].number = _lineNumber;
		_lineNumber++;
	}
	free(_lineBuffer);
	fclose(_file);
	return (_lines);
}
