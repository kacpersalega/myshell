#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMMANDSIZE 1024

int main(int argc, char *argv[]) {
    // Flush after every printf
    setbuf(stdout, NULL);

    // buffer for storing commands typed by user
    char command[COMMANDSIZE];

    while (1)
    {
        printf("$ ");

        // stores what user typed in 'command' array.
        fgets(command, sizeof(command), stdin);

        // removes trailing newline character from command
        command[strcspn(command, "\r\n")] = 0;

        if (strcmp(command, "exit") == 0)
        {
            break;
        }
        else if (strncmp(command, "echo ", 5) == 0)
        {
            printf("%s\n", command + 5);
        }
        else if (strncmp(command, "type ", 5) == 0)
        {
            if (strncmp(command + 5, "echo", 4) == 0)
            {
                printf("%s is a shell builtin\n", command + 5);
            }
            else if (strncmp(command + 5, "type", 4) == 0)
            {
                printf("%s is a shell builtin\n", command + 5);
            }
            else if (strncmp(command + 5, "exit", 4) == 0)
            {
                printf("%s is a shell builtin\n", command + 5);
            }
            else
            {
                printf("%s: not found\n", command + 5);
            }
        }
        else
        {
            printf("%s: not found\n", command);
        }

    }


    return 0;
}
