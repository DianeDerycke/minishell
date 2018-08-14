/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 20:44:14 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/14 10:14:05 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
ssize_t		ms_echo(char **split_cmd, char ***ms_env)
{
	int		i;
	int		is_opt;

	is_opt = 0;
	i = 1;
	(void)ms_env;
	while (split_cmd[i] && ((ft_strcmp(split_cmd[i], "-n") == 0)))
	{
		is_opt++;
		i++;
	}
	while (split_cmd[i])
	{
		ft_putstr(split_cmd[i]);
		split_cmd[i + 1] ? ft_putchar(' ') : 0;
		i++;
	}
	if (!(is_opt))
		ft_putchar('\n');
	return (SUCCESS);
}