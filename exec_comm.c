#include "shell.h"
/**
*exec_comm - executes the command givven by user
@ arg - agru
return: void
*/

void exec_comm(char **arv)
{
char *comm = NULL, *actual_com = NULL;

    if (arv){
        /* get the command */
        comm = arv[0];
		
		actual_com = get_loc(comm);

        /* execute the command with execve */
        if (execve(actual_com, arv, NULL) == -1){
            perror("Error: cant exec");
        }
    }	
}
