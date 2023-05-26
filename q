#include <shell.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIMITER " \t\r\n\a"


/**
 * main - write prompt
 *
 * Return: always 0
 */

int main(void)
{
	char buffer[BUFFER_SIZE];
	char **args;
	int status;

	while (1)
	{
	write(STDOUT_FILENO, "$ ", 2);
	read_command(buffer);
	args = parse_command(buffer);
	status = execute_command(args);

	free(args);

	if (status == 0)
		break;
	}

	return (0);
}

/**
 * read_command - function that read command
 * @buffer: which coontent data
 * Return: always 0
 */

void read_command(char *buffer)
{
	fgets(buffer, BUFFER_SIZE, stdin);
}
/**
 * parse_command - function  toknization
 * @buffer: which content data
 * Return: always 0
 */

char **parse_command(char *buffer)
{
	int buffer_size = BUFFER_SIZE;
	int position = 0
	char **tokens = malloc(buffer_size * sizeof(char *));
	char *token;

	if (!tokens)
	{
	write(STDERR_FILENO, "Memory allocation error\n", 24);
	exit(EXIT_FAILURE);
	}

	token = strtok(buffer, TOKEN_DELIMITER);
	while (token != NULL)
	{
	tokens[position] = token;
	position++;

	if (position >= buffer_size)
	{
		buffer_size += BUFFER_SIZE;
		tokens = realloc(tokens, buffer_size * sizeof(char *));
		if (!tokens)
		{
		write(STDERR_FILENO, "Memory allocation error\n", 24);
		exit(EXIT_FAILURE);
		}
	}

	token = strtok(NULL, TOKEN_DELIMITER);
	}
	tokens[position] = NULL;

	return (tokens);
}
/**
 * execute_command - function that execute command
 * @args: argument entred
 * Return: always 0
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;
	int pipefd[2];
	char not_found_message[] = ": not found";


	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	pid = fork();
	if (pid == 0)
	{
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);

	execvp(args[0], args)
	{
		char not_found_message[] = ": not found\n";

		write(STDERR_FILENO, args[0], strlen(args[0]));
		write(STDERR_FILENO, not_found_message, strlen(not_found_message));
		return (1);
	}
	}
	else if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
	{
	close(pipefd[1]);

	char buffer[BUFFER_SIZE];
	ssize_t n;
	char output[BUFFER_SIZE];
	int output_pos = 0;

	while ((n = read(pipefd[0], buffer, BUFFER_SIZE)) > 0)
	{
		memcpy(output + output_pos, buffer, n);
		output_pos += n;
	}

	close(pipefd[0]);

	if (output_pos > 0)
	{
		int start_index = 0;
	while (output[start_index] != '|')
	{
		{
			start_index++;
		}
		start_index++;

		write(STDOUT_FILENO, output + start_index, output_pos - start_index);
	}

	waitpid(pid, &status, 0);
	return (0);
	}
	return (0);
	}
}
