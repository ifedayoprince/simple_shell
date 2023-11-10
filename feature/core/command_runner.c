#include "../../main.h"

void execute_command(char* commandStr)
{
    char* argv[] = {"/bin/echo", "hello","world", NULL};

    // command_t *cmd = parse_command(commandStr);
    char* envp[] = {NULL};
    int ret = execve("/bin/echo", argv, envp);


    // free(cmd->args);
    printf("Returned %d\n", ret);
}