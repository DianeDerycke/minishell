/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:10:19 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/20 14:32:37 by DERYCKE          ###   ########.fr       */
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
		malloc_error();
	return (path);
}

char    *get_variable_name(char *arg, size_t bs_index)
{
    char    *tmp;

    tmp = NULL;
    if (!arg)
        return (NULL);
    // if ((arg)[1] == '{' && (arg)[ft_strlen((arg)) - 1] == '}')
    //     tmp = ft_strndup(arg + 2, ft_strlen((arg)) - 2);
    if (bs_index > 0)
        tmp = ft_strndup(arg + 1, bs_index);
    else
        tmp = ft_strdup(arg + 1);
    if (!tmp)
        malloc_error();
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