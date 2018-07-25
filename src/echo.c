/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 20:44:14 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/07/20 00:16:05 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void	ms_echo(char **split_cmd)
{
	int		i;
	int		is_opt;

	is_opt = 0;
	i = 1;
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
}