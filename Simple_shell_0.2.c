#include "main.h"

#define MAX_ARGS 100
/**
 * main - handle  arguments
 *
 * Return: Always 0 in success
 */
int main(void)
{

        char *argv[MAX_ARGS];
        int argc = MAX_ARGS;
        int i;

        FILE *Fl = fopen("handlearg.txt", "w");

        if (Fl == NULL)
        {
                perror("opening Fl failed");
                return (1);
        }
        for (i = 0; i < argc; i++)
        {
                if (argv[i] != NULL)
                {
                        fwrite(argv[i], sizeof(char), 1, Fl);
                }
        }
        fclose(Fl);
        return (0);

	char *argv[MAX_ARGS];
	int argc = MAX_ARGS;
	int i;

	FILE *Fl = fopen("handlearg.txt", "w");

	if (Fl == NULL)
	{
		perror("opening Fl failed");
		return (19);
	}
	for (i = 0; i < argc; i++)
	{
		if (argv[i] != NULL)
		{
			fwrite(argv[i], sizeof(char), 1, Fl);
		}
	}
	fclose(Fl);
	return (0);

}
