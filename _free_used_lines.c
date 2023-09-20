#include "monty.h"
/**
 * _free_used_lines -This function help to free the line used
 * @_lines: pointer to line frees
 */
void _free_used_lines(line_t *_lines)
{
	int idx = 0;

	while (_lines[idx]._content != NULL)
	{
		free(_lines[idx]._content);
		idx++;
	}
	free(_lines);
}
