#include "shell.h"

#define STDOUT_FILENO 1
#define MAX_COMMAND_LENGTH 100
/**
 * main - a UNIX command line interpreter.
 *
 * Return: always 0 i succes and 1 if failed
 */

int main(void)
{
	FILE *my_shell = fopen("my_shell", "r");
	pid_t childpid;
	char command[MAX_COMMAND_LENGTH];

	if (my_shell == NULL)
	{
		{
			perror("open file failed");
			exit(1);
		}
		childpid = fork();

		if (childpid < 0)
		{
			perror("process to create failed");
			return (1);
		}
		else if (childpid == 0)
		{	
			char *const args[] = {"ls", NULL};

			execve("/bin/ls", args, NULL);
			perror("execve failed");
			return (1);
		}
		else
		{
		write(STDOUT_FILENO, "this is the ppid\n", 17);
		wait(NULL);
		}
		while (fgets(command, sizeof(command), my_shell) != NULL)
		{
			fputs(command, stdout);		
		}
	fclose(my_shell);
	}
	return (0);
}
