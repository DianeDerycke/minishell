/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:44:35 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/07/19 01:32:54 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

int		main(void)
{
	char			cmd[1024];
	extern char 	**environ;
	char			**ms_env;
	char			**array;
	int	 			bytes;
	t_builtin		builtin_tab[6];

	init_builtins(builtin_tab);
	if (!(ms_env = ft_copy_array(environ)))
		return (1);
	while (1)
	{
		ft_putstr("$> ");
		if (!(bytes = read(1, cmd, 1024)))
			return (0);
		cmd[bytes - 1] = '\0';
		if (bytes == 1)
			continue ;
		if (!(array = ft_strsplit(cmd, ' ')))
			return (1);
		exec_cmd(ms_env, array, builtin_tab);
	}
	ft_double_free(array);
	return (0);
}