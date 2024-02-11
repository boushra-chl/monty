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

	if (current == NULL)
	{
		fprintf(stderr, "L%d: usage: pall\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

