#include "monty.h"

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		(*stack)->n = ((*stack)->n) + (tmp->n);
	}
}
