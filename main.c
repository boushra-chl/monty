#include "monty.h"

/**
 * * main - main function
 * *@argc: number of arguments
 * *@argv: string of arguments
 * *
 * *Return: 0 on Success
 * */
int n;

int main(int argc, char **argv)
{
	instruction_t *ptr;

	ptr = (instruction_t *)malloc(sizeof(instruction_t));
	if (ptr == NULL)
	{
		fprintf(stderr, "Usage: monty file");
		exit(EXIT_FAILURE);
	}
	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		free(ptr);
		exit(EXIT_FAILURE);
	}
	ptr->opcode = argv[0];
	if (strcmp(ptr->opcode, "push") == 0)
	{
		n = atoi(argv[1]);
		ptr->f = &push;
	}
	else if (strcmp(ptr->opcode, "pall") == 0)
		ptr->f = &pall;
	else if (strcmp(ptr->opcode, "pint") == 0)
		ptr->f = &pint;
	return (0);
}

