#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void exec_cmd(char *argv[], char **env, char **av);
void prompt(char **av, char **env);
void print_prompt(void);
ssize_t get_user_input(char **str, size_t *n);
void cleanup_and_exit(char *str);
void process_input(char *str);
int main(int ac, char **av, char **env);

#endif
