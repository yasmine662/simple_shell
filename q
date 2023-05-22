#include "main.h"
#include <errno.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_PATH_LENGTH 100

/**
 * main - function that handle a path
 *
 * Return: 0 in success
 */
int main(void)
{
	const char *pathname = "/bin/ls";
	char *command = "-l";
	FILE *Fl = fopen(pathname, "r");
	pid_t childpid;

	if (Fl != NULL)
	{
		if (access(command, X_OK) == 0)
		{
			return (1);
		}
			if (childpid < 0)
			childpid = fork();
			{
				perror("process to create failed");
				return (1);
			}
			if (childpid == 0)
			{
				write(STDOUT_FILENO, "-l", sizeof(char));
				execve("/bin/ls", &command, NULL);
				perror("execve failed");
				return (1);
			}
			else
			{
				write(STDOUT_FILENO, "this is the ppid\n", 17);
				wait(NULL);
			}
		else
		{
			return (0);
		}
	fclose(Fl);
	}
	if (Fl == NULL)
	{
		perror("openning Fl failed");
		return (1);
	}
	return (0);
}
