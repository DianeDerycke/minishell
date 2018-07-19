#ifndef MINISHELL_H
#define MINISHELL_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct 		s_builtin
{
	char			*name;
	void			(*function)(char **);
}					t_builtin;

//parser.c
char				*find_path(char *cmd, char **ms_env);

//builtins.c
void				init_builtins(t_builtin *builtin_tab);
int 				find_builtin(char *str, t_builtin *builtins);

//exec_cmd.c
void				exec_cmd(char **ms_env, char **split_cmd, t_builtin *builtins);

//echo.c
void				ms_echo(char **array);


//error.c
void				malloc_error(void);
void				command_not_found(char *path);

//utils.c
char				*ms_getenv(char **ms_env);
#endif