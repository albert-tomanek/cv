/* Compile: gcc cv.c -o cv */

/*						~~ Compile Vala ~~						*
 *																*
 * This program takes a vala file,								*
 * and looks for a compile header.								*
 * The compile header is formatted like the one in this file,	*
 * (ie. "/* Compile: " + compile_command + " *" + "/").			*
 *																*
 * Copyright (c) Albert Tomanek <electron826@gmail.com>  2017	*
 * Use under the terms of the MIT license.						*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRLEN 256

const char version[] = "1.0";

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Compile Vala v%s\nSyntax:\n\t%s <file>\n", version, argv[0]);
		exit(0);
	}

	FILE *valafile   = fopen(argv[1], "r");
	char *first_line = malloc(STRLEN * sizeof(char));
	char *compile_string;

	if (! valafile)
	{
		fprintf(stderr, "Error: The file could not be opened.\n");
		exit(1);
	}
	if (! first_line)
	{
		fprintf(stderr, "Error: Out of memory.\n");
		exit(1);
	}

	fgets(first_line, STRLEN, valafile);

	fclose(valafile);

	if (! strncmp(first_line, "/* Compile: ", 12) && ! strncmp((first_line + (strlen(first_line)-4)), " */", 3))	// -4 to skip the newline at the end
	{
		compile_string = (first_line + 12);			// Skip the '/* Comp..' at the beginning
		first_line[(strlen(first_line)-3)] = '\0';	// Get rid of the ' */' at the end

		printf("%s\n", compile_string);
		system(compile_string);
	}
	else
	{
		fprintf(stderr, "Error: File does not have compile header.\n");
		exit(1);
	}

	free(first_line);

	return 0;
}
