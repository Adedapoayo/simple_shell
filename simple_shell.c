#include "shell.h"

int mainshell(int arc, char *arv[])
{
  char *prmt = "$ ";
  char *input = NULL, *input_cpy = NULL;
  size_t input_len = 0; 
  ssize_t stdinput;
  const char *dlimiter = " ";
  char *split;
  int numof_toks = 0; 
  int token_length = 0;
  int v;

 /* declaring void variables */
 (void)arc;

  while(1)
  {
/*print prompt*/
 write(STDOUT_FILENO, prmt, 2);
 /*getline from stdinput*/
  stdinput = getline(&input, &input_len, stdin);
  if (stdinput == -1)
  {
	  perror("ERROR (nothing entered in stdinput)");
	  free(input);
      exit(EXIT_FAILURE);
  }
  /*allocate spaces for the copy of the input*/
  input_cpy = malloc(sizeof(char) * stdinput);
  if (input_cpy == NULL)
  {
	  perror("maloc error for inputcpy");
	  exit(EXIT_FAILURE);
  }
  
  stringcpy(input_cpy, input);
  /*split strings*/
  split = strtok(input, dlimiter);
  
  while(split != NULL)
  {
	  numof_toks++;
	  split = strtok(NULL, dlimiter);
  }
  numof_toks++;
  
  arv = malloc(sizeof(char *) *numof_toks);
 
split = strtok(input_cpy, dlimiter);

for(v = 0; split != NULL; v++)
{
	while(split[token_length] != '\0'){
		token_length++;
	}
	arv[v] = malloc(sizeof(char) * (token_length + 1));

	stringcpy(arv[v], split);
	
	split = strtok(NULL, dlimiter);
}
arv[v] = NULL;

exec_comm(arv);
}

free(input_cpy);
  free(input);
  return (0);
}
