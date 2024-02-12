#include "monty.h"
/**
 * push - functions that pushes a value to stack
 * @stack: pointer to top of stack
 * @line_number: number of line in instructions file
 * @value: integer to add
 *
 * Return: Nothing
 */
void push(stack_t **stack, int line_number, int value)
{
	stack_t *new_node;

	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	if ((*stack) != NULL)
	{
		new_node->next = (*stack);
		(*stack)->prev = new_node;
	}
	(*stack) = new_node;
}

/**
 * pall - prints all elements of a stack
 * @line_number: line number
 * @stack: pointer to top of stack
 *
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = (*stack);

	(void) line_number;
	if (current == NULL)
		exit(EXIT_FAILURE);
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - prints element at the top
 * @stack: pointer to head
 * @line_number: number of the line
 *
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack = &head;
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack is empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
