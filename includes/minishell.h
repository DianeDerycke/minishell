#ifndef MINISHELL_H
#define MINISHELL_H

#include "../libft/libft.h"
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>

typedef struct 		s_builtin
{
	char			*built_name;
	void			(*built_ft)(void *);
}					t_builtin;

//parser.c
char		*find_path(char *cmd, char **ms_env);

//exec_cmd.c
void		exec_cmd(char **ms_env, char **array);


//error.c
void		malloc_error(void);
void		command_not_found(char *path);

//utils.c
char		*ms_getenv(char **ms_env);
#endif