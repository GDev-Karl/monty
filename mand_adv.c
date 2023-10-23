#include "monty.h"

#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number of the opcode in the Monty script.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!(*stack)->next || !(*stack)->next->next)
	{
		set_argument_error(add_error(line_number));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	pop(stack, line_number);
}

#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number of the opcode in the Monty script.
 */
void nop(stack_t **stack __attribute__((unused)), unsigned int line_number
		__attribute__((unused)))
{

}

/**
 * sub - subtracts the top element of the stack from the second top
 * element of the stack
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number of the opcode in the Monty script
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (!(*stack)->next || !(*stack)->next->next)
	{
		set_argument_error(short_error(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * divide - divides the second top element of the stack by the top
 * element of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number of the opcode in the Monty script
 */
void divide(stack_t **stack, unsigned int line_number)
{
	if (!(*stack)->next || !(*stack)->next->next)
	{
		set_argument_error(short_error(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_argument_error(division_error(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	pop(stack, line_number);
}

void mul(stack_t **stack, unsigned int line_number)
{
	if (!(*stack)->next || !(*stack)->next->next)
	{
		set_argument_error(short_error(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	pop(stack, line_number);
}
