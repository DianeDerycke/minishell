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
int		cmd_is_valid(char *path);

//ERROR
void	malloc_error(void);
void	command_not_found(char *path);

#endif