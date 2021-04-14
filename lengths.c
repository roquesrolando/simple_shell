#include "shell_header.h"

/**
 * numberOfElementsInArray - function counts the number of commans/
 * optionsin user input
 * @usrinput: input from user
 * Return: length of the 2D array for user input
 */
int numberOfElementsInArray(char *usrinput)
{
	int count, lengthOfArray = 0;

	for (count = 0; usrinput[count] != '\0'; count++)
	{
		if ((usrinput[count] == 32 && usrinput[count + 1] != 32) ||
				(count == 0 && usrinput[count] != 32))
		{
			lengthOfArray++;
		}
	}
	return (lengthOfArray);
}

/**
 * moveIndex - function moves the index up from where we start reading command,
 * if there are extra spaces at beginning of user input
 * @usrinput: input from user
 * Return: the index to start reading command from
 */
int moveIndex(char *usrinput)
{
	int count, index1 = 0;

	for (count = 0; (usrinput[index1] == 32  || usrinput[index1] == '\t') 
                    && usrinput[index1] != '\0'; count++)
	{
		index1++;

		if (usrinput[index1] != 32)
		{
			break;
		}
	}

	return (index1);
}

/**
 *
 *
 */
int checkIfInputAllSpaces(char *usrinput)
{
	int count;

	for (count = 0; usrinput[count] != '\0'; count++)
	{
		if (usrinput[count] != 32)
		{
			return (0);
		}
	}
	return (1);
}
