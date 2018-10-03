/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:26:30 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/10/03 14:49:57 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"

int		ms_exec_binary(char *utility, char **split_cmd, char **env, char **tmp)
{
	char	*path;
	pid_t	pid;
	int		status;

	path = NULL;
	status = 0;
	if ((path = ms_get_valid_cmd(utility, env))
		&& access(path, X_OK) == SUCCESS)
	{
		if ((pid = fork()) == SUCCESS)
			execve(path, split_cmd, tmp);
		else
			waitpid(pid, &status, 0);
	}
	else if (!path)
		return (FAILURE);
	else
		ms_perm_denied(split_cmd[0]);
	ft_strdel(&path);
	return (status != 0 ? -1 : 0);
}
