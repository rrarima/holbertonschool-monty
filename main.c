#include "monty.h"

int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 1;
        stack_t *stack = NULL;
	int i;

        instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"nop", nop},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return EXIT_FAILURE;
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	read = getline(&line, &len, file);
	while (read != -1)
	{
		char *opcode;

		opcode = strtok(line, " \t\n");

		if (opcode == NULL)
		{
			line_number = line_number + 1;
			continue;
		}
		i = 0;
		while (instructions[i].opcode != NULL)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				break;
			}
			i = i + 1;
		}

		if (instructions[i].opcode == NULL)
		{
			fprintf(stderr, "L%u: unkown instruction %s\n", line_number, opcode);
			return (EXIT_FAILURE);
		}

		read = getline(&line, &len, file);
		line_number = line_number + 1;

	}
	free(line);
	fclose(file);

	return (EXIT_SUCCESS);
}
