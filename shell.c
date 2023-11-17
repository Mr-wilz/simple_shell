#include "shell.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * exec_cmd- function that executes commands
 * @argv: array of string representing command
 * @env: Pointer to the environment variables
 * @av: Array of strings representing the command-line arguments.
 */

void exec_cmd(char *argv[], char **env, char **av) {
	pid_t child_pid = fork();
	int status;

	if (child_pid == -1) {
		perror("Error creating child process");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0) {
		if (execve(argv[0], argv, env) == -1) {
			write(STDERR_FILENO, av[0], sizeof(av[0]));
			write(STDERR_FILENO, ": No such file or directory\n", 29);
		}
	} else {
		wait(&status);
	}
}

/**
 * prompt - Continuously prompts the user for input and executes entered commands.
 * @av: Array of strings representing the command-line arguments.
 * @env: Pointer to the environment variables.
 */

void prompt(char **av, char **env) {
	char *str = NULL;
	size_t n = 0;
	ssize_t num_char;
	char *argv[] = {NULL, NULL};

	while (1) {
		print_prompt();	
		num_char = get_user_input(&str, &n);

		if (num_char == -1) {
			cleanup_and_exit(str);
		}

		process_input(str);
		argv[0] = str;

		exec_cmd(argv, env, av);
	}
}

/**
 * main - Entry point of the program.
 * @ac: Number of command-line arguments.
 * @av: Array of strings representing the command-line arguments.
 * @env: Pointer to the environment variables.
 * Return: 0 on successful execution.
 */

int main(int ac, char **av, char **env) {
	if (ac == 1)
		prompt(av, env);
	return (0);
}
