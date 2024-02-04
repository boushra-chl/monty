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
	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	return (0);
}
