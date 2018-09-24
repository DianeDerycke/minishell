/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:50:46 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/09/24 17:26:34 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		*get_var_path(char *var)
{
	char	*path;
	size_t	i;

	i = 0;
	if (!var)
		return (NULL);
	while (var[i] != '=')
		i++;
	if (!(path = ft_strdup(var + i + 1)))
		ms_malloc_error();
	return (path);
}

char		*get_variable_name(char *arg, size_t end)
{
	char	*tmp;

	tmp = NULL;
	if (!arg)
		return (NULL);
	if (end > 0)
		tmp = ft_strndup(arg + 1, end);
	else
		tmp = ft_strdup(arg + 1);
	if (!tmp)
		ms_malloc_error();
	return (tmp);
}

void		join_path_rest(char **arg, char *var_path, size_t bs_index)
{
	char	*rest_arg;

	rest_arg = ft_strdup(*arg + (bs_index + 1));
	ft_strdel(arg);
	if (rest_arg)
		*arg = ft_strjoin_free(var_path, rest_arg);
	else
		*arg = var_path;
	ft_strdel(&rest_arg);
}

char		*join_begin_path(char *str, char *str2, char c)
{
	size_t		i;
	char		*tmp;
	char		*cpy;

	i = 0;
	cpy = NULL;
	if (!(tmp = ft_dup_until(str, c)))
		return (NULL);
	if (!(cpy = ft_strjoin_free(tmp, str2)))
		return (NULL);
	ft_strdel(&str);
	ft_strdel(&str2);
	return (cpy);
}

ssize_t		has_arg(char **split_cmd)
{
	size_t		i;

	i = 1;
	while (split_cmd[i] && !ft_strchr(split_cmd[i], VAL_EQUAL))
		i++;
	if (split_cmd[i] && ft_strchr(split_cmd[i], VAL_EQUAL))
		return (SUCCESS);
	return (FAILURE);
}
