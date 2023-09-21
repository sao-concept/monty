#include "monty.h"
/**
 * main - This is the entry point for the Monty Interpreter
 * @argc: argument counter
 * @argv: argument strings
 * Return: EXIT_SUCCESS, otherwise EXIT_FAILURE
 */

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		return (EXIT_FAILURE);
	}

	return (_execute_monty(argv[1]));
}
