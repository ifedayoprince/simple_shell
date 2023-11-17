#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
 * File: main.h
 * Auth: Ifedayo Oni, Muhammad Yusuf
*/

#define MAX_STRING_LENGTH 256

void boot_shell(void);
void execute_command(char command[]);
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

#endif
