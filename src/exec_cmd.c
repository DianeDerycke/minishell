/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:48:29 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/09/19 17:51:20 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			exec_cmd(char ***ms_env, char ***split_cmd, t_builtin *builtins)
{
	int				index;
	char			*path;
	struct stat 	f_stat;
	static int		ret = 0;

	path = NULL;
	if (!**split_cmd || apply_expansions(*split_cmd, *ms_env) == 1)
	{
		ft_free_array(*split_cmd);
		return (FAILURE);
	}
	if ((index = find_builtin((*split_cmd)[0], builtins, ret)) >= 0)
		ret = builtins[index].function(*split_cmd, ms_env);
	else
		if ((ret = ms_exec_binary((*split_cmd)[0], *split_cmd, *ms_env)) == FAILURE)
		{
			if ((ms_file_exist((*split_cmd)[0]) == SUCCESS && lstat((*split_cmd)[0], &f_stat) == 0))
			{
				if (!(f_stat.st_mode & S_IXUSR))
					ms_perm_denied((*split_cmd)[0]);
			}
			else
				ms_command_not_found((*split_cmd)[0]);
		}
	ft_free_array(*split_cmd);
	return (ret);
}