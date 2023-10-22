#include "monty.h"

/**
 * free_tokens - Frees the global op_tokens array of strings.
 */
void free_tokens(void)
{
	size_t i = 0;

	if (op_tokens == NULL)
		return;

	for (i = 0; op_tokens[i]; i++)
		free(op_tokens[i]);

	free(op_tokens);
}

/**
 * token_len - the length of current op_toks.
 *
 * Return: Length of current op_toks
 */
unsigned int token_len(void)
{
	unsigned int sizeof_tokens = 0;

	while (op_tokens[sizeof_tokens])
		sizeof_tokens++;

	return (sizeof_tokens);
}

/**
 * is_empty_line - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int is_empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", push},
		{"pall", pall},
	        {"pint", pint},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * run_monty - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int execute_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (stack_initialisation(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		line_number++;
		op_tokens = separate_words(line, DELIMS);
		if (op_tokens == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			free_stack(&stack);
			return (allocation_error());
		}
		else if (op_tokens[0][0] == '#') /* comment line */
		{
			free_tokens();
			continue;
		}
		op_func = get_op_func(op_tokens[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			exit_status = unknown_instruction(op_tokens[0], line_number);
			free_tokens();
			break;
		}
		prev_tok_len = token_len();
		op_func(&stack, line_number);
		if (token_len() != prev_tok_len)
		{
			if (op_tokens && op_tokens[prev_tok_len])
				exit_status = atoi(op_tokens[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (allocation_error());
	}

	free(line);
	return (exit_status);
}
