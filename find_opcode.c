#include "monty.h"

/**
 *find_opcode - matches the opcode to the appropriate function
 *
 *@opcode: pointer to opcode that is to be matched
 *
 *@stack: pointer to pointer to top of the stack
 *
 *@line_number: line number of read line
 */

void find_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{NULL, NULL}
	};

	i = 0;
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i = i + 1;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
