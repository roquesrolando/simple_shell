#include "shell_header.h"

/**
 * executeCommand - function exectues command
 * @fullPath: name of binary file that will execute
 * @commandLineArgs: command along with options
 */

void executeCommand(char *fullPath, char **commandLineArgs)
{
	int id, status;

	id = fork();

	if (id == 0)
	{
		execve(fullPath, commandLineArgs, NULL);
	}
	else
	{
		wait(&status);
		EXIT_CODE = WEXITSTATUS(status);
	}
}
