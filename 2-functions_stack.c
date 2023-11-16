#include "monty.h"

/**
 * func_pstr - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @nline: number of line opcode occurs on
 */
void func_pstr(stack_t **stack, unsigned int nline)
{
	stack_t *tmp = *stack;
	int c = 0;

	(void)nline;


	while (tmp)
	{
		c = tmp->n;
		if (c == 0 || func_isalpha(c) == 0)
			break;
		putchar(c);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * func_rotl - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @nline: number of line opcode occurs on
 */
void func_rotl(stack_t **stack, unsigned int nline)
{
	stack_t *current = *stack;


	int var1 = 0;

	if (!nline || !stack || !*stack || !(*stack)->next)
		return;

	var1 = current->n;

	while (current->next)
	{
		current = current->next;
		current->prev->n = current->n;
	}

	current->n = var1;
}

/**
 * func_rotr - mod top of stack y second top stacks
 * @stack: pointer to lists for monty stack
 * @nline: number of line opcode occurs on
 */
void func_rotr(stack_t **stack, unsigned int nline)
{
	stack_t *current = *stack;

	int var1 = 0;

	if (!nline || !stack || !*stack || !(*stack)->next)
		return;

	while (current->next)
		current = current->next;

	var1 = current->n;

	while (current->prev)
	{
		current = current->prev;
		current->next->n = current->n;
	}

	current->n = var1;
}
