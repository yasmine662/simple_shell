#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * main - first step in creation hsh program
 *
 * Return: always(0)
 */

int main(void)
{
	char command[1024];
	char const prompt[] = "($) ";

	while (1)
	{
	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

	if (fgets(command, sizeof(command), stdin) == NULL)
	{
		break;
	}
	system(command);
	}
	return (0);
}
