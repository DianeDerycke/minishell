/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:48:29 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/30 13:25:54 by DERYCKE          ###   ########.fr       */
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
	else
		ms_exec_binary((*split_cmd)[0], *split_cmd, *ms_env);
	ft_free_array(*split_cmd);
	return (SUCCESS);
}