#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void);
void read_command(char *buffer);
char **parse_command(char *buffer);
int execute_command(char **args);

#endif
