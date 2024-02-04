#include "monty.h"
/**
 * * main - main function, entry point of my code
 * * @argc: number of arguments
 * * @argv: array of strings containing arguments
 * *
 * * Return: 0 on Success
 * */
int main(int argc, char **argv)
{
	FILE *fd; /*bytecode file to read instructions from*/
	char *line = NULL; /*pointer to line in the bytecode file*/
	size_t len = 0; /*variable to store the size of line*/
	ssize_t read; /*number of characters read from file*/
	char *opcode; /*pointer to string indicating opcode to use*/
	char *value_str; /*pointer to the value after opcode ex: push 3*/
	int value; /*value to push*/

	stack_t *stack = NULL;
	unsigned int line_number;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
		if (fd == NULL)
		{
			fprintf(stderr, "Error: can't open file\n");
			exit(EXIT_FAILURE);
		}
	line_number = 1;
	while((read = getline(&line, &len, fd)) != -1)
	{
		opcode = strtok(line, " \t\n");
		if (opcode == NULL || strcmp(opcode, "#") == 0)
		{
			line_number++;
			continue;
		}
		if (strcmp(opcode, "push") == 0)
		{
			value_str = strtok(NULL, " /t/n"); /*continue tokenizing the original line*/
			if(value_str == NULL || !isdigit(value_str[0]))
			{
				fprintf(stderr, "Usage: monty file\n");
				exit(EXIT_FAILURE);
			}
			value = atoi(value_str);
			push(&stack, value, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
			pall(&stack, line_number);
		line_number++;
	}
	fclose(fd);
	if (line)
		free(line);
	return (0);
}

