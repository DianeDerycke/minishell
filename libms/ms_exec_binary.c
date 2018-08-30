/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:26:30 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/30 13:22:26 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"

void	ms_exec_binary(char *utility, char **split_cmd, char **env)
{
	char	*path;
	pid_t	pid;
	int		status;

	path = NULL;
	status = 0;
	if ((path = ms_get_valid_cmd(utility, env)))
	{
		if ((pid = fork()) == SUCCESS)
			execve(path, split_cmd, env);
		else
			waitpid(pid, &status, 0);
	}
	else if (!path)
	{
		ms_command_not_found(utility);
		return ;
	}
	ft_strdel(&path);
}