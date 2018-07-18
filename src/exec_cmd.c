/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:48:29 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/07/19 01:29:53 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void		exec_cmd(char **ms_env, char **array, t_builtin *builtins)
{
	pid_t	pid;
	int		index;
	int		status;
	char	*path;

	status = 0;
	path = NULL;
	if ((index = find_builtin(array[0], builtins)) >= 0)
		return (builtins[index].function(array));
	else if ((path = find_path(array[0], ms_env)))
	{
		if (!(pid = fork()))
			execve(path, array, ms_env);
		else
			waitpid(pid, &status, 0);
	}
	else if (!path)
		command_not_found(array[0]);
}