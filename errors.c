#include "monty.h"

/**
 * error_with_usage - Prints error if the usage is not good
 *
 * Return: EXIT_FAILURE
 */
int error_with_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * failed_open - cannot open a file
 * @file_name: the name of the file
 *
 * Return: EXIT_FAILURE
 */
int failed_open(char *file_name)
{
	fprintf(stderr, "Can't open file %s\n", file_name);
	return (EXIT_FAILURE);
}

/**
 * allocation_error - malloc failed
 *
 * Return: (EXIT_FAILURE) always.
 */
int allocation_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * unknown_instruction - Prints unknown instruction where
 * @opcode: Opcode where error occurred.
 * @line_number: Line number in Monty file
 *
 * Return: EXIT_FAILURE
 */
int unknown_instruction(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * type_error - Prints invalid type. must be an integer
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int type_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
