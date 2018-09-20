/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:18:40 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/09/20 14:16:37 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

ssize_t    tilde_expansion(char **arg)
{
    char    *tmp;

    tmp = NULL;
    if (!arg || !(*arg))
        return (FAILURE);
    if ((*arg)[0] == C_TILDE && ft_strlen(*arg) > 1  && (*arg)[1] == C_SLASH)
    {
        if (!(tmp = ft_strdup((*arg) + 1)))
            ms_malloc_error();
        ft_strdel(arg);
        if (!(*arg = ft_strjoin(DEFAULT_HOME, tmp)))
            ms_malloc_error();
        ft_strdel(&tmp);
    }
    else if ((*arg)[0] == C_TILDE)
    {
        ft_strdel(arg);
        if (!(*arg = ft_strdup(DEFAULT_HOME)))
            ms_malloc_error();
    }
    return (SUCCESS);
}

ssize_t 	dollar_expansion(char **arg, char **ms_env, char *start_var)
{
    size_t  bs_index;
    size_t  index;
    char    *var_name;
    char    *tmp;

    tmp = NULL;
    ft_find_char(start_var, VAL_BACKSPACE, &bs_index);
    var_name = get_variable_name(start_var, bs_index);
    if (ms_find_variable(var_name, ms_env, &index) == SUCCESS)
    {
        ft_strdel(&var_name);
        if (bs_index > 0)
            join_path_rest(arg, get_variable_path(ms_env[index]), bs_index);
        else
        {
            tmp = ft_strdup(*arg);
            ft_strdel(arg);
            if (!(*arg = join_beginning_path(tmp, get_variable_path(ms_env[index]), CH_DOLLAR)))
                return (FAILURE);
        }
        return (SUCCESS);
    }
    else
    {
        ms_undefined_variable(var_name);
        ft_strdel(&var_name);
        return (FAILURE);   
    }
}

ssize_t 	apply_expansions(char **split_cmd, char **ms_env)
{
	size_t		i;
    char        *start_var;

	i = 0;
    start_var = NULL;
	while (split_cmd[i])
	{
		if ((start_var = ft_strchr(split_cmd[i], VAL_DOLLAR)))
        {
			if (dollar_expansion(split_cmd + i, ms_env, start_var) == FAILURE)
            {
                ft_free_array(split_cmd);
                return (FAILURE);
            }
        }
		else if ((ft_strcmp(split_cmd[i], "~") == SUCCESS) || ft_strchr(split_cmd[i], VAL_TILDE))
            if (tilde_expansion(split_cmd + i) == FAILURE)
            {
                ft_free_array(split_cmd);
                return (FAILURE);
            }
		i++;
    }
    return (SUCCESS);
}