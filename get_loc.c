#include "shell.h"

char *get_loc(char *comm)
{
char *path, *path_dup, *path_tokniz, *full_path;
int v, path_len, dir_len = 0;
struct stat buff;

	path = getenv("PATH");

if(path)
{
	/* get path length */
    while (path[path_len] != '\0')
	{
        path_len++;
    }
    /*Allocate memory for the duplicated string*/
    path_dup = (char*)malloc((path_len + 1) * sizeof(char));
    
    /* duplicated string*/
    for (v = 0; v < path_len; v++)
    {
        path_dup[v] = path[v];
    }
    
    /* Add the null terminator at the end*/
    path_dup[path_len] = '\0';
	
	path_tokniz = strtok(path_dup, ":");
	/* get path length */
	while(path_tokniz != NULL)
	{
	while(path_tokniz[dir_len] != '\0')
	{
		dir_len++;
	}
	full_path = malloc(path_len + dir_len + 2);
	full_path = path_tokniz;
	cated_str = cat_strs(full_path, "/", "\0", NULL);
	
	free(cated_str);
	
	if(stat(full_path, &buff) == 0)
	{
		free(path_dup);
		
		return(full_path);
	}
	else{
		free(full_path);
		
		path_tokniz = strtok(NULL, ":");
	}
}
free(path_dup);

if (stat(comm, &buff) == 0)
{
	return(comm);
}
return(NULL);
	}
	return(NULL);
}
