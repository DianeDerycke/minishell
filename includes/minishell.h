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
# define MS_BUFF_SIZE 2048
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

//ms_cd.c
ssize_t				ms_cd(char **split_cmd, char ***ms_env);
ssize_t     		ms_cd_to_home(char **ms_env);
ssize_t     		edit_pwd_var(char **ms_env);
ssize_t     		edit_oldpwd_var(char **ms_env, char **buf);
ssize_t     		ms_get_cwd(char **buf);

//ms_echo.c
ssize_t				ms_echo(char **split_cmd, char ***ms_env);
void				ms_display_echo_arg(char **split_cmd, size_t index);
ssize_t				ms_is_echo_opt(char **split_cmd, size_t *index);

//ms_env.c
ssize_t				ms_env(char **split_cmd, char ***ms_env);
void    			add_argument_to_env(char **split_cmd, char **env);
ssize_t    			apply_options(char **split_cmd, char **env);



//ms_parser env
void	     		init_env_options(char **split_cmd, t_opt *env_opt);
void				valid_option(char c, t_opt *env_opt);

//ms_setenv.c
ssize_t				ms_setenv(char **split_cmd, char ***ms_env);
ssize_t     		is_valid_set_cmd(char **split_cmd);
char    			**edit_variable(char *var_name, char *var_value, char **ms_env, ssize_t index);
char    			**add_variable(char **split_cmd, char ***ms_env);
char     			**set_var_env(char **split_cmd, char ***ms_env);

//ms_unsetenv.c
ssize_t				ms_unsetenv(char **split_cmd, char ***ms_env);
char			    **delete_variable(char **ms_env, size_t index);


//ms_expansions.c
ssize_t				ms_apply_expansions(char **split_cmd, char **ms_env);
ssize_t   			ms_tilde_expansion(char **arg, char **ms_env);
ssize_t				ms_dollar_expansion(char **arg, char **ms_env);

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
ssize_t				find_variable(char *cmd, char **ms_env, size_t *index);
//utils2.c
char				*get_variable_path(char *var);
char    			*get_variable_name(char *arg, size_t bs_index);//change name function
void    			join_path_rest(char **arg, char *var_path, size_t bs_index);

//init.c
void				init_builtin_struct(t_builtin *builtin_tab);
void				init_opt_struct(t_opt 	*env_opt);

#endif