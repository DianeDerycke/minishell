/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 00:22:08 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/07/21 04:26:14 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

int 	find_builtin(char *cmd, t_builtin *builtins)
{
	int 	i;

	i = 0;
	if (!cmd)
		return (-1);
	while (builtins[i].name[0])
	{
		if (ft_strcmp(cmd, builtins[i].name) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	init_builtins(t_builtin *builtin_tab)
{
	ft_strcpy(builtin_tab[0].name, "echo");
	builtin_tab[0].function = ms_echo;
	builtin_tab[1].name[0] = '\0';
	builtin_tab[1].function = NULL;
}
