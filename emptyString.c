#include <stdio.h>
#include <stdlib.h>

char **handleEmptyString()
{
	char **commandLineArgs;

	commandLineArgs = malloc(sizeof(char *) * 2);

	commandLineArgs[0] = NULL;
	commandLineArgs[1] = NULL;

	return (commandLineArgs);
}
