#include "monty.h"

/**
 *swap - swaps the top two elements of the stack
 *
 *@stack: pointer to pointer to top of the stack
 *
 *@line_number: line number of read line
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int tmp;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = current->n;
	current->n = current->next->n;
	current->next->n = tmp;
}

/**
 *add - adds top two elements of the stack and removes the top element after
 *
 *@stack: pointer to pointer to top of the stack
 *
 *@line_number: line number of read line
 */

void add(stack_t **stack, unsigned int line_number)
{
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
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	pop(stack, line_number);
}

/**
 *nop - function that does nothing
 *
 *@stack: pointer to pointer to top of the stack
 *
 *@line_number: line number of read line
 */

void nop(__attribute__((unused))stack_t **stack,
	 __attribute__((unused))unsigned int line_number)
{
	;
}
