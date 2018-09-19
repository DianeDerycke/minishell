#ifndef MINISHELL_H
#define MINISHELL_H

# include "../libft/libft.h"
# include "../libms/libms.h"
# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>

# define ARRAY_SIZE 5
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

//builtins.c
int 				find_builtin(char *cmd, t_builtin *builtins);

//cd.c
ssize_t				ms_cd(char **split_cmd, char ***ms_env);
ssize_t     		cd_to_env_var(char **ms_env, char *var_name);
ssize_t     		edit_oldpwd_var(char ***ms_env, char **buf);

//echo.c
ssize_t				ms_echo(char **split_cmd, char ***ms_env);
void				display_echo_arg(char **split_cmd, size_t index);
ssize_t				has_echo_opt(char **split_cmd, size_t *index);

//env.c
ssize_t				ms_env(char **split_cmd, char ***ms_env);
void    			add_argument_to_env(char **split_cmd, char **env);
char      			**find_first_bin(char **split_cmd, int c);
ssize_t    			apply_options(char **split_cmd, t_opt opt, char **ms_env);
char        		**create_tmp_env(char **split_cmd);

//parser env
void	     		init_env_options(char **split_cmd, t_opt *env_opt);
void				valid_option(char c, t_opt *env_opt);

//setenv.c
ssize_t				ms_setenv(char **split_cmd, char ***ms_env);
ssize_t     		is_valid_set_cmd(char **split_cmd);
char				**add_variable(char *var_name, char *var_value, char **ms_env);
char				**set_var_env(char **split_cmd, char **ms_env);

//unsetenv.c
ssize_t				ms_unsetenv(char **split_cmd, char ***ms_env);
char			    **delete_variable(char **ms_env, size_t index);


//expansions.c
ssize_t				apply_expansions(char **split_cmd, char **ms_env);
ssize_t   			tilde_expansion(char **arg, char **ms_env);
ssize_t				dollar_expansion(char **arg, char **ms_env, char *start_var);

//exec_cmd.c
ssize_t				exec_cmd(char ***ms_env, char ***split_cmd, t_builtin *builtins);

//error.c
void				error_option(char c);
ssize_t				too_many_args(char *cmd);
ssize_t				unvalid_setenv_cmd(void);

//error2.c
ssize_t     		too_few_args(void);
ssize_t     		error_chdir(int error, char *path);
ssize_t			    undefined_variable(char *var);

//utils.c
char				*get_variable_path(char *var);
char    			*get_variable_name(char *arg, size_t bs_index);//change name function
void    			join_path_rest(char **arg, char *var_value, size_t bs_index);
char				*join_beginning_path(char *str, char *str2, char c);


//init.c
void				init_builtin_struct(t_builtin *builtin_tab);
void				init_opt_struct(t_opt 	*env_opt);

#endif