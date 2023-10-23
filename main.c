#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_tokens = NULL;

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
