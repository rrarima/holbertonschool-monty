#include "monty.h"

int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
        stack_t *stack = NULL;

        instruction_t instructions[] = {
		{.opcode = "push", .f = push},
		{.opcode = "pall", .f = pall},
		{.opcode = NULL, .f = NULL}
	};

	instruction_t *instruction = &instructions[0];

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

	while ((read = getline(&line, &len, file)) != -1)
	{
		char *opcode;

		opcode = strtok(line, " \t\n");
		if (opcode == NULL)
		{
			line_number = line_number + 1;
			continue;
		}

		while (instruction->opcode != NULL)
		{
			if (strcmp(opcode, instruction->opcode) == 0)
			break;
		}

		if (instruction->opcode == NULL)
		{
			fprintf(stderr, "L%u: unkown instruction %s\n", line_number, opcode);
			return EXIT_FAILURE;
		}

		instruction->f(&stack, line_number);
		line_number = line_number + 1;

	}

	free(line);
	fclose(file);

	return EXIT_SUCCESS;

}
