#include "monty.h"
/**
 * * find_func - find the appropriate function for the opcode
 * * @opcode: opcode to execute
 * * @value: argument of opcode
 * * @format: 0 for stack and 1 for queue
 * * @line_number: line number
 * *
 * * Return: Nothing
 * */
void find_func(char *opcode, char *value, int line_number, int format)
{
	int i;
	instruction_t opcode_func[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; opcode_func[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcode_func[i].opcode) == 0)
			call_func(opcode_func[i].f, opcode, value, line_number, format);
		else
		{
			fprintf(stderr, "Error: invalid instructions\n");
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * * call_func - Calls the required function.
 * * @func: Pointer to the function that is about to be called.
 * * @opcode: string representing the opcode.
 * * @value: string representing a numeric value.
 * * @line_number: line numeber for the instruction.
 * * @format: 0 or 1
 * */
void call_func(op_func func, char *opcode, char *value_str, int line_number, int format)
{
	stack_t *stack;
	int i;

	if (strcmp(opcode, "push") == 0)
	{
		if (value_str != NULL && value_str[0] == '-')
			value_str = value_str + 1;
		if (value_str == NULL)
		{
			fprintf(stderr, "Error: No integer to push\n");
			exit(EXIT_FAILURE);
		}
		for (i = 0; value_str[i] != '\0'; i++)
		{
			if(isdigit(value_str[i]))
			{
				fprintf(stderr, "Error: No integer to push\n");
				exit(EXIT_FAILURE);
			}
		}
		stack = create_node(atoi(value_str));
		if (format == 0)
			func(&stack, line_number);
	}
	else
		func(&stack, line_number);
}

