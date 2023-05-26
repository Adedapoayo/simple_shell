#include "shell.h"

int main(int agc, char **agv)
{
    char *prmt = "$ ", *exiting = "Exinting shell....";
    char *input = NULL, *input_dup = NULL;
    size_t input_len = 0;
    ssize_t stdinput;
    const char *dlimter = " \n";
    int numof_tok = 0;
    char *tok;
    int v;

    /* declaring void variables */
    (void)agc;

    /* Create a loop for the shell's prompt */
    while (1)
    {
        write(STDOUT_FILENO, prmt, 2);
        stdinput = getline(&input, &input_len, stdin);
        /* check if the getline function failed or reached EOF or user use CTRL + D */
        if (stdinput == -1)
        {
            write(STDOUT_FILENO, exiting, 14);
            return (-1);
        }

        /* allocate space for a copy of the lineptr */
        input_dup = malloc(sizeof(char) * stdinput);
        if (input_dup == NULL)
        {
            perror("tsh: memory allocation error");
            return (-1);
        }
        /* copy lineptr to lineptr_copy */
        stringcpy(input_dup, input);

        /********** split the string (lineptr) into an array of words ********/
        /* calculate the total number of tokens */
        tok = strtok(input, dlimter);

        while (tok != NULL)
        {
            numof_tok++;
            tok = strtok(NULL, dlimter);
        }
        numof_tok++;

        /* Allocate space to hold the array of strings */
        agv = malloc(sizeof(char *) * numof_tok);

        /* Store each token in the argv array */
        tok = strtok(input_dup, dlimter);

        for (v = 0; tok != NULL; v++)
        {
            agv[v] = malloc(sizeof(char) * _strlen(tok));
            stringcpy(agv[v], tok);

            tok = strtok(NULL, dlimter);
        }
        agv[v] = NULL;

        /* execute the command */
        exec(agv);
    }

    /* free up allocated memory */
    free(input_dup);
    free(input);

    return (0);
}
