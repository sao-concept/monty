#include "monty.h"
/**
 * _atoi - convert a string to an integer.
 * @s: char type string
 * @n: pointer to the converted int
 * Return: 0 on success, -1 on failure
 */
int _atoi(char *s, int *n)
{
	int idx, _resp = 0, _first_num, _sign = 1;

	if (s == NULL || n == NULL)
		return (-1);

	for (_first_num = 0; !(s[_first_num] >= '0'
&& s[_first_num] <= '9'); _first_num++)
	{
		if (s[_first_num] == '-')
		{
			_sign *= -1;
		}
	}

	for (idx = _first_num; s[idx] ; idx++)
	{
		if (s[idx] >= '0' && s[idx] <= '9')
		{
			_resp *= 10;
			_resp += (s[idx] - '0');
		}
		else
			return (-1);
	}

	*n = _resp * _sign;
	return (0);
}
