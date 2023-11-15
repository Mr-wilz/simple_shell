#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

char *get_path(char *command);
void tokenize_line(char *input, const char *delimiters, char **tokens, int *token_count);
void exe_cmd(char **argv);

int main(void);

#endif
