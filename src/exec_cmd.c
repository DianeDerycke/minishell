/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:48:29 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/07/18 20:02:30 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void		exec_cmd(char **ms_env, char **array)
{
	pid_t	pid;
	char	*path;
	int		status;

	status = 0;
	if ((path = find_path(array[0], ms_env)))
	{
		if (!(pid = fork()))
			execve(path, array, ms_env);
		else
			waitpid(pid, &status, 0);
	}
	else if (path && *path)
		command_not_found(array[0]);
	ft_strdel(&path);
}