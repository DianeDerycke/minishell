/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 03:04:31 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/09/19 14:30:38 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		error_option(char c)
{
	ft_putstr_fd("env: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd("\nusage: env [-iv] [-P utilpath] [-S string] [-u name]", 2);
	ft_putendl_fd("           [name=value ...] [utility [argument ...]]", 2);
}

ssize_t		too_many_args(char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(": Too many arguments.", 2);
	return (FAILURE);
}

ssize_t		unvalid_setenv_cmd(void)
{
	ft_putendl_fd("setenv: Variable name must contain alphanumeric characters.", 2);
	return (FAILURE);
}

ssize_t     error_chdir(int error, char *path)
{
    struct stat     f_stat;

    if (error == -1 && !(opendir(path)))
    {
        if (lstat(path, &f_stat) == 0 && !(f_stat.st_mode & S_IXUSR))
            return (ms_error_perm_denied("cd", path));
        else
            return (ms_no_such_file_or_dir("cd", path));
    }
    return (FAILURE);
}