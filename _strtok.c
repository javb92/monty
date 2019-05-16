#include "monty.h"
/**
 *_strtok - print list
 *@buf: list
 *@l_ct: line
 *@tok: token
 *@he: list
 *@fi: file
 *Return: number elements.
 */
void _strtok(char *buf, unsigned int l_ct, char *tok, stack_t **he, FILE *fi)
{
	int f_idx = 0;
	instruction_t ints[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	char *delimiters = " \t\n";

	tok = strtok(buf, delimiters);
	if (tok == NULL)
	{ free(buf); }
	while (tok != NULL)
	{
		while (ints[f_idx].opcode != NULL)
		{
			if (strcmp(ints[f_idx].opcode, tok) == 0)
			{
				if (strcmp(tok, "push") == 0)
				{ tok = strtok(NULL, delimiters);
					if (_isdigit(tok) == 0)
					{ final_liberation(he, buf, fi);
						fprintf(stderr, "L%d: usage: push integer\n", l_ct);
						exit(EXIT_FAILURE);
					}
					else if (_isdigit(tok) == 1)
					{ par_number = atoi(tok);
					}
				}
				ints[f_idx].f(he, l_ct);
				break;
			}
			f_idx++;
		}
		if (ints[f_idx].opcode == NULL)
		{ fprintf(stderr, "L%d: unknown instruction %s\n", l_ct, tok);
			final_liberation(he, buf, fi);
			exit(EXIT_FAILURE); }
		tok = strtok(NULL, delimiters);
		f_idx = 0; }
}