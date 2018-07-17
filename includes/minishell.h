#ifndef MINISHELL_H
#define MINISHELL_H

#include "../libft/libft.h"
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>

//SRC
char		*find_path(char *cmd, char **ms_env);

//ERROR
void	malloc_error(void);
void	command_not_found(char *path);

//UTILS
char	*ms_getenv(char **ms_env);

#endif