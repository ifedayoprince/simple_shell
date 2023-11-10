#include "../../main.h"

command_t *parse_command(char *commandStr)
{
    int p = strlen(commandStr);
    int i = 0;
    command_t *command;

    char *buffer = calloc(MAX_STRING_LENGTH, sizeof(char));
    int argsCounter = 0;
    char **args = calloc(1, sizeof(buffer));

    int position_pointer = 0;
    bool counterStart = false;

    if (buffer == NULL || args == NULL)
        return (NULL);

    for (i = 0; i < p - 1; i++)
    {
        char c = commandStr[i];

        // Ignore trailing whitespace
        if (c == ' ' && (commandStr[i + 1] == ' ' || commandStr[i + 1] == '\n'))
            continue;
        else if (c == ' ' && !counterStart) // Skip leading whitespace
            continue;
        else if (c == ' ' || c == '\n')
        {
            args = realloc(args, sizeof(buffer) * (argsCounter + 2));
            if (args == NULL)
                return (NULL);

            args[argsCounter] = strdup(buffer);
            argsCounter++;

            free(buffer);
            buffer = calloc(MAX_STRING_LENGTH, sizeof(char));
            if (buffer == NULL)
                return (NULL);

            position_pointer = 0;
        }
        else
        {
            counterStart = true;
            buffer[position_pointer] = c;
            position_pointer++;
        }
    }

    args[argsCounter + 1] = NULL;

    // print_arguments(args, argsCounter);
    free(buffer);
    
    command = malloc(sizeof(command_t));

    command->name = args[0];
    command->args = args;
    command->argc = argsCounter;

    print_command_to_screen(command);

    return command;
}
