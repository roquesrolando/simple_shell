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

	if (ac == 500)
		printf("%s\n", av[0]);/*debugging purposes*/
	signal(SIGINT, get_c);
	patharray = get_path(env);

	while (1)
	{
		commandLineArgs = input(patharray);

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
		if (_strcmp(commandLineArgs[0], "exit") == 0)
		{
			freeDoublePointers(patharray);
			freeDoublePointers(commandLineArgs);
			exit(0);
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
	return (0);
}

/**
 * checkIsAtty - function checks to see if prompt needs to be printed
 */
void checkIsAtty(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		_putchar('$');
		_putchar(' ');
	}

}

/**
 * handlesNullInput - functions checks for NULL input
 * @usrinput: user or file input
 * Return: NULL
 */
char **handlesNullInput(char *usrinput)
{
	free(usrinput);
	return (NULL);
}
