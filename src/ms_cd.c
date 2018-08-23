/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:44:35 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/23 15:37:56 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

ssize_t     ms_cd_to_home(char **ms_env)
{
    size_t      index;
    ssize_t     error;

    error = find_variable("HOME", ms_env, &index);
    if (error == -1)
        return (FAILURE);
    if ((chdir(ms_env[index] + 5)) == SUCCESS)
        return (SUCCESS);
    return (FAILURE);
}

ssize_t     edit_pwd_var(char **ms_env)
{
    char    *buf;
    size_t  index;

    index = 0;
    buf = NULL;
    if (ms_get_cwd(&buf) || find_variable("PWD", ms_env, &index) == -1)
        return (FAILURE);
    edit_variable("PWD", buf, ms_env, index);
    ft_strdel(&buf);
    return (SUCCESS);
}

ssize_t     edit_oldpwd_var(char **ms_env, char **buf)
{
    size_t      index;

    if (find_variable("OLDPWD", ms_env, &index) == -1)
        return (FAILURE);
    edit_variable("OLDPWD", *buf, ms_env, index);
    ft_strdel(buf);
    return (SUCCESS);
}

ssize_t     ms_get_cwd(char **buf)
{
    if (!(*buf = malloc(MS_BUFF_SIZE)))
        ms_malloc_error();
    if (!(getcwd(*buf, MS_BUFF_SIZE)))
    {
        ft_strdel(buf);
        return (FAILURE);
    }
    return (SUCCESS);
}

ssize_t    ms_cd(char **split_cmd, char ***ms_env)
{
    size_t  len_cmd;
    int     error;
    char    *buf;

    buf = NULL;
    len_cmd = ft_strlen_array(split_cmd);
    if (ms_get_cwd(&buf) == FAILURE)
        return (FAILURE);
    if (len_cmd > 2)
        too_many_args("cd");
    else if (len_cmd == 1)
    {
        if (ms_cd_to_home(*ms_env) == FAILURE)
            return (FAILURE);
    }
    else if ((error = chdir(split_cmd[1])) != 0)
    {
        ft_strdel(&buf);
        return (error_chdir(error, split_cmd[1]));
    }
    if (edit_oldpwd_var(*ms_env, &buf) == FAILURE || edit_pwd_var(*ms_env) == FAILURE)
        return (FAILURE);
    ft_strdel(&buf);
    return (SUCCESS);
}

//to do : clean