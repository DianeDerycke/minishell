/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:44:35 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/07/17 21:22:58 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

int		main(void)
{
	char			cmd[1024];
	char			**array;
	pid_t			pid;
	int	 			bytes;
	int				status;
	extern char 	**environ;
	char			*path;
	char			**ms_env;

	bytes = 0;
	status = 0;
	path = NULL;
	if (!(ms_env = ft_copy_array(environ)))
		return (1);
	while (1)
	{
		ft_putstr("$> ");
		bytes = read(1, cmd, 1024);
		cmd[bytes - 1] = '\0';
		if (!(array = ft_strsplit(cmd, ' ')))
			return (1);
		if ((path = find_path(array[0], ms_env)))
		{
			if (!(pid = fork()))
				execve(path, array, ms_env);
			else
				waitpid(pid, &status, 0);
		}
		else
			command_not_found(array[0]);
	}
	return (0);
}