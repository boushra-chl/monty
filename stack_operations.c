#include "monty.h"
/**
 * create_node - function that initializes the stack
 * @n: value to store
 *
 * Return: pointer to the new stack
 */
stack_t *create_node(int n)
{
	stack_t *new_node;

	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error allocating memory\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;
	return(new_node);
}

/**
 * * push - function that adds an element to a stack
 * * @line_number: line number
 * * @stack: pointer to top of stack
 * * @n: element to add to stack
 * *
 * * Return: Nothing
 * */
void push(stack_t **stack, int n, unsigned int  __attribute__((__unused__))line_number)
{
	stack_t *new_node;

	new_node = create_node(n);
	if (*stack == NULL)
		(*stack) = new_node;
	else
	{
		(*stack)->prev = new_node;
		new_node->next = (*stack);
		(*stack) = new_node;
	}
}

/**
 * * pall - prints all elements of a stack
 * * @line_number: line number
 * * @stack: pointer to top of stack
 * *
 * * Return: Nothing
 * */
void pall(stack_t **stack, unsigned int __attribute__((__unused__))line_number)
{
	while ((*stack) != NULL)
	{
		printf("%d\n", (*stack)->n);
		(*stack) = (*stack)->next;
	}
}

