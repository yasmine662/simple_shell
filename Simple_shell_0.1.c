#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * main - a UNIX command line interpreter.
 *
 * Return: always 0 i succes and 1 if failed
 */

int main(void)
{
	char command[1024];
	char const prompt[] = "#cisfun$ ";
	int  length = 0;
	pid_t childpid;

	while (1)
        {
        write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
  
	if (fgets(command, sizeof(command), stdin) == NULL)
	{
	break;
	}

	length = 0;
	while (command[length] != '\0' && command[length] != '\n')
	{
		length++;
	}
        if (length == 0 || (length == 1 && command[0] == '\n'))
	{
		break;
	}
        if (command[length - 1] == '\n')
	{
		command[length - 1] = '\0';
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
			char *args[2];
			args[0] = "/bin/ls";
			args[1] = "NULL";
			
			if (execve(command, args, NULL) == -1)
			{
				write(STDERR_FILENO, "./shell: ", 9);
				write(STDERR_FILENO, ": No such file or directory\n", 28);
                        	return (1);
			}
                }
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
