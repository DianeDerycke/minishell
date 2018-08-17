/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expansions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:18:40 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/17 16:48:07 by DERYCKE          ###   ########.fr       */
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

ssize_t 	ms_dollar_expansion(char **arg, char **ms_env)
{
    char    *tmp;
    char    *tmp2;
    size_t  i;
    size_t  index;

    index = 0;
    i = 0;
    tmp2 = NULL;
    if (!*arg)
        return (FAILURE);
    if ((*arg)[1] == '{' && (*arg)[ft_strlen((*arg)) - 1] == '}')
        tmp = ft_strndup(*arg + 2, ft_strlen((*arg)) - 2);
    else if ((ft_find_char(*arg, 92, &i)) == 0)
        tmp = ft_strndup(*arg + 1, i);
    else
        tmp = ft_strdup(*arg + 1);
    if (!tmp)
        malloc_error();


    if (find_variable(tmp, ms_env, &index) == 0)
    {
        ft_strdel(&tmp);
        if (i > 0)
        {
            tmp = get_variable_path(ms_env[index]);
            tmp2 = ft_strdup(*arg + i + 1);
            ft_strdel(arg);
            *arg = ft_strjoin_free(tmp, tmp2);
            ft_strdel(&tmp2);
        }
        else
            {
                ft_strdel(arg);
                *arg = get_variable_path(ms_env[index]);
            }
        return (SUCCESS);
    }
    else
    {
        undefined_variable(tmp);
        ft_strdel(&tmp);
        return (FAILURE);
    }
}

ssize_t 	ms_expansions(char **split_cmd, char **ms_env)
{
	size_t		i;

	i = 0;
	while (split_cmd[i])
	{
		if (split_cmd[i][0] == '$')
        {
			if (ms_dollar_expansion(split_cmd + i, ms_env) == 1)
                return (FAILURE);
        }
		else if (ft_strcmp(split_cmd[i], "~") == 0)
            if (ms_tilde_expansion(split_cmd + i, ms_env) == 1)
                return (FAILURE);
		i++;
	}
    return (SUCCESS);
}