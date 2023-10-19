#include "monty.h"
/**
 * main - is the main fuction
 * Return: will return 0 which means positive
 */
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
