#include "../../main.h"

void boot_shell()
{
	char *prompt = "($) ";
	char ch;
	int c = 0;
	char *buffer = calloc(MAX_STRING_LENGTH, sizeof(char));

	while (1)
	{

		write(STDOUT_FILENO, prompt, strlen(prompt));

		while (read(STDIN_FILENO, &ch, 1) && ch != '\n')
			buffer[c++] = ch;

		buffer[c] = '\0';
		execute_command(buffer);

		free(buffer);
		c = 0;
		buffer = calloc(MAX_STRING_LENGTH, sizeof(char));
	}
}

void execute_command(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
		perror("[error] -> ");
	else if (pid == 0)
	{
		char *ar[] = {command, NULL};
		int subProc = execve(ar[0], ar, NULL);
		if (subProc == -1)
			perror("[error] -> ");
	}
	else
		wait();
}
