/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:18:40 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/10/01 14:39:41 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

ssize_t		tilde_expansion(char **arg)
{
	char	*tmp;

	tmp = NULL;
	if (!arg || !(*arg))
		return (FAILURE);
	if ((*arg)[0] == C_TILDE && ft_strlen(*arg) > 1 && (*arg)[1] == C_SLASH)
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

ssize_t		dollar_expansion(char **arg, char **env, char *start_var)
{
	size_t		i;
	ssize_t		ret;
	size_t		bs_index;
	char		*tmp;

	ret = 0;
	ft_find_char(start_var, VAL_BACKSPACE, &bs_index);
	tmp = get_variable_name(start_var + 1, bs_index);
	if (ms_find_variable(tmp, env, &i) == SUCCESS)
	{
		ft_strdel(&tmp);
		if (bs_index > 0)
			join_path_rest(arg, ms_get_var_path(env[i]), bs_index);
		else
		{
			tmp = ft_strdup(*arg);
			ft_strdel(arg);
			if (!(*arg = join_begin_path(tmp, ms_get_var_path(env[i]), DOLLAR)))
				ret = FAILURE;
		}
		return (ret);
	}
	ret = ms_undefined_variable(tmp);
	ft_strdel(&tmp);
	return (ret);
}

ssize_t		apply_expansions(char **split_cmd, char **ms_env)
{
	size_t		i;
	char		*start_var;

	i = 0;
	start_var = NULL;
	while (split_cmd[i])
	{
		if ((start_var = ft_strchr(split_cmd[i], VAL_DOLLAR)))
		{
			if (dollar_expansion(split_cmd + i, ms_env, start_var) == FAILURE)
				return (FAILURE);
		}
		else if ((ft_strcmp(split_cmd[i], "~") == SUCCESS) ||
					ft_strchr(split_cmd[i], VAL_TILDE))
			if (tilde_expansion(split_cmd + i) == FAILURE)
				return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
