/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 00:22:08 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/09/24 17:09:02 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		find_builtin(char *cmd, t_builtin *builtins, int ret)
{
	int		i;

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
		exit(ret);
	return (-1);
}
