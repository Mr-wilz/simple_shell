#include "shell.h"

#define MAX_ARGUMENTS 1024

extern char **environ;
int main(void)
{
	char *argv[MAX_ARGUMENTS];
	char **env = environ;
	char *usr_inp = NULL;
	size_t inp_size = 0;
	ssize_t chars_read;
	int num_tokens;

	while (1)
	{
		printf("$ ");
		chars_read = getline(&usr_inp, &inp_size, stdin);
		if (chars_read == -1)
		{
			printf("Shell exited \n");
			free(usr_inp);
			return (-1);
        	}
	tokenize_line(usr_inp, " \n", argv, &num_tokens);	
		if (num_tokens > 0)
		{
			if (strcmp(argv[0], "exit") == 0)
			{
				printf("Shell Exited.. \n");
				free(usr_inp);
				return (0);
			}
			else if (strcmp(argv[0], "env") == 0)
			{
				env = environ;
				while (*env != NULL)
				{
					printf("%s\n", *env);
					env++;
				}
			}
			else
				exe_cmd(argv);
		}
		free(usr_inp);
        	usr_inp = NULL;
	}
	return (0);
}
