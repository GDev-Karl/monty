#include "monty.h"

/**
 * pchar_error - error occured if the value is not in the ascii table
 * @line_number: THis is the line number
 * @message_error: the message of the error
 * Return: It will return failure
 */
int pchar_error(unsigned int line_number, char *message_error)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message_error);
	return (EXIT_FAILURE);
}
