/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 00:22:08 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/27 13:58:30 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int 	find_builtin(char *cmd, t_builtin *builtins)
{
	int 	i;

	i = 0;
	if (!cmd)
		return (-1);
	while (i < ARRAY_SIZE)
	{
		if (ft_strcmp(cmd, builtins[i].name) == SUCCESS)
			return (i);
		i++;
	}
	if (ft_strcmp(cmd, "exit") == SUCCESS)
		exit(0);
	return (-1);
}