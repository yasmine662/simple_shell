#include <stdio.h>
#include <stdlib.h>
#define STDOUT_FILENO 1
#define MAX_COMMAND_LENGTH 100
/**
 * main - a UNIX command line interpreter.
 * @my_shell: file name
 * @command: the commande to execute
 * Return: always 0 i succes and 1 if failed
 */

int main(void)
{
	FILE *my_shell;
	
	my_shell = fopen("my_shell", r));

	if (my_shell == NULL)
	{
		perror("open file failed");
		exit(1);
	}
	pid_t childpid;

	childpid = fork();
	if (childpid < 0)
	{
		perror("process to create failed")
		return (1);
	}
	else if (chilpid == 0)
	{
		char *const args[] = {"sh", "my_shell", NULL};

		execve("/bin/sh", args, NULL);
		perror("execve failed");
		return (1);
	}
	else
	{
		write(STDOUT_FILENO, "this is the ppid\n", 20);
		wait(NULL);
		return (0);
	}
	write(STDOUT_FILENO, "$ ", 3);
	char *command[MAX_COMMAND_LENGTH];

	while (fget(command, sizeof(command), my_shell) != NULL)
	{
		fputs(command,stdout);
	}

	fclose(my_shell);
}
