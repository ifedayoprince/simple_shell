/*
 * File: main.c
 * Auth: Ifedayo Oni, Muhammad Yusuf
 */

#include "main.h"

/**
 * main - entry function called when program loads.
 *
 * Return: the return number
 */
int main(void)
{
	char buffer[MAX_STRING_LENGTH];

	if (isatty(STDIN_FILENO) == 0)
	{
		int c = 0;
		char ch;

		while (read(STDIN_FILENO, &ch, 1) && ch != EOF)
			if (ch != '\n')
				buffer[c++] = ch;

		buffer[c] = '\0';
		execute_command(buffer);

		return (0);
	}
	boot_shell();

	return (0);
}
