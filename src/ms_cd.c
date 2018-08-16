/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:44:35 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/16 15:58:02 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

ssize_t     ms_cd_home(char **ms_env)
{
    size_t      index;
    ssize_t     error;

    error = find_variable("HOME", ms_env, &index);
    if (error == -1)
        return (FAILURE);
    if ((chdir(ms_env[index] + 5)) == 0)
        return (SUCCESS);
    return (FAILURE);
}

ssize_t     edit_oldpwd(char *path, char **ms_env)
{
    size_t      index;
    ssize_t     error;

    error = find_variable("OLDPWD", ms_env, &index);
    if (error == -1)
        return (FAILURE);
    edit_variable("OLDPWD", path, ms_env, index);
    return (SUCCESS);
}

ssize_t    ms_cd(char **split_cmd, char ***ms_env)
{
    char    *buf;
    size_t  len;
    int     error;

    len = ft_strlen_table(split_cmd);
    if (!(buf = malloc(2048)))
        malloc_error();
    getcwd(buf, 2048);
    if (len > 2)
        too_many_args("cd");
    if (len == 1)
    {
        if (ms_cd_home(*ms_env) == 1)
            return (FAILURE);
    }
    else if ((error = chdir(split_cmd[1])) != 0)
        return (error_chdir(error, split_cmd[1]));
    ft_strdel(&buf);
    if (edit_oldpwd(buf, *ms_env) == 1)
        return (FAILURE);
    return (SUCCESS);
}

//handle chdir error