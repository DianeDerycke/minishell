/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expansions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:18:40 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/20 15:33:21 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

ssize_t    ms_tilde_expansion(char **arg, char **ms_env)
{
    size_t  index;

    index = 0;
    if (find_variable("HOME", ms_env, &index) == SUCCESS)
    {
        ft_strdel(arg);
        *arg = get_variable_path(ms_env[index]);
    }
    else
        return (undefined_variable("HOME"));
    return (SUCCESS);
}

ssize_t 	ms_dollar_expansion(char **arg, char **ms_env)
{
    size_t  bs_index;
    size_t  index;
    char    *var_name;

    ft_find_char(*arg, BACKSPACE, &bs_index);
    var_name = get_variable_name(*arg, bs_index);
    if (find_variable(var_name, ms_env, &index) == SUCCESS)
    {
        ft_strdel(&var_name);
        if (bs_index > 0)
            join_path_rest(arg, get_variable_path(ms_env[index]), bs_index);
        else
        {
            ft_strdel(arg);
            *arg = get_variable_path(ms_env[index]);
        }
        return (SUCCESS);
    }
    else
    {
        undefined_variable(var_name);
        ft_strdel(&var_name);
        return (FAILURE);   
    }
}

ssize_t 	ms_apply_expansions(char **split_cmd, char **ms_env)
{
	size_t		i;

	i = 0;
	while (split_cmd[i])
	{
		if (split_cmd[i][0] == '$')
        {
			if (ms_dollar_expansion(split_cmd + i, ms_env) == FAILURE)
                return (FAILURE);
        }
		else if (ft_strcmp(split_cmd[i], "~") == SUCCESS)
            if (ms_tilde_expansion(split_cmd + i, ms_env) == FAILURE)
                return (FAILURE);
		i++;
	}
    return (SUCCESS);
}