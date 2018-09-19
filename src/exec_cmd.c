/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:48:29 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/09/19 14:11:31 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

ssize_t		exec_cmd(char ***ms_env, char ***split_cmd, t_builtin *builtins)
{
	int				index;
	char			*path;
	struct stat 	f_stat;
	ssize_t			ret;

	ret = 0;
	path = NULL;
	if (!**split_cmd || apply_expansions(*split_cmd, *ms_env) == 1)
		return (FAILURE);
	if ((index = find_builtin((*split_cmd)[0], builtins)) >= 0)
		builtins[index].function(*split_cmd, ms_env);
	else
		if (ms_exec_binary((*split_cmd)[0], *split_cmd, *ms_env) == FAILURE)
		{
			if (ms_file_exist((*split_cmd)[0]) == SUCCESS && lstat((*split_cmd)[0], &f_stat) == 0)
			{
				if (!(f_stat.st_mode & S_IXUSR))
					ret = ms_perm_denied((*split_cmd)[0]);
			}
			else
				ms_command_not_found((*split_cmd)[0]);
		}
	ft_free_array(*split_cmd);
	return (ret);
}