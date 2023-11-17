#include "shell.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "Cisfun$ ", 8);
}

ssize_t get_user_input(char **str, size_t *n)
{
	return getline(str, n, stdin);
}

void cleanup_and_exit(char *str)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(str);
	exit(EXIT_SUCCESS);
}

void process_input(char *str)
{
	int i = 0;
	while (str[i]) {
		if (str[i] == '\n') {
			str[i] = 0;
			break;
		}
		i++;
	}
}
