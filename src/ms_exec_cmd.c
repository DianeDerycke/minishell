/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:48:29 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/23 13:40:59 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
ssize_t		exec_cmd(char ***ms_env, char ***split_cmd, t_builtin *builtins)
{
	pid_t	pid;
	int		index;
	int		status;
	char	*path;

	status = 0;
	path = NULL;
	if (!**split_cmd || ms_apply_expansions(*split_cmd, *ms_env) == 1)
		return (FAILURE);
	if ((index = find_builtin((*split_cmd)[0], builtins)) >= 0)
		builtins[index].function(*split_cmd, ms_env);
	else if (ft_strcmp((*split_cmd)[0], "exit") == 0)
		exit(0);
	else if ((path = find_path((*split_cmd)[0], *ms_env)))
	{
		if ((pid = fork()) == SUCCESS)
			execve(path, *split_cmd, *ms_env);
		else
			waitpid(pid, &status, 0);
	}
	else if (!path)
	{
		command_not_found((*split_cmd)[0]);
		return (FAILURE);
	}
	ft_strdel(&path);
	return (SUCCESS);
}