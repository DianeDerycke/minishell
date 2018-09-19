/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libms.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:09:16 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/09/19 13:09:13 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMS_H
# define LIBMS_H

#include "../libft/libft.h"
#include "get_next_line.h"

# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>

# define HOME "HOME"
# define OLDPWD "OLDPWD"
# define PAGAIN 1
# define ERR_INTR -1
# define STR_EQUAL "="
# define CH_DOLLAR '$'
# define C_WHITESPACE ' '
# define C_DQUOTE '"'
# define C_EQUAL '='
# define VAL_BACKSPACE 92
# define VAL_EQUAL 61
# define VAL_DASH 45
# define VAL_DOLLAR 36
# define MS_BUFF_SIZE 2048
# define DEFAULT_PATH "/usr/local/bin:/bin:/usr/bin:/usr/sbin:/sbin"

char        **ms_get_env(void);
ssize_t     ms_read_input(char **input);
char	    **ms_clean_input(char **input);
char        *ms_create_variable(char *var_name, char *var_value);
void	    ms_malloc_error(void);
ssize_t	    ms_exec_binary(char *utility, char **split_cmd, char **env);
char		*ms_get_valid_cmd(char *cmd, char **ms_env);
char        *ms_find_path_variable(char **ms_env);
ssize_t     ms_get_cwd(char **buf);
ssize_t     ms_edit_pwd_var(char ***ms_env);
ssize_t		ms_find_variable(char *cmd, char **ms_env, size_t *index);
void    ms_edit_variable(char *var_name, char *var_value, char ***ms_env, size_t index);





//ERROR
ssize_t		ms_command_not_found(char *cmd);
ssize_t     ms_no_such_file_or_dir(char *utility, char *cmd);
ssize_t    ms_perm_denied(char *utility);

#endif