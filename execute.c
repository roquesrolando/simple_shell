#include "shell_header.h"

/**
 * executeCommand - function exectues command
 * @fullPath: name of binary file that will execute
 * @commandLineArgs: command along with options
 */

void executeCommand(char *fullPath, char **commandLineArgs)
{
	int id;

	id = fork();

	if (id == 0)
	{
		execve(fullPath, commandLineArgs, NULL);
	}
	else
	{
		wait(NULL);
	}

}
