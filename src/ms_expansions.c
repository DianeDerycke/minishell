/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expansions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:18:40 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/16 16:05:11 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

ssize_t    ms_tilde_expansion(char **arg, char **ms_env)
{
    size_t  index;

    index = 0;
    if (find_variable("HOME", ms_env, &index) == 0)
    {
        ft_strdel(arg);
        *arg = get_variable_path(ms_env[index]);
    }
    else
        return (undefined_variable("HOME"));
    return (SUCCESS);
}

ssize_t 	ms_dollar_expansion(char **arg, char *var, char **ms_env)
{
    char    *tmp;
    size_t  i;
    size_t  index;

    index = 0;
    i = 0;
    tmp = NULL;
    if (var[0] == '{' && var[ft_strlen(var) - 1] == '}')
        tmp = ft_strndup(var + 1, ft_strlen(var) - 2);
    else
        tmp = ft_strdup(var);
    if (!tmp)
        malloc_error();
    if (find_variable(tmp, ms_env, &index) == 0)
    {
        ft_strdel(arg);
        *arg = get_variable_path(ms_env[index]);
    }
    else
        return (undefined_variable(tmp));
    ft_strdel(&tmp);
    return (SUCCESS);
}

ssize_t 	ms_expansions(char **split_cmd, char **ms_env)
{
	size_t		i;

	i = 0;
	while (split_cmd[i])
	{
		if (split_cmd[i][0] == '$')
        {
			if (ms_dollar_expansion(split_cmd + i, *(split_cmd + i) + 1, ms_env) == 1)
                return (FAILURE);
        }
		else if (ft_strcmp(split_cmd[i], "~") == 0)
            if (ms_tilde_expansion(split_cmd + i, ms_env) == 1)
                return (FAILURE);
		i++;
	}
    return (SUCCESS);
}