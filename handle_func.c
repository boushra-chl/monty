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
void find_func(char *opcode, char *value_str, int line_number, int format)
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
		{
			call_func(opcode_func[i].f, opcode, value_str, line_number, format);
			return;
		}
	}
	fprintf(stderr, "Error: invalid instructions\n");
	exit(EXIT_FAILURE);
}

/**
 * * call_func - Calls the required function.
 * * @func: Pointer to the function that is about to be called.
 * * @opcode: string representing the opcode.
 * * @val_str: string representing a numeric value.
 * * @line_number: line numeber for the instruction.
 * * @format: 0 or 1
 * */
void call_func(op_func func, char *opcode, char *val_str, int line_number, int format)
{
	stack_t *stack = NULL;
	int i;

	if (strcmp(opcode, "push") == 0)
	{
		if (val_str != NULL && val_str[0] == '-')
			val_str = val_str + 1;
		if (val_str == NULL)
		{
			fprintf(stderr, "Error: No integer to push\n");
			exit(EXIT_FAILURE);
		}
		for (i = 0; val_str[i] != '\0'; i++)
		{
			if(isdigit(val_str[i]) == 0)
			{
				fprintf(stderr, "Error: Not integer\n");
				exit(EXIT_FAILURE);
			}
		}
		stack = create_node(atoi(val_str));
		if (format == 0)
			func(&stack, line_number);
	}
	else
		func(&stack, line_number);
}

