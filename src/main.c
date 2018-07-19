/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:44:35 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/07/19 23:38:50 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

int		main(void)
{
	char			cmd[1024];
	extern char 	**environ;
	char			**ms_env;
	char			**split_cmd;
	int	 			bytes;
	t_builtin		builtin_tab[6];

	init_builtins(builtin_tab);
	if (!(ms_env = ft_copy_split_cmd(environ)))
		return (1);
	while (1)
	{
		ft_putstr("$> ");
		if (!(bytes = read(1, cmd, 1024)))
			return (0);
		cmd[bytes - 1] = '\0';
		if (bytes == 1)
			continue ;
		if (!(split_cmd = ft_strsplit(cmd, ' ')))
			return (1);
		exec_cmd(ms_env, split_cmd, builtin_tab);
	}
	ft_double_free(split_cmd);
	return (0);
}

//parsing quote