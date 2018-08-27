/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:48:29 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/27 14:33:32 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

ssize_t		exec_cmd(char ***ms_env, char ***split_cmd, t_builtin *builtins)
{
	int		index;
	char	*path;

	path = NULL;
	if (!**split_cmd || ms_apply_expansions(*split_cmd, *ms_env) == 1)
		return (FAILURE);
	if ((index = find_builtin((*split_cmd)[0], builtins)) >= 0)
		builtins[index].function(*split_cmd, ms_env);
	else if ((path = find_path((*split_cmd)[0], *ms_env)))
		ms_exec_binary(path, *split_cmd, *ms_env);
	else if (!path)
	{
		command_not_found((*split_cmd)[0]);
		ft_strdel(&path);
		ft_free_array(*split_cmd);
		return (FAILURE);
	}
	ft_strdel(&path);
	ft_free_array(*split_cmd);
	return (SUCCESS);
}