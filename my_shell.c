#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

/**
 * main - enry point
 *
 * Return: Always 0.
 */
int main(void)
{
	size_t buf_size = 0;
	char *buf = NULL;
	char *token;
	int status, i = 0;
	char **array;
	pid_t child_pid;

	while (1)
	{

		write(1, "#cisfun$ ", 9);
		getline(&buf, &buf_size, stdin);
		token = strtok(buf, "\t\n");
		array = malloc(sizeof(char *) * 1024);

		while (token)
		{
			array[i] = token;
			token = strtok(NULL, "\t\n");
			i++;
		}
			array[i] = NULL;
			child_pid = fork();

		if (child_pid == 0)
		{
			if (execve(array[0], array, NULL) == -1)
				perror("Error");
		}
		else
		{
			wait(&status);
		}
		i = 0;
		free(array);
	}
}
