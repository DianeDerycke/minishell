/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 03:04:31 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/07/20 00:15:50 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

ssize_t		command_not_found(char *cmd)
{
	ft_putstr("minishell: command not found: ");
	ft_putendl(cmd);
	return (FAILURE);
}

void	malloc_error(void)
{
	ft_putendl("minishell: Malloc error");
	exit (FAILURE);
}

ssize_t		error_option(char c)
{
	ft_putstr_fd("env: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd("\nusage: env [-iv] [-P utilpath] [-S string] [-u name]", 2);
	ft_putendl_fd("           [name=value ...] [utility [argument ...]]", 2);
	return (FAILURE);
}