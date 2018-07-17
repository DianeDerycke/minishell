/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:44:35 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/07/17 04:29:23 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

int		main(void)
{
	char	cmd[1024];
	char	**array;
	pid_t	pid;
	int	 	bytes;
	int		status;
	
	bytes = 0;
	status = 0;
	while (1)
	{
		ft_putstr("$> ");
		bytes = read(1, cmd, 1024);
		cmd[bytes - 1] = '\0';
		array = ft_strsplit(cmd, ' ');
		if (!array) //manage error later
			return (1);
		if (cmd_is_valid(array[0]) == 0)
		{
			if (!(pid = fork()))
				execve(array[0], array, NULL);
			else
				waitpid(pid, &status, 0);
		}
		else
			command_not_found(array[0]);
	}
	return (0);
}