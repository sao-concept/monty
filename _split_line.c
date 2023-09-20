#include "monty.h"
/**
 * _line_spliter - This function helps to breakdown strings.
 * @_line: pointer to broken strings
 * Return: pointer to strings
 */
#define TOKEN_DELIMETER " \t\r\n\a"

char **_line_spliter(char *_line)
{
	int position = 0;
	char **_tokens = NULL;
	char *_token;

	if (_line == NULL)
		return (NULL);
	_token = strtok(_line, TOKEN_DELIMETER);

	while (_token != NULL)
	{
		char **tmp = realloc(_tokens, sizeof(char *) * (position + 1));

		if (tmp == NULL)
		{
			fprintf(stderr, "Error: allocation error\n");
			exit(EXIT_FAILURE);
		}
		_tokens = tmp;
		_tokens[position] = strdup(_token);
		if (_tokens[position] == NULL)
		{
			fprintf(stderr, "Error: error allocation\n");
			exit(EXIT_FAILURE);
		}
		_token = strtok(NULL, TOKEN_DELIMETER);
		position++;
	}
	_tokens[position] = NULL;
	return (_tokens);
}
