#include "monty.h"

/**
 *push - pushes a new node onto the top of the stack
 *
 *@stack: pointer to pointer to top of the stack
 *
 *@line_number: line number of read line
 */

void push(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *new_node;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(strtok(NULL, " \t\n"));
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 *pall - prints values of stack starting from the top
 *
 *@stack: pointer to pointer to top of the stack
 *
 *@line_number: line number of read line
 */

void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 *pint - prints the value at the top of the stack
 *
 *@stack: pointer to pointer to stack in stack_t struct
 *
 *@line_number: line number of read opcode
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}

/**
 *pop - removes the top element of the stack
 *
 *@stack: pointer to pointer to top of the stack
 *
 *@line_number: line number of read line
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
