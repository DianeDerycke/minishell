/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:44:35 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/15 19:56:21 by DERYCKE          ###   ########.fr       */
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
    else if ((chdir(ms_env[index] + 5)) == 0)
        return (SUCCESS);
    return (FAILURE);
}

// ssize_t     edit_oldpwd(char *path, char **ms_env)
// {

// }

ssize_t    ms_cd(char **split_cmd, char ***ms_env)
{
    char    *buf;
    size_t  len;

    len = ft_strlen_table(split_cmd);
    if (!(buf = malloc(2048)))
        malloc_error();
    getcwd(buf, 2048);
    if (len == 1)
        return (ms_cd_home(*ms_env));
    else if (len > 2)
        too_many_args("cd");
    else if (chdir(split_cmd[1]))
        return (SUCCESS);
    // {
        // edit_oldpwd(buf, *ms_env);
    // }
    return (FAILURE);
}