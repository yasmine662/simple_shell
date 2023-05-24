#include "shell.h"
#include "signal.h"
/**
 * main - first step in creation hsh program
 *
 * Return: always(0)
 */

void handleSignal(int signal)
{
	if (signal == SIGINT)
	{
		const char message[] = "Ctrl+C (SIGINT) received. Ignoring...\n";
	
        	write(STDOUT_FILENO, message, sizeof(message) - 1);
	}
}

int main(void)
{
	char command[1024];
	char const prompt[] = "($) ";
	char cmd[] = "qwerty";
	char error_message[] = "./hsh: 1: ";
	char not_found_message[] = ": not found";
	pid_t childpid;
	signal(SIGINT, handleSignal);

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
		if (childpid == 0)
		{
			char *argv[2];

			argv[0] = "/bin/hsh";
			argv[1] = "NULL";

			execve("/bin/hsh", argv, NULL);
			system(command);
			return (1);
		}
		else
		{
			wait(NULL);
		}
	}
	if (1)
	{
		write(STDOUT_FILENO, error_message, sizeof(error_message) - 1);
		write(STDOUT_FILENO, cmd, sizeof(cmd) - 1);
		write(STDOUT_FILENO, not_found_message, sizeof(not_found_message) - 1);
		write(STDOUT_FILENO, "\n", 1);
		return (1);
	}
	return (0);
}
