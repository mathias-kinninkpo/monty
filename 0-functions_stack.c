#include "monty.h"

/*OWRN BY GUY AHONAKPON GBAGUIDI*/
/**
 * func_push - push int to a stack
 * @stack: linked lists for monty stack
 * @nline: number of line opcode occurs on
 */
void func_push(stack_t **stack, __attribute__ ((unused))unsigned int nline)
{
	stack_t *s_top;
	(void)nline;

	s_top = malloc(sizeof(stack_t));
	if (s_top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	s_top->n = var_global.push_arg;
	s_top->next = *stack;
	s_top->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = s_top;
	*stack = s_top;
}

/**
 * func_pall - print all function
 * @stack: pointer to linked list stack
 * @nline: number of line opcode occurs on
 */
void func_pall(stack_t **stack, __attribute__ ((unused))unsigned int nline)
{
	stack_t *current;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * func_pint - print int a s_top of stack
 * @stack: pointer to linked list stack
 * @nline: number of line opcode occurs on
 *
 */
void func_pint(stack_t **stack, unsigned int nline)
{
	stack_t *current;

	current = *stack;
	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", nline);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", current->n);
}

/**
 * func_pop - remove element a list
 *@stack: pointer to first node
 *@nline: integer
 *Return: void
 */
void func_pop(stack_t **stack, unsigned int nline)
{
	stack_t *nodo = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", nline);
		exit(EXIT_FAILURE);
	}
	*stack = nodo->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(nodo);
}

/**
 * free_dlistint - free a list
 * @head: pointer to first node
 *
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
