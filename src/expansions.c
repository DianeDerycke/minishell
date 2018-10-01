/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:18:40 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/10/01 21:13:24 by dideryck         ###   ########.fr       */
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

static void		dollar_expansion(char **split_cmd, char **env, char *arg,
										char *ptr)
{
	char	*sub;
	char	*join;
	char	*v_value;
	int 	index;

	index = 0;
	while (ptr)
	{
		sub = (ptr != arg ? ft_strsub(arg, 0, (size_t)(ptr - arg - 1)) : ft_strdup(""));
		if (sub == NULL)
			ms_malloc_error();
		if ((v_value = ms_get_var_path(ptr + 1, env, &index)) != NULL)
		{
			if (!(join = ft_strjoin_free(sub, v_value)) ||
			(ptr[index] && ((!(sub = ft_strsub(ptr + 1, index, ft_strlen(ptr + index)))) || 
			(!(join = ft_strjoin_free(join, sub))))))
				ms_malloc_error();
		}
		ft_strdel(&sub);
		arg = ptr + index;
		ptr = ft_strchr(ptr + index, VAL_DOLLAR);
	}
	ft_strdel(split_cmd);
	*split_cmd = join;
}

ssize_t		apply_expansions(char **split_cmd, char **ms_env)
{
	size_t		i;
	char		*ptr;

	ptr = NULL;
	i = 0;
	while (split_cmd[i])
	{
		if ((ptr = ft_strchr(split_cmd[i], VAL_DOLLAR)))
			dollar_expansion(split_cmd + i, ms_env, split_cmd[i], ptr);
		else if ((ft_strcmp(split_cmd[i], "~") == SUCCESS) ||
					ft_strchr(split_cmd[i], VAL_TILDE))
			if (tilde_expansion(split_cmd + i) == FAILURE)
				return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
