#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 * main - first step in creation hsh program
 *
 * Return: always(0)
 */

int main(void)
{
	char command[1024];
	char const prompt[] = "($) ";
	char cmd[] = "qwerty";
	char error_message[] = "./hsh: 1: ";
	char not_found_message[] = ": not found\n";
	pid_t childpid;

	while (1)
	{
	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

	if (fgets(command, sizeof(command), stdin) == NULL)
		{
			break;
		}
	childpid = fork();

	if (childpid < 0)
		{
			perror("process to create failed");
			return (1);
		}
	else
	if (childpid == 0)
	{
		char *argv[1];
		argv[0] = "/bin/hsh";
		argv[1] = "NULL";

		{
			system(command);
		}
		{
			write(STDOUT_FILENO, argv, strlen(command));
			execve("/bin/hsh", argv, NULL);
			write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
	}
	else
		{
			wait(NULL);
		}
		{
			write(STDOUT_FILENO, error_message, sizeof(error_message) - 1);
			write(STDOUT_FILENO, cmd, sizeof(cmd) - 1);
			write(STDOUT_FILENO, not_found_message, sizeof(not_found_message) - 1);
			return (1);
		}
	}
	return (0);
}
