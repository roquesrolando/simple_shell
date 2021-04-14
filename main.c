#include "shell_header.h"

/**
 * main - our simple shell, reads command from the command line
 * and searches for the appropiate fullPath to execute
 * @ac: number of argumetns
 * @av: commands entered
 * @env: enviroment variables
 * Return: 0 if succesful
 */
int main(int ac, char **av, char **env)
{
	char **commandLineArgs, **patharray, *fullPath, *pathname;

	if (ac == 5)
		printf("%s\n", av[0]);/*debugging purposes*/

	patharray = get_path(env);

	while (1)
	{
		commandLineArgs = input();

		if (commandLineArgs == NULL)
		{
			freeDoublePointers(patharray);
			exit(0);
		}
		if (_strcmp(commandLineArgs[0], "env") == 0)
		{
			printDoubleArray(env);
			freeDoublePointers(commandLineArgs);
			continue;
		}

		pathname = getFullPath(patharray, commandLineArgs);

		if (pathname == NULL)
		{
			freeDoublePointers(commandLineArgs);
			continue;
		}
		fullPath = strConcat(pathname, commandLineArgs[0]);
		executeCommand(fullPath, commandLineArgs);
		free(fullPath);
		freeDoublePointers(commandLineArgs);

	}
	free(patharray);
	return (0);
}
