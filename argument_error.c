#include "monty.h"

/**
 * set_argument_error - Sets last element of op_toks to be an error code.
 * @error_code: Integer to store as a string in op_toks.
 */
void set_argument_error(int error_code)
{
	int tokens_len = 0, i = 0;
	char *exit_value = NULL;
	char **new_tokens = NULL;

	tokens_len = token_len();
	new_tokens = malloc(sizeof(char *) * (tokens_len + 2));
	if (!op_tokens)
	{
		allocation_error();
		return;
	}
	while (i < tokens_len)
	{
		new_tokens[i] = op_tokens[i];
		i++;
	}
	exit_value = get_string(error_code);
	if (!exit_value)
	{
		free(new_tokens);
		allocation_error();
		return;
	}
	new_tokens[i++] = exit_value;
	new_tokens[i] = NULL;
	free(op_tokens);
	op_tokens = new_tokens;
}
