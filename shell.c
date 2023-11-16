#include "shell.h"
/**
 * main - entry point of the program
 * @ac: line argument count
 * @av: pointer to pointer to the string vector
 * @env: pointer to pointer to the environment variables
 * Return: 0 on success.
 */

int main(int ac, char **av, char **env)
{
	if (ac == 1)
		prompt(av, env);
	return (0);
}
