#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
/*OWRN BY GUY AHONAKPON GBAGUIDI*/

/*--- Struct Definitions ---*/
extern int push_arg;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int nline);
} instruction_t;

/**
 * struct global_variable - opcoode and its function
 * @file: the opcode
 * @push_arg: function to handle the opcode
 * @buffer: pointer to
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_variable
{
	FILE *file;
	int push_arg;
	char *buffer;
} global_var;

extern global_var var_global;

void read_file(char *filename, stack_t **stack);
char *parse_line(char *line, stack_t **stack, unsigned int nline);
typedef void (*instruct_func)(stack_t **stack, unsigned int nline);
instruct_func get_op_func(char *str);

/*Fuxntions Monty*/
void func_pall(stack_t **stack, unsigned int nline);
void func_push(stack_t **stack, unsigned int nline);
void func_pint(stack_t **stack, unsigned int nline);
void func_pop(stack_t **stack, unsigned int nline);
void func_swap(stack_t **stack, unsigned int nline);
void func_nop(stack_t **stack, unsigned int nline);
void func_rotl(stack_t **stack, unsigned int nline);
void func_rotr(stack_t **stack, unsigned int nline);

/*Functions string ascci */
void func_pchar(stack_t **stack, unsigned int nline);
void func_pstr(stack_t **stack, unsigned int nline);

/*Functions math*/
void func_sub(stack_t **stack, unsigned int nline);
void func_add(stack_t **stack, unsigned int nline);
void func_mul(stack_t **stack, unsigned int nline);
void func_div(stack_t **stack, unsigned int nline);
void func_mod(stack_t **stack, unsigned int nline);

/*Utility functions*/
void free_dlistint(stack_t *head);
void dobfree(stack_t **stack);
void dobfree2(stack_t **stack);
int func_isalpha(int c);
#endif
