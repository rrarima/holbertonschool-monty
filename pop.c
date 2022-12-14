#include "monty.h"

void pop(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
