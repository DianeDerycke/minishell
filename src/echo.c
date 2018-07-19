/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 20:44:14 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/07/19 01:56:13 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void	ms_echo(char **array)
{
	int		i;
	int		is_opt;

	is_opt = 0;
	i = 1;
	while (array[i] && ((ft_strcmp(array[i], "-n") == 0)))
	{
		is_opt++;
		i++;
	}
	while (array[i])
	{
		ft_putstr(array[i]);
		array[i + 1] ? ft_putchar(' ') : 0;
		i++;
	}
	if (!(is_opt))
		ft_putchar('\n');
}