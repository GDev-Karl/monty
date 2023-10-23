#include "monty.h"

/**
 * mod - Computes the remainder of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number of the opcode in the Monty script.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (!(*stack)->next || !(*stack)->next->next)
	{
		set_argument_error(short_error(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_argument_error(division_error(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	pop(stack, line_number);
}


/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * of the stack by the top element of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number of the opcode in the Monty script.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack)->next)
	{
		set_argument_error(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_argument_error(pchar_error(line_number, "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number of the opcode in the Monty script.
 */
void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");
}

/**
 * rotl - rotates the stack to the top
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number of the opcode in the Monty script.
 */
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *top, *bottom;

	if (!(*stack)->next || !(*stack)->next->next)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

}

/**
 * rotr -  rotates the stack to the bottom
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number of the opcode in the Monty script.
 */
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *top, *bottom;

	if (!(*stack)->next || !(*stack)->next->next)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;
}
