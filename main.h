#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_STRING_LENGTH 256

void boot_shell(void);
void execute_command(char command[]);

#endif
