/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:48:29 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/07/20 18:41:48 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void		exec_cmd(char **ms_env, char **split_cmd, t_builtin *builtins)
{
	pid_t	pid;
	int		index;
	int		status;
	char	*path;

	status = 0;
	path = NULL;
	if ((index = find_builtin(split_cmd[0], builtins)) >= 0)
		builtins[index].function(split_cmd, ms_env);
	else if ((path = find_path(split_cmd[0], ms_env)))
	{
		if (!(pid = fork()))
			execve(path, split_cmd, ms_env);
		else
			waitpid(pid, &status, 0);
	}
	else if (!path)
		command_not_found(split_cmd[0]);
}