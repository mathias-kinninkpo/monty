#include "monty.h"

/*OWRN BY GUY AHONAKPON GBAGUIDI*/
/**
 * func_sub - sub top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @nline: number of line opcode occurs on
 */
void func_sub(stack_t **stack, unsigned int nline)
{
	stack_t *tmp = *stack;
	int sub = 0, i = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}

	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	func_pop(stack, nline);

	(*stack)->n = sub;
}

/**
 * func_mul - mul top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @nline: number of line opcode occurs on
 */
void func_mul(stack_t **stack, unsigned int nline)
{
	int aux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", nline);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		aux = (*stack)->n;
		func_pop(stack, nline);
		(*stack)->n *= aux;
	}
}

/**
 * func_div - div top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @nline: number of line opcode occurs on
 */
void func_div(stack_t **stack, unsigned int nline)
{
	int div = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", nline);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", nline);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		div = (*stack)->n;
		func_pop(stack, nline);
		(*stack)->n /= div;
	}
}

/**
 * func_mod - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @nline: number of line opcode occurs on
 */
void func_mod(stack_t **stack, unsigned int nline)
{
	int mod = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", nline);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", nline);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		mod = (*stack)->n;
		func_pop(stack, nline);
		(*stack)->n %= mod;
	}
}
