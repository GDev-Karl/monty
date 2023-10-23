#include "monty.h"

/**
 * ErrorOfPint - This print error message for the stack
 * Return: It will return failure
 * @line_number: THis is the line number
 */
int ErrorOfPint(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pop_error - This print error message where we try to pop an empty stack
 * Return: It will return failure
 * @line_number: THis is the line number
 */
int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_error - This print error message for structure with less than
 * two elements
 * Return: It will return failure
 * @line_number: THis is the line number
 * @opcode: the code of the operation
 */
int short_error(unsigned int line_number, char *opcode)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * add_error - error occured if the stack contains less than two elements
 * Return: It will return failure
 * @line_number: THis is the line number
 */
int add_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * division_error - error occured if the top element of the stack is 0
 * @line_number: THis is the line number
 * Return: It will return failure
 */
int division_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}
