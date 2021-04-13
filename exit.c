#include "shell_header.h"

int exitString(char *usrinput)
{
	int index1, count;
	char *temp;

	index1 = moveIndex(usrinput);

	temp = malloc(sizeof(char) * 120);

	for (count = 0; usrinput[index1] != '\0'; count++)
	{
		temp[count] = usrinput[index1];
		index1++;
	}

	if ((_strcmp("exit", temp)) == 0)
	{
		free(temp);
		return (0);
	}
	else
	{
		free(temp);
		return (1);
	}
}
