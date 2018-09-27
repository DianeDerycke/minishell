/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:51:19 by dideryck          #+#    #+#             */
/*   Updated: 2018/09/27 14:00:34 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char				**find_first_bin(char **split_cmd, int c)
{
	size_t		i;

	i = 0;
	if (!split_cmd || !c)
		return (NULL);
	while (split_cmd[i] && !(ft_strchr(split_cmd[i], c)))
		i++;
	if (split_cmd[i])
		while (split_cmd[i] && ft_strchr(split_cmd[i], c))
			i++;
	if (!(split_cmd[i]))
		return (NULL);
	return (split_cmd + i);
}

size_t      getnbr_args(char **split_cmd, int c)
{
    size_t  i;

    i = 0;
    if (!split_cmd)
        return (0);
    while (split_cmd[i] && ft_strchr(split_cmd[i], c))
        i++;
    return (i);
}