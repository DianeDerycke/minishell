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

ssize_t    ms_setenv(char **split_cmd, char **ms_env)
{
    (void)ms_env;
    (void)split_cmd;
    printf("MS_SETENV\n");
	return (SUCCESS);
}

ssize_t    ms_unsetenv(char **split_cmd, char **ms_env)
{
    (void)ms_env;
    (void)split_cmd;
    printf("MS UNSETENV\n");
	return (SUCCESS);
}