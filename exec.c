#include "shell.h"
void exec(char **agv){
    char *comm = NULL, *actualcomm = NULL;

    if (agv){
        /* get the command */
        comm = agv[0];

        /* generate the path to this command before passing it to execve */
        actualcomm = getloc(comm);

        /* execute the actual command with execve */
        if (execve(actualcomm, agv, NULL) == -1){
            perror("Error:");
        }
    }

}
