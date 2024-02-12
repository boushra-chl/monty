#include "monty.h"
/**
 * call_push_func - function that calls the push function
 * @opcode: pointer to opcode
 * @value_str: pointer to value
 * @line_number: number of line in instructions file
 *
 * Return: Nothing
 */

void call_push_func(char *opcode, char *value_str, int line_number)
{
	int i;

	if (strcmp(opcode, "push") == 0)
	{
		if (value_str == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		if (value_str[0] == '-')
			value_str = value_str + 1;
		for (i = 0; value_str[i] != '\0'; i++)
		{
			if (isdigit(value_str[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
		push(&head, line_number, atoi(value_str));
	}
	else
		find_func(&head, opcode, line_number);
}

/**
 * find_func - function that finds the appropriate function
 * @opcode: pointer to opcode
 * @line_number: number of line in instruction file
 * @stack: pointer to stack
 * Return: Nothing
 */
void find_func(stack_t **stack, char *opcode, int line_number)
{
	instruction_t op_func[] = {
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};
	int i;

	stack = &head;
	for (i = 0; op_func[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, op_func[i].opcode) == 0)
		{
			op_func[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

