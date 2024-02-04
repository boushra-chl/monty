#include "monty.h"
/**
 * * open_file - function that opens a file
 * * @file_name: name of file to open
 * *
 * * Return: Nothing
 * */
void open_file(char *file_name)
{
	FILE *fd;

	if(file_name == NULL)
	{
		fprintf(stderr, "Error: file not specified\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(file_name, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: can't open file\n");
		exit(EXIT_FAILURE);
	}
	read_file(fd);
	fclose(fd);
}

/**
 * * read_file - function that reads a file
 * * @fd: file descriptor
 * *
 * * Return: Nothing
 * */
void read_file(FILE *fd)
{
	int line_number = 0;
	char *line = NULL; /*pointer to line in the bytecode file*/
	size_t len = 0; /*variable to store the size of line*/
	int format = 0; /* storage format: stack or queue*/

	line_number = 1;
	while( getline(&line, &len, fd) != -1)
	{
		format = parse_line(line, line_number, format);
	}
	line_number++;
	free(line);
}

/**
 * * parse_line - function that parses lines
 * * @line: pointer to line of strings
 * * @line_number: the number of the line
 * * @format: 0 for stack and 1 for queue
 * *
 * * Return: format
 * */
int parse_line(char *line, int line_number, int format)
{
	char *opcode; /*pointer to string indicating opcode to use*/
	char *value_str; /*pointer to the value after opcode ex: push 3*/

	if (line == NULL)
	{
		fprintf(stderr, "Error: can't read from file\n");
		exit(EXIT_FAILURE);
	}
	opcode = strtok(line, " \t\n");
	if (opcode == NULL || strcmp(opcode, "#") == 0)
		return (format);
	value_str = strtok(NULL, " /t/n");
	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	find_func(opcode, value_str, line_number, format);
	return (format);
}

