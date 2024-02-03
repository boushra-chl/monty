#include "monty.h"
/**
 * * push - function that adds an element to a stack
 * * @line_num: line number
 * * @top: pointer to top of stack
 * * @n: element to add to stack
 * *
 * * Return: Nothing
 * */
void push(stack_t **top, unsigned int line_number)
{
	stack_t *new_node;

	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "L<%d>: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *top;
	if ((*top) != NULL)
		(*top)->prev = new_node;
	*top = new_node;
}

/**
 * * pall - prints all elements of a stack
 * * @line_num: line number
 * * @top: pointer to top of stack
 * *
 * * Return: Nothing
 * */
void pall(stack_t **top, unsigned int line_number)
{
	if ((*top) == NULL)
	{
		fprintf(stderr, "L<%d>: usage: monty file", line_number);
		exit(EXIT_FAILURE);
	}
	while ((*top) != NULL)
	{
		printf("%d\n", (*top)->n);
		(*top) = (*top)->next;
	}
}

/**
 * * pint - prints the value at the top of stack
 * * @top: pointer to top of stack
 * *
 * * Return: Nothing
 * */
void pint(stack_t **top, unsigned int line_number)
{
	if ((*top) == NULL)
	{
		fprintf(stderr, "L<%d>: usage: monty file", line_number);
		exit(EXIT_FAILURE);
	}
	while ((*top)->prev != NULL)
		(*top) = (*top)->prev;
	printf("%d\n", (*top)->n);
}

