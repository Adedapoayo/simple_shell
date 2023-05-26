#include "shell.h"

char *getloc(char *comm){
    char *path, *path_dup, *pathtok, *full_fpath;
    int commlen, dirlen;
    struct stat buff;

    path = getenv("PATH");

    if (path){
        /* Duplicate the path string -> remember to free up memory for this because strdup allocates memory that needs to be freed*/ 
        path_dup = strdup(path);
        /* Get length of the command that was passed */
        commlen = _strlen(comm);

        /* Let's break down the path variable and get all the directories available*/
        pathtok = strtok(path_dup, ":");

        while(pathtok != NULL){
            /* Get the length of the directory*/
            dirlen = _strlen(pathtok);
            /* allocate memory for storing the command name together with the directory name */
            full_fpath = malloc(commlen + dirlen + 2); /* NB: we added 2 for the slash and null character we will introduce in the full command */
            /* to build the path for the command, let's copy the directory path and concatenate the command to it */
            stringcpy(full_fpath, pathtok);
            _mystrcat(full_fpath, "/");
            _mystrcat(full_fpath, comm);
            _mystrcat(full_fpath, "\0");

            /* let's test if this file path actually exists and return it if it does, otherwise try the next directory */
            if (stat(full_fpath, &buff) == 0){
                /* return value of 0 means success implying that the file_path is valid*/

                /* free up allocated memory before returning your file_path */
                free(path_dup);

                return (full_fpath);
            }
            else{
                /* free up the file_path memory so we can check for another path*/
                free(full_fpath);
                pathtok = strtok(NULL, ":");

            }

        }

        /* if we don't get any file_path that exists for the command, we return NULL but we need to free up memory for path_copy */ 
        free(path_dup);

        /* before we exit without luck, let's see if the command itself is a file_path that exists */
        if (stat(comm, &buff) == 0)
        {
            return (comm);
        }


        return (NULL);

    }


    return (NULL);
}
