#include "shell.h"
#include <sys/wait.h>
#include <sys/types.h>
/**
 * prompt - function to prompt user for input.
 * @av: pointer to pointer of the arguments string
 * @env: pointer to pointer to the environment variables
 * Return: void
 */

void prompt(char **av, char **env)
{
	char *str = NULL;
	int status, i = 0;
	size_t n = 0;
	ssize_t num_char;
	char *argv[] = {NULL, NULL};
	pid_t child_pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("Cisfun$ ");
		num_char = getline(&str, &n, stdin);
		if (num_char == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		while (str[i])
		{
			if (str[i] == '\n')
				str[i] = 0;
			i++;
		}
		argv[0] = str;
		child_pid = fork();
		if (child_pid == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s: No such file or directory\n", av[0]);
		}
		else
			wait(&status);
	}
}
