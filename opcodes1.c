#include "monty.h"
/**
 * swap - function that swaps 2 first elements
 * @stack: pointer to stack
 * @line_number: number of line
 *
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr,"L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	(*stack)->prev = tmp;
	tmp->next = (*stack);
	tmp->prev = NULL;
	if ((*stack)->next != NULL)
		(*stack)->next->prev = (*stack);
	(*stack) = tmp;
}
