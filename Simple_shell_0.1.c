#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define STDOUT_FILENO 1
#define MAX_COMMAND_LENGTH 100
/**
 * main - a UNIX command line interpreter.
 * @my_shell: file name
 * @command: commande to execute
 * Return: always 0 i succes and 1 if failed
 */

int main(void)
{
	FILE *my_shell;

	my_shell = fopen("my_shell", "r");

	if (my_shell == NULL)
	{
		perror("open file failed");
		exit(1);
	}
	pid_t childpid;

	childpid = fork();

	if (childpid < 0)
	{
		perror("process to create failed");
		return (1);
	}
	else if (childpid == 0)
	{
		char *const args[] = {"sh", "my_shell", NULL};

		execve("/bin/sh", args, NULL);
		perror("execve failed");
		return (1);
	}
	else
	{
		write(STDOUT_FILENO, "this is the ppid\n", 17);
		wait(NULL);
		write(STDOUT_FILENO, "$ ", 2);
		char command[MAX_COMMAND_LENGTH];

		while (fgets(command, sizeof(command), my_shell) != NULL)
		{
			fputs(command, stdout);
		}
	}
	fclose(my_shell);
	return (0);
}
