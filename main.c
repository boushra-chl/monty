#include "monty.h"
/**
 * * main - main function, entry
 * * @argc: number of arguments
 * * @argv: array of arguments
 * *
 * * Return: 0 on Success
 * */
stack_t *head = NULL;
int main(int argc, char **argv)
{
	if(argc != 2)
	{
		fprintf(stderr, "Usage: monty file");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	return(0);
}
