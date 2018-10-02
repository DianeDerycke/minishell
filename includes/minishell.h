/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:56:27 by dideryck          #+#    #+#             */
/*   Updated: 2018/10/02 17:18:33 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "../libms/libms.h"
# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>

# define ARRAY_SIZE 6

typedef struct		s_builtin
{
	char			name[20];
	ssize_t			(*function)(char **, char ***);
}					t_builtin;

typedef struct		s_opt
{
	ssize_t			i;
	ssize_t			p;
	ssize_t			s;
	ssize_t			u;
	ssize_t			v;
}					t_opt;

typedef struct		s_expansion
{
	char	*tmp;
	char	*sub;
	char	*join;
	char	*v_value;
	int		index;
}					t_expansion;
/*
** builtins.c
*/
int					find_builtin(char *cmd, t_builtin *builtins, int ret);

/*
** cd.c
*/
ssize_t				ms_cd(char **split_cmd, char ***ms_env);
ssize_t				cd_to_env_var(char **ms_env, char *var_name);
ssize_t				edit_oldpwd_var(char ***ms_env, char **buf);

/*
** echo.c
*/
ssize_t				ms_echo(char **split_cmd, char ***ms_env);
void				display_echo_arg(char **split_cmd, size_t index);
ssize_t				has_echo_opt(char **split_cmd, size_t *index);

/*
** env.c
*/
ssize_t				ms_env(char **split_cmd, char ***ms_env);
void				add_argument_to_env(char **split_cmd, char ***env);
char				**find_first_bin(char **split_cmd, int c);

/*
** parser env
*/
void				init_env_options(char **split_cmd, t_opt *env_opt);
void				valid_option(char c, t_opt *env_opt);

/*
**  setenv.c
*/
ssize_t				ms_setenv(char **split_cmd, char ***ms_env);
char				**add_variable(char *v_name, char *v_value, char **ms_env);
char				**set_var_env(char **split_cmd, char **ms_env);

/*
** unsetenv.c
*/
ssize_t				ms_unsetenv(char **split_cmd, char ***ms_env);
char				**delete_variable(char **ms_env, size_t index);

/*
** expansions.c
*/
ssize_t				apply_expansions(char **split_cmd, char **ms_env);

/*
** exec_cmd.c
*/
int					exec_cmd(char ***ms_env, char ***cmd, t_builtin *builtins);

/*
** error.c
*/
void				error_option(char c);
ssize_t				too_many_args(char *cmd);
ssize_t				unvalid_setenv_cmd(void);
ssize_t				error_chdir(int error, char *path, char *cmd);

/*
** utils.c
*/
void				join_path_rest(char **arg, char *v_path, size_t bs_index);
char				*join_begin_path(char *str, char *str2, char c);
ssize_t				has_arg(char **split_cmd);
ssize_t				exec_simple_env(char **cmd, char **s_bin, char **env);

/*
** init.c
*/
void				init_builtin_struct(t_builtin *builtin_tab);
void				init_opt_struct(t_opt *env_opt);

/*
** utils2.c
*/
size_t				getnbr_args(char **split_cmd, int c);
char				**find_first_bin(char **split_cmd, int c);
void				copy_add_var_to_env(char ***env, char *name, char *value);

/*
** help.c
*/
ssize_t				ms_help(char **split_cmd, char ***ms_env);

#endif
