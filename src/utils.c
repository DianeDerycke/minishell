/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:50:46 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/30 13:26:00 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
ssize_t		find_variable(char *cmd, char **ms_env, size_t *index)
{
	size_t 	i;

	i = 0;
	*index = 0;
	if (!cmd)
		return (-1);
	while (ms_env[*index])
	{
 		while(ms_env[*index][i] == cmd[i] && ms_env[*index][i] != '=')
			i++;
		if (ms_env[*index][i] == '=')
			return (0);
		(*index)++;
		i = 0;
	}
	return (-1);
}