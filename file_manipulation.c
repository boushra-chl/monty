#include "monty.h"
/**
 * open_file - function that opens a file
 * @file_name: name of file to open
 *
 * Return: Nothing
 */
void open_file(char *file_name)
{
	FILE *fd;

	if (file_name == NULL)
	{
		fprintf(stderr, "No file name provided\n");
			exit(EXIT_FAILURE);
	}
	fd = fopen(file_name, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	read_file(fd);
	fclose(fd);
}

/**
 * read_file - function that reads from a file
 * @fd: pointer to file descriptor
 *
 * Return: Nothing
 */
void read_file(FILE *fd)
{
	char *line = NULL;
	int line_number;
	char *opcode;
	char *value_str;

	line = malloc(LINE_LEN_MAX * sizeof(char));
	if (line == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	line_number = 1;
	while (fgets(line, LINE_LEN_MAX, fd) != NULL)
	{
		opcode = strtok(line, " \t\n");
		if (opcode == NULL || strcmp(opcode, "#") == 0)
			continue;
		value_str = strtok(NULL, " \t\n");
		call_push_func(opcode, value_str, line_number);
		line_number++;
	}
	free(line);
}

