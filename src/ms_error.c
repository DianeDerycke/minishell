/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 03:04:31 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/13 15:07:33 by DERYCKE          ###   ########.fr       */
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
	printf("ERROR OPTION END RETURN FAILURE\n");	
	return (FAILURE);
}

ssize_t		too_many_args(void)
{
	ft_putendl_fd("setenv: Too many arguments.", 2);
	return (FAILURE);
}

ssize_t		unvalid_setenv_cmd(void)
{
	ft_putendl_fd("setenv: Variable name must containe alphanumeric characters.", 2);
	return (FAILURE);
}