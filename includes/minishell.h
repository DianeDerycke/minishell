#ifndef MINISHELL_H
#define MINISHELL_H

# include "../libft/libft.h"
# include "../includes/get_next_line.h"
# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>

# define SUCCESS 0
# define FAILURE 1
# define EAGAIN 1
# define EINTR -1

typedef struct 		s_builtin
{
	char			name[20];
	void			(*function)(char **, char **);
}					t_builtin;

//parser.c
char				*find_path(char *cmd, char **ms_env);
void				ms_remove_quote_cmd(char **split_cmd);
char				**ms_split_input(char **input);

//builtins.c
void				init_builtin_struct(t_builtin *builtin_tab);
int 				find_builtin(char *cmd, t_builtin *builtins);

//exec_cmd.c
void				exec_cmd(char **ms_env, char **split_cmd, t_builtin *builtins);

// BUILTINS FILES
void				ms_echo(char **split_cmd, char **ms_env);
void				ms_env(char **split_cmd, char **ms_env);
void				ms_setenv(char **split_cmd, char **ms_env);
void				ms_unsetenv(char **split_cmd, char **ms_env);
void				ms_cd(char **split_cmd, char **ms_env);
//error.c
void				malloc_error(void);
void				command_not_found(char *cmd);

//utils.c
char				*ms_getenv(char **ms_env);
int					ms_read_input(char **cmd);
size_t				len_without_char(char *str, char c);

#endif