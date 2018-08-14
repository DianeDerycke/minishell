/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 19:11:59 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/14 16:08:38 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
ssize_t     is_valid_set_cmd(char **split_cmd)
{
    size_t      i;

    i = 1;
    while (split_cmd[i])
    {
        if (ft_str_isalnum(split_cmd[i]) == 1)
            return (FAILURE);
        i++;
    }
    return (SUCCESS);
}

char    **edit_variable(char **split_cmd, char **ms_env, ssize_t index)
{
    ft_strdel(&(ms_env[index]));
    ms_env[index] = create_line(split_cmd);
    return (ms_env);
}

char    **add_variable(char **split_cmd, char **ms_env)
{
    char    **tmp_ms_env;

    if (!(tmp_ms_env = ft_copy_array(ms_env, ft_strlen_table(ms_env) + 1)))
        malloc_error();
    // ft_free_array(ms_env);
    tmp_ms_env[(ft_strlen_table(tmp_ms_env))] = create_line(split_cmd);
    if (!(ms_env = ft_copy_array(tmp_ms_env, ft_strlen_table(tmp_ms_env))))
        malloc_error();
    // ft_free_array(tmp_ms_env);
    return (ms_env);
}

char     **set_var_env(char **split_cmd, char **ms_env)
{
    size_t     index;

    index = 0;
    if (find_variable(split_cmd[1], ms_env, &index) == 0)
        return (edit_variable(split_cmd, ms_env, index));
    else
        return (add_variable(split_cmd, ms_env));
}

ssize_t    ms_setenv(char **split_cmd, char ***ms_env)
{   
    size_t     i;
    size_t     len_split_cmd;

    i = 1;
    len_split_cmd = ft_strlen_table(split_cmd);
    if (len_split_cmd == 1)
        ft_print_array(*ms_env);
    else if (len_split_cmd > 3)
        return (too_many_args());
    else if ((is_valid_set_cmd(split_cmd)) == 1)
        return (unvalid_setenv_cmd());
    else
        *ms_env = set_var_env(split_cmd, *ms_env);
	return (SUCCESS);
}