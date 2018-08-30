/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:10:19 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/30 11:10:02 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_variable_path(char *var)
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

char    *get_variable_name(char *arg, size_t end)
{
    char    *tmp;

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

void    join_path_rest(char **arg, char *var_path, size_t bs_index)
{
    char    *rest_arg;

    rest_arg = ft_strdup(*arg + (bs_index + 1));
    ft_strdel(arg);
    if (rest_arg)
        *arg = ft_strjoin_free(var_path, rest_arg);
    else
        *arg = var_path;
    ft_strdel(&rest_arg);
}