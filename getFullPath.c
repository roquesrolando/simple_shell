#include "shell_header.h"

/**
 * getFullPath - function parses through path array and opens every
 * directory and checks to see if file exists
 * @patharray: array of directories in path
 * @commandLineArgs: user input
 * Return: the directory containing the binary
 */
/*char *getFullPath(char **patharray, char **commandLineArgs)
{
	DIR *directory = NULL;
	struct dirent *binaryFiles = NULL;
	int count;

	for (count = 0; patharray[count] != NULL; count++)
	{
		directory = opendir(patharray[count]);
		while ((binaryFiles = readdir(directory)) != NULL)
		{
			if (_strcmp(binaryFiles->d_name, commandLineArgs[0]) == 0)
			{
				closedir(directory);
				return (patharray[count]);
			}
		}
		closedir(directory);
	}
	perror(commandLineArgs[0]);
	*printf("%s: No such file or directory\n", commandLineArgs[0]);
	return (NULL);
}*/

char *getFullPath(char **patharray, char **commandLineArgs)
{
	DIR *directory = NULL;
	struct dirent *binaryFiles = NULL;
	int count;
	errno = ENOENT;
	
	for (count = 0; patharray[count] != NULL; count++)
	{
		directory = opendir(patharray[count]);
		while ((binaryFiles = readdir(directory)) != NULL)
		{
			if (_strcmp(binaryFiles->d_name, commandLineArgs[0]) == 0)
			{
				closedir(directory);
				return (patharray[count]);
			}
		}
		closedir(directory);
	}
	perror(commandLineArgs[0]);
	return (NULL);
}
