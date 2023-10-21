#include "monty.h"

/**
 * stack_initialisation - Initializes a stack_t with 0 at the top
 * @stack: A pointer to an unitialized stack_t stack.
 *
 * Return: If an error occurs - EXIT_FAILURE.
 *         Otherwise - EXIT_SUCCESS.
 */
int stack_initialisation(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (allocation_error());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or bottom (queue) of a stack_t.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * check_mode - Checks if a stack_t linked list is in stack or queue mode.
 * @structure: A pointer to the top (stack) or bottom (queue)
 * of a stack_t linked list.
 *
 * Return: If the stack_t is in stack mode - STACK (0).
 *         If the stack_t is in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int check_mode(stack_t *structure)
{
	if (structure->n == STACK)
		return (STACK);
	else if (structure->n == QUEUE)
		return (QUEUE);
	return (2);
}

