/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:50:46 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/14 17:55:58 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
ssize_t		find_variable(char *cmd, char **ms_env, size_t *index)
{
	size_t 	i;

	i = 0;
	*index = 0;
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

char    *create_line(char **split_cmd)
{
    size_t  i;
    char    *tmp;
    char    *tmp1; 

    i = 1;
    if (!(tmp = ft_strdup(split_cmd[1])) || !(tmp1 = ft_strjoin_free(tmp, "=")))
		malloc_error();
    if (split_cmd[2])
    {
        if (!(tmp = ft_strjoin_free(tmp1, split_cmd[2])))
			malloc_error();
        return (tmp);
    }
    return (tmp1);
}