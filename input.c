#include "shell_header.h"

/**
 * input - function gets input from user
 * Return: commandLineArgs
 */
char **input(void)
{
	ssize_t length;
	size_t inputSize = 50;
	char *usrinput = NULL, *newInput = NULL;
	int count;

	if (isatty(STDIN_FILENO) == 1)
	{
		_putchar('$');
		_putchar(' ');
	}

	length = getline(&usrinput, &inputSize, stdin);

	if (length == EOF || (length == 1 && (isatty(STDIN_FILENO) == 0)))
	{
		free(usrinput);
		return (NULL);
	}
	if (length == 1 && (isatty(STDIN_FILENO) == 1))
	{
		while (length == 1)
		{
			_putchar('$');
			_putchar(' ');
			length = getline(&usrinput, &inputSize, stdin);
		}
	}
	usrinput[length - 1] = '\0';

	if ((_strcmp("exit", usrinput)) == 0)
	{
		free(usrinput);
		return (NULL);
	}

	for (count = 0; usrinput[count] != '\0'; count++)
	{
		if (usrinput[count] == '/' && usrinput[count + 1] != '\0')
		{
			newInput = pathInput(usrinput);
			if (newInput == NULL)
			{
				free(newInput);
				return (getArray(usrinput));
			}
			return (getArray(newInput));
		}
	}
	free(newInput);
	return (getArray(usrinput));
}

/**
 * getArray - function converts user input into an array
 * @usrinput: user input
 * Return: commandLineArgs
 */
char **getArray(char *usrinput)
{
	int count, count2, index1 = 0, lengthOfArray = 0;
	char **commandLineArgs;

	lengthOfArray = numberOfElementsInArray(usrinput);
	commandLineArgs = malloc(sizeof(commandLineArgs) * (lengthOfArray + 1));
	if (commandLineArgs == NULL)
	{
		free(usrinput);
		return (NULL);
	}
	for (count = 0; count < lengthOfArray; count++)
	{
		commandLineArgs[count] = malloc(sizeof(char) * 100);

		if (commandLineArgs[count] == NULL)
		{
			for (count -= 1; count >= 0; count--)
			{
				free(commandLineArgs[count]);
			}
			free(commandLineArgs);
			return (NULL);
		}
	}
	index1 = moveIndex(usrinput);
	for (count = 0; (count < 100) && (usrinput[index1] != '\0'); count++)
	{
		for (count2 = 0; usrinput[index1] != 32
			&& usrinput[index1] != '\0'; count2++)
		{
			commandLineArgs[count][count2] = usrinput[index1];
			index1++;
		}
		commandLineArgs[count][count2] = '\0';
		while (usrinput[index1] == 32)
			index1++;
	}
	commandLineArgs[count] = NULL;
	free(usrinput);
	return (commandLineArgs);
}

/**
 * _strcmp - function compares two strings
 * @s1: string to compare
 * @s2: string to compare
 * Return: 0 if strings are the same, -1 if not
 */
int _strcmp(char *s1, char *s2)
{
	int count;

	for (count = 0; s1[count] != '\0' || s2[count] != '\0'; count++)
	{
		if (s1[count] != s2[count])
			return (-1);
	}

	return (0);
}
