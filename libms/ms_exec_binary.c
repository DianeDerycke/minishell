/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:26:30 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/27 14:27:03 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"

void	ms_exec_binary(char *path, char **split_cmd, char **ms_env)
{
	pid_t	pid;
	int		status;

	status = 0;
	if ((pid = fork()) == SUCCESS)
		execve(path, split_cmd, ms_env);
	else
		waitpid(pid, &status, 0);
}