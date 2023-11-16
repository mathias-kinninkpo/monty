#include "monty.h"
/**
 * func_swap - swap top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @nline: number of line opcode occurs on
 */

void func_swap(stack_t **stack, unsigned int nline)
{
	stack_t *current;
	int tmp;

	current = *stack;
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}
	tmp = current->n;
	current->n = current->next->n;
	current->next->n = tmp;
}

/**
 * func_add - add top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @nline: number of line opcode occurs on
 */

void func_add(stack_t **stack, unsigned int nline)
{
	stack_t *tmp = *stack;
	int sum = 0, i = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}

	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	func_pop(stack, nline);

	(*stack)->n = sum;
}

/**
 * func_nop - nop top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @nline: number of line opcode occurs on
 */

void func_nop(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused)) unsigned int nline)
{
	;
}

/**
 * func_pchar - prints the ASCII value of a number
 * @stack: pointer to the top of the stack
 * @nline: the index of the current line
 *
 */
void func_pchar(stack_t **stack, unsigned int nline)
{
	int val;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", nline);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	val = (*stack)->n;
	if (val > 127 || val < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", nline);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(val);
	putchar('\n');
}

/**
 * func_isalpha - checks if int is in alphabet
 * @c: int
 * Return: 1 if yes, 0 if no
 */
int func_isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}
