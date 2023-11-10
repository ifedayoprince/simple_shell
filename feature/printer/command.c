#include "../../main.h"

void print_command_to_screen(command_t *cmd)
{
    int i = 0;

    printf("\n[name] -> program name is '%s'.\n", cmd->args[0]);

    for (i = 1; i < cmd->argc; i++)
    {
        printf("      [arg] -> argument %d has value '%s'.\n", i, cmd->args[i]);
    }

    printf("\n");
}

void print_arguments(char **args, int argc)
{
    int i = 0;

    for (i = 0; i < argc; i++)
    {
        printf("      [arg] -> argument %d has value '%s'.\n", i, args[i]);
    }

    printf("\n");
}