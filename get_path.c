#include "shell.h"
#define MAX_PATH_SIZE 4096

/**
 * tok_line - tokenises users input
 * @input: pointer to string input
 * @delim: pointer to string used to separate tokens
 * @tokens: pointer to array of tokens extracted from input
 * @token_count: pointer to an integer that will be used to store
 * the count of tokens found in the input line
 * Return: void
 */

void tokenize_line(char *input, const char *delimiters, char **tokens, int *token_count) {
	char *token = strtok(input, delimiters);
	*token_count = 0;

	while (token != NULL) {
		tokens[(*token_count)++] = token;
		token = strtok(NULL, delimiters);
	}

	tokens[*token_count] = NULL;
}

/**
 * get_path - function that gets the path of an entered command
 * @command: command input by the user
 * Return: Null on success.
 */

char *get_path(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *token = strtok(path_copy, ":");

	if (command[0] == '/')
	{
		if (access(command, X_OK) == 0) {
			return strdup(command);
		} else
			return NULL;
	}

	if (path == NULL) {
		fprintf(stderr, "Error: PATH environment variable not set\n");
		exit(EXIT_FAILURE);
	}

	while (token != NULL) {

		char *full_path = (char *)malloc(strlen(token) + strlen(command) + 2);
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (access(full_path, X_OK) == 0) {
			free(path_copy);
			return full_path;
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return NULL;
}
/**
 * exe_cmd - function to execute the command typed
 * @argv: an array of the comand line arguments
 */
void exe_cmd(char **argv)
{
char *command_typed = NULL;
char *final_command = NULL;
char *envp[] = { NULL };
int status;
if (argv)
{
command_typed = argv[0];
final_command = get_path(command_typed);
if (final_command)
{
pid_t pid = fork();
if (pid == 0)
{
if (execve(final_command, argv, envp) == -1)
{
perror("Error");
exit(1);
}
}
else if (pid < 0)
perror("Fork failed");
else
wait(&status);
}
else
{
fprintf(stderr, "hsh: %d: %s: not found\n", 1, argv[0]);
}
}
}
