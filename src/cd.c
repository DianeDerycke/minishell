/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:44:35 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/09/19 16:12:30 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

ssize_t     cd_to_env_var(char **ms_env, char *var_name)
{
    size_t      index;
    ssize_t     error;

    error = ms_find_variable(var_name, ms_env, &index);
    if (error == -1)
        return (FAILURE); //VARIABLE DOES NOT EXIST ERROR
    if ((chdir(ms_env[index] + (ft_strlen(var_name) + 1)) == SUCCESS))
        return (SUCCESS);
    return (FAILURE);
}

ssize_t     edit_oldpwd_var(char ***ms_env, char **buf)
{
    size_t      index;

    if (ms_find_variable("OLDPWD", *ms_env, &index) == -1)
        return (FAILURE);
    ms_edit_variable("OLDPWD", *buf, ms_env, index);
    ft_strdel(buf);
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
        if (cd_to_env_var(*ms_env, HOME) == FAILURE)
        {
            ft_strdel(&buf);
            return (FAILURE);
        }
    }
    else if (len_cmd == 2 && ft_strcmp(split_cmd[1], "-") == 0)
    {
        if (cd_to_env_var(*ms_env, OLDPWD) == FAILURE)
        {
            ft_strdel(&buf);
            return (FAILURE);
        }
    }
    else if ((error = chdir(split_cmd[1])) < 0)
    {
        ft_strdel(&buf);
        return (error_chdir(error, split_cmd[1], "cd"));
    }
    if (edit_oldpwd_var(ms_env, &buf) == FAILURE || ms_edit_pwd_var(ms_env) == FAILURE)
        return (FAILURE);
    ft_strdel(&buf);
    return (SUCCESS);
}