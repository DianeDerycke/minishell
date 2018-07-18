/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 03:04:31 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/07/19 00:39:51 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void	command_not_found(char *path)
{
	ft_putstr("minishell: command not found: ");
	ft_putendl(path);
}

void	malloc_error(void)
{
	ft_putendl("minishell: Malloc error");
	exit (1);
}