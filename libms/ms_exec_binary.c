/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:26:30 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/09/24 17:49:01 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"

int		ms_exec_binary(char *utility, char **split_cmd, char **env)
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
		return (FAILURE);
	ft_strdel(&path);
	return (status != 0 ? -1 : 0);
}
