/*
#include "monty.h"
 * main - is the main fuction
 * Return: will return 0 which means positive
int main(void)
{
	FILE *fp;
	char line[100];
	stack_t *stack = NULL;

	fp = fopen("bytecodes/00.m", "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file bytecode/00.m\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), fp) != NULL)
	{
		if  (strcmp(line, "push 1$\n") == 0)
			push(&stack, 1);
		else if (strcmp(line, "push 2$\n") == 0)
			push(&stack, 2);
		else if (strcmp(line, "push 3$\n") == 0)
			push(&stack, 3);
		else if (strcmp(line, "pall$\n") == 0)
			pall(&stack, 0);
		else
		{
			fprintf(stderr, "Error: unknown instruction %s", line);
			exit(EXIT_FAILURE);
		}

	}

	fclose(fp);

	return (0);
} 
*/

#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - the entry point for Monty Interp
 *
 * @argc: the number of parameter parse to the program
 * @argv: list of the arguments of the program
 *
 * Return: (EXIT_SUCCESS) if success (EXIT_FAILURE) if  error
 */
int main(int argc, char **argv)
{
	FILE *file_script = NULL; /* the file that contain the script */
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (error_with_usage());

	file_script = fopen(argv[1], "r");
	if (file_script == NULL)
		return (failed_open(argv[1]));

	exit_code = execute_monty(file_script);

	fclose(file_script);
	return (exit_code);
}
