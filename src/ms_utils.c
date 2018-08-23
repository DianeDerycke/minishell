/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:50:46 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/23 14:19:57 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
ssize_t		find_variable(char *cmd, char **ms_env, size_t *index)
{
	size_t 	i;

	i = 0;
	*index = 0;
	if (!cmd)
		return (-1);
	while (ms_env[*index])
	{
 		while(ms_env[*index][i] == cmd[i] && ms_env[*index][i] != '=')
			i++;
		if (ms_env[*index][i] == '=')
			return (0);
		(*index)++;
		i = 0;
	}
	return (-1);
}

char	*ms_get_varpath_value(char **ms_env)
{
	int		i;

	i = 0;
	while (ms_env[i] && ft_strncmp("PATH=", ms_env[i], 5) != 0)
		i++;
	if (!(ms_env[i]))
		return (NULL);
	return (ms_env[i] + 5);
}

int				ms_read_input(char **cmd)
{
	int 	is_read_done;

	is_read_done = get_next_line(1, cmd);
	if (is_read_done == -1)
	{
		ft_strdel(cmd);
		return (EINTR);
	}
	if (is_read_done == 1 && !(**cmd))
		return (PAGAIN);
	return (SUCCESS);
}