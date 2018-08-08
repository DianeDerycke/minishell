/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:50:46 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/07/21 04:30:21 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

char	*ms_getenv(char **ms_env)
{
	int		i;

	i = 0;
	while (ms_env[i] && ft_strncmp("PATH=", ms_env[i], 5) != 0)
		i++;
	return (ms_env[i] + 5);
}

int				ms_read_input(char **cmd)
{
	int 	is_read_done;

	is_read_done = get_next_line(1, cmd);
	if (is_read_done == -1)
		return (EINTR);
	if (is_read_done == 1 && !(**cmd))
		return (EAGAIN);
	return (SUCCESS);
}

size_t		len_without_char(char *str, char c)
{
	size_t		final_len;
	size_t		i;

	i = 0;
	final_len = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != c)
			final_len++;
		i++;
	}
	return (final_len);
}

void	init_env_ot(t_opt 	*env_opt)
{
	env_opt->i = 0;
	env_opt->p = 0;
	env_opt->s = 0;
	env_opt->u = 0;
	env_opt->v = 0;
}