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
	ssize_t			(*function)(char **, char ***);
}					t_builtin;

typedef struct 		s_opt
{
	ssize_t			i;
	ssize_t			p;
	ssize_t			s;
	ssize_t			u;
	ssize_t			v;
}					t_opt;

//parser.c
char				*find_path(char *cmd, char **ms_env);
void				ms_remove_quote_cmd(char **split_cmd);
char				**ms_split_input(char **input);

//parser env
ssize_t     		is_valid_env_options(char **split_cmd, t_opt env_opt);

//builtins.c
int 				find_builtin(char *cmd, t_builtin *builtins);

//exec_cmd.c
ssize_t				exec_cmd(char ***ms_env, char **split_cmd, t_builtin *builtins);

//env.c
ssize_t    			exec_env_cmd(char **split_cmd, char **ms_env, t_opt env_opt);


// BUILTINS FILES
ssize_t				ms_echo(char **split_cmd, char ***ms_env);
ssize_t				ms_env(char **split_cmd, char ***ms_env);
ssize_t				ms_setenv(char **split_cmd, char ***ms_env);
ssize_t				ms_unsetenv(char **split_cmd, char ***ms_env);
ssize_t				ms_cd(char **split_cmd, char ***ms_env);

//ms_setenv.c
ssize_t     		is_valid_set_cmd(char **split_cmd);
char				**edit_variable(char **split_cmd, char **ms_env, ssize_t index);
char    			**add_variable(char **split_cmd, char **ms_env);
char			    **delete_variable(char **ms_env, size_t index);
char     			**set_var_env(char **split_cmd, char **ms_env);

//error.c
void				malloc_error(void);
ssize_t				command_not_found(char *cmd);
ssize_t				error_option(char c);
ssize_t				too_many_args(void);
ssize_t				unvalid_setenv_cmd(void);

//error2.c
ssize_t     		too_few_args(void);


//utils.c
char				*ms_getenv(char **ms_env);
int					ms_read_input(char **cmd);
size_t				len_without_char(char *str, char c);
ssize_t				find_variable(char *cmd, char **ms_env, size_t *index);
char    			*create_line(char **split_cmd);

//init.c
void				init_builtin_struct(t_builtin *builtin_tab);
void				init_opt(t_opt 	*env_opt);


#endif

//change name function with ms/setenv