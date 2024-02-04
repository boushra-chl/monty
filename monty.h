#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>
#include<sys/types.h>
#include <ctype.h>

/**
 * * struct stack_s - doubly linked list representation of a stack (or queue)
 * * @n: integer
 * * @prev: points to the previous element of the stack (or queue)
 * * @next: points to the next element of the stack (or queue)
 * *
 * * Description: doubly linked list node structure
 * * for stack, queues, LIFO, FIFO
 * */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * * struct instruction_s - opcode and its function
 * * @opcode: the opcode
 * * @f: function to handle the opcode
 * *
 * * Description: opcode and its function
 * * for stack, queues, LIFO, FIFO
 * */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef void (*op_func)(stack_t **, unsigned int);

stack_t *create_node(int n);
void push(stack_t **stack, unsigned int __attribute__((__unused__))line_number);
void pall(stack_t **new_node, unsigned int __attribute__((__unused__))line_number);
void open_file(char *file_name);
void read_file(FILE *fd);
int parse_line(char *line, int line_number, int format);
void find_func(char *opcode, char *value, int line_number, int format);
void call_func(op_func func, char *opcode, char *value_str, int line_number, int format);

#endif
