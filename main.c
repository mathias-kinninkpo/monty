#include "monty.h"
/*GUY AHONAKPON GBAGUIDI*/
global_var var_global;
/**
 * main - driver function for monty program
 * @var_argc: int num of arguments
 * @var_argv: opcode file
 * Return: 0
 */
int main(int var_argc, char **var_argv)
{
	stack_t *stack;

	stack = NULL;
	if (var_argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(var_argv[1], &stack);
    /* recordar liberar memorias */
	free_dlistint(stack);
	return (0);
}
