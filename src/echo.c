/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 20:44:14 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/09/19 17:11:45 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

ssize_t		has_echo_opt(char **split_cmd, size_t *index)
{
	ssize_t		is_opt;

	is_opt = 0;
	while (split_cmd[*index] && ((ft_strcmp(split_cmd[*index], "-n") == 0)))
	{
		is_opt++;
		(*index)++;
	}
	return (is_opt);
}

void	display_echo_arg(char **split_cmd, size_t index)
{
	while (split_cmd[index])
	{
		ft_putstr(split_cmd[index]);
		split_cmd[index + 1] ? ft_putchar(' ') : 0;
		index++;
	}
}

ssize_t		ms_echo(char **split_cmd, char ***ms_env)
{
	size_t		i;
	ssize_t		is_opt;

	(void)ms_env;
	i = 1;
	is_opt = has_echo_opt(split_cmd, &i);
	display_echo_arg(split_cmd, i);
	if (!(is_opt))
		ft_putchar('\n');
	return (SUCCESS);
}