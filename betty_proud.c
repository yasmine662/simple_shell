#include "stdio.h"
#include "stdlib.h"
/**
 * main - code passes a betty check
 *
 * Return: 1 if Fl Null also if result not equal to size of data
 */
int main(void)
{
	char data[] = "project simple shell by malika and yassmine\n";
	FILE *Fl;
	int result;

	Fl = fopen("bettycheck.txt", "w");
	if (Fl == NULL)
	{
		perror("Error opening the Fl");
		return (1);
	}
	result = fwrite(data, sizeof(char), sizeof(data), Fl);
	if (result != sizeof(data))
	{
		perror("Error writing to Fl");
		fclose(Fl);
		return (1);
	}
	return (0);
}
