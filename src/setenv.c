/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 19:11:59 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/30 13:25:58 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
ssize_t     is_valid_set_cmd(char **split_cmd)
{
    size_t      i;
    size_t      j;

    j = 0;
    i = 1;
    while (split_cmd[i])
    {
        if (ft_str_isalnum(split_cmd[i]) == 1)
            return (FAILURE);
        i++;
    }
    return (SUCCESS);
}

char    **edit_variable(char *var_name, char *var_value, char **ms_env, ssize_t index)
{
    ft_strdel(&(ms_env[index]));
    ms_env[index] = ms_create_variable(var_name, var_value);
    return (ms_env);
}

char    **add_variable(char **split_cmd, char ***ms_env)
{
    char    **tmp_ms_env;
    size_t  len_tmp;

    len_tmp = 0;
    if (!(tmp_ms_env = ft_copy_array(*ms_env, ft_strlen_array(*ms_env) + 1)))
        ms_malloc_error();
    len_tmp = ft_strlen_array(tmp_ms_env);
    ft_free_array(*ms_env);
    if (ft_strlen_array(split_cmd) == 3)
        tmp_ms_env[len_tmp] = ms_create_variable(split_cmd[1], split_cmd[2]);
    else
        tmp_ms_env[len_tmp] = ms_create_variable(split_cmd[1], NULL);
    return (tmp_ms_env);
}

char     **set_var_env(char **split_cmd, char ***ms_env)
{
    size_t     index;

    index = 0;
    if (find_variable(split_cmd[1], *ms_env, &index) == 0)
    {
        if (ft_strlen_array(split_cmd) == 3)
            edit_variable(split_cmd[1], split_cmd[2], *ms_env, index);
        else
            edit_variable(split_cmd[1], NULL, *ms_env, index);
    //to do: fix if/else to only if
    }
    else
        *ms_env = add_variable(split_cmd, ms_env);
    return (*ms_env);
}

ssize_t    ms_setenv(char **split_cmd, char ***ms_env)
{   
    size_t     i;
    size_t     len_split_cmd;

    i = 1;
    len_split_cmd = ft_strlen_array(split_cmd);
    if (len_split_cmd == 1)
        ft_print_array(*ms_env);
    else if (len_split_cmd > 3)
        return (too_many_args("setenv"));
    else if ((is_valid_set_cmd(split_cmd)) == 1)
        return (unvalid_setenv_cmd());
    else
        *ms_env = set_var_env(split_cmd, ms_env);
	return (SUCCESS);
}