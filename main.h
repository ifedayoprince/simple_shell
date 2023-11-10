#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_STRING_LENGTH 256

typedef struct
{
    char* name;
    // char* env[4];
    int argc;
    char **args;
} command_t;


void boot_shell();
void execute_command(char *commandStr);
command_t* parse_command(char *commandStr);


// Printer functions for debugging
void print_command_to_screen(command_t *cmd);
void print_arguments(char **args, int argc);

#endif
