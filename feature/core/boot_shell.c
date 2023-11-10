#include "../../main.h"

void boot_shell()
{
    char ch;
    char *command = calloc(MAX_STRING_LENGTH, sizeof(char));

    if (command == NULL)
        return;

    while (true)
    {
        write(STDOUT_FILENO, "($) ", 4);

        read(STDIN_FILENO, command, MAX_STRING_LENGTH);
        execute_command(command);
    }
}
