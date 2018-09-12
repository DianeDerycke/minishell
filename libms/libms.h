/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libms.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:09:16 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/09/12 17:12:32 by DERYCKE          ###   ########.fr       */
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

# define PAGAIN 1
# define ERR_INTR -1
# define VAL_BACKSPACE 92
# define VAL_EQUAL 61
# define STR_EQUAL "="
# define VAL_DASH 45
# define DEFAULT_PATH "/usr/local/bin:/bin:/usr/bin:/usr/sbin:/sbin"

char        **ms_get_env(void);
ssize_t     ms_read_input(char **input);
char	    **ms_clean_input(char **input);
char        *ms_create_variable(char *var_name, char *var_value);
void	    ms_malloc_error(void);
void	    ms_exec_binary(char *utility, char **split_cmd, char **env);
char		*ms_get_valid_cmd(char *cmd, char **ms_env);
char        *ms_find_path_variable(char **ms_env);

//ERROR
ssize_t		ms_command_not_found(char *cmd);


#endif