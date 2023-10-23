#include "monty.h"

/**
 * push - This function takes pointer to the top of the stack
 * @stack: This is the stack
 * @n: this is the item to be inserted in the stack
 */
void push(stack_t **stack, unsigned int n)
{
	stack_t *tmp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_argument_error(allocation_error());
		return;
	}

	if (op_tokens[1] == NULL)
	{
		set_argument_error(type_error(n));
		return;
	}

	for (i = 0; op_tokens[1][i]; i++)
	{
		if (op_tokens[1][i] == '-' && i == 0)
			continue;
		if (op_tokens[1][i] < '0' || op_tokens[1][i] > '9')
		{
			set_argument_error(type_error(n));
			return;
		}
	}
	new->n = atoi(op_tokens[1]);

	if (check_mode(*stack) == STACK) /* STACK mode insert at front */
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else /* QUEUE mode insert at end */
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

/**
 * pall - This function takes a pointer to the top of the stack
 * @stack: this is the stack
 * @line_number: This helps for error message handling
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - This will print the value on top of the stack
 * @stack: This is a pointer to the stack
 * @line_number: This is the line number
 * /
void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_argument_error(ErrorOfPint(line_number));
		return;
	}
	printf("%d\n", (*stack)->next->n);
}

/**
 * pop - removes the top element of the stack.
 * @stack: A pointer to the top
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;

	if ((*stack)->next == NULL)
	{
		set_argument_error(pop_error(line_number));
		return;
	}

	new_node = (*stack)->next->next;
	free((*stack)->next);
	if (new_node)
		new_node->prev = *stack;
	(*stack)->next = new_node;
}


/**
 * swap - swaps the top two elements of the stack.
 * @stack: A pointer to the top
 * @line_number: This is the line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_argument_error(short_error(line_number, "swap"));
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;

	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}

