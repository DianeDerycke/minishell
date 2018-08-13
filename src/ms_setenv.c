/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 19:11:59 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/13 13:25:35 by DERYCKE          ###   ########.fr       */
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

void    reset_variable(char **split_cmd, char **ms_env, ssize_t index)
{
    ft_strdel(&(ms_env[index]));
    ms_env[index] = create_line(split_cmd);
}

void    add_variable(char **split_cmd, char **ms_env)
{
    char    **tmp_ms_env;

    tmp_ms_env = ft_copy_array(ms_env, ft_strlen_table(ms_env) + 1);
    ft_free_array(ms_env);
    tmp_ms_env[(ft_strlen_table(tmp_ms_env) - 1)] = create_line(split_cmd);
    ms_env = ft_copy_array(tmp_ms_env, ft_strlen_table(tmp_ms_env));
}

void     set_var_env(char **split_cmd, char **ms_env)
{
    ssize_t     index;

    index = 0;
    if ((index = find_variable(split_cmd, ms_env)) >= 0)
        reset_variable(split_cmd, ms_env, index);
    else
        add_variable(split_cmd, ms_env);
}

ssize_t    ms_setenv(char **split_cmd, char **ms_env)
{   
    size_t     i;
    size_t     len_split_cmd;
    char        **tmp;

    i = 1;
    len_split_cmd = ft_strlen_table(split_cmd);
    tmp = NULL;
    if (len_split_cmd == 1)
        ft_print_array(ms_env);
    else if (len_split_cmd > 3)
        return (setenv_error_args());
    else if ((is_valid_set_cmd(split_cmd)) == 1)
        return (FAILURE);
    else
        set_var_env(split_cmd, ms_env);
	return (SUCCESS);
}