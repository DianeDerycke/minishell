/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 03:04:31 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/07/17 04:10:34 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void	command_not_found(char *path)
{
	ft_putstr(path);
	ft_putendl("command not found");
	exit (1);
}

void	malloc_error(void)
{
	ft_putendl("Malloc error");
	exit (1);
}