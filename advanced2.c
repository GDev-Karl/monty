#include "monty.h"

/**
 * stack - sets the format of the data to a stack (LIFO)
 * of the stack by the top element of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number of the opcode in the Monty script.
 */
void stack(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	(*stack)->n = STACK;
}

/**
 * queue - sets the format of the data to a queue (FIFO).
 * of the stack by the top element of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number of the opcode in the Monty script.
 */
void queue(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	(*stack)->n = QUEUE;
}
