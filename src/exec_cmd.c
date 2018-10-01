/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:48:29 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/10/01 12:34:11 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			exec_cmd(char ***ms_env, char ***cmd, t_builtin *builtins)
{
	int				index;
	struct stat		f_stat;
	static int		ret = 0;

	index = 0;
	if (!cmd || !*cmd || !**cmd || apply_expansions(*cmd, *ms_env) == 1)
	{
		ft_free_array(*cmd);
		return (FAILURE);
	}
	if ((index = find_builtin((*cmd)[0], builtins, ret)) >= 0)
		ret = builtins[index].function(*cmd, ms_env);
	else if ((ret = ms_exec_binary((*cmd)[0], *cmd, *ms_env, *ms_env)) == 1)
	{
		if (ms_file_exist((*cmd)[0]) == FAILURE)
			ms_command_not_found((*cmd)[0]);
		else if (lstat((*cmd)[0], &f_stat) == 0 &&
				!(f_stat.st_mode & S_IXUSR))
			ms_perm_denied((*cmd)[0]);
	}
	ft_free_array(*cmd);
	return (ret);
}
