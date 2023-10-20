#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

extern char **op_tokens;


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* argument_error.c */
void set_argument_error(int error_code);


/* convertion.c */
char *get_string(int num);
unsigned int abs_value(int);
int get_len_base(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size);


/* error.c */
int error_with_usage(void);
int failed_open(char *filename);
int allocation_error(void);
int unknown_instruction(char *opcode, unsigned int line_number);
int type_error(unsigned int line_number);


/* push_pall */
void push(stack_t **stack, unsigned int n);
void pall(stack_t **stack, unsigned int line_number);


/* run.c */
void free_tokens(void);
unsigned int token_len(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int execute_monty(FILE *script_fd);


/* stack_function.c */
int stack_initialisation(stack_t **stack);
void free_stack(stack_t **stack);
int check_mode(stack_t *stack);


/* tokenization.c */
char **separate_words(char *str, char *delims);
int is_delimiter(char ch, char *delims);
int get_length(char *str, char *delims);
int counts_words(char *str, char *delims);
char *next_word(char *str, char *delims);

#endif
