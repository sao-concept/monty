#ifndef _MONTY_H_
#define _MONTY_H_
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char *_operand;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct line_s - line content and its number
 * @_content: line content
 * @number: line number
 *
 * Description: stores line of the monty source code
 */
typedef struct line_s
{
	char *_content;
	int number;
} line_t;



int _execute_monty(const char *_filename);
line_t *_text_file_reader(const char *_filename);
char **_line_spliter(char *_line);
void (*_fetch_operator_func(char *_s))(stack_t**, unsigned int);

void _push_operation(stack_t **_stack, unsigned int _line_number);
void _pall_operation(stack_t **_stack, unsigned int _line_number);
void _pint_operation(stack_t **_stack, unsigned int _line_number);
void _pop_operation(stack_t **_stack, unsigned int _line_number);
void _swap_operation(stack_t **_stack, unsigned int _line_number);
void _add_operation(stack_t **_stack, unsigned int _line_number);
void _nop_operation(stack_t **_stack, unsigned int _line_number);
void _sub_operation(stack_t **_stack, unsigned int _line_number);
void _div_operation(stack_t **_stack, unsigned int _line_number);
void _mul_operation(stack_t **_stack, unsigned int _line_number);
void _mod_operation(stack_t **_stack, unsigned int _line_number);
void _pchar_operation(stack_t **_stack, unsigned int _line_number);
void _pstr_operation(stack_t **_stack, unsigned int _line_number);
void _rotl_operation(stack_t **_stack, unsigned int _line_number);
void _rotr_operation(stack_t **_stack, unsigned int _line_number);

void _free_used_stack(stack_t *head);
void _free_used_lines(line_t *_lines);
int _atoi(char *s, int *n);

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
char *strdup(const char *s);

#endif /* _MONTY_H_ */
