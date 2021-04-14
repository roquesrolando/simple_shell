#include "shell_header.h"

/**
 * executeCommand - function exectues command
 * @fullPath: name of binary file that will execute
 * @commandLineArgs: command along with options
 */

int executeCommand(char *fullPath, char **commandLineArgs)
{
	int id, status;

	id = fork();

	if (id == 0)
	{
		if (execve(fullPath, commandLineArgs, NULL) == -1)
		{
			return (-1);
		}
	}
	else
	{
		wait(&status);
		EXIT_CODE = WEXITSTATUS(status);
	}
	return (0);
}
