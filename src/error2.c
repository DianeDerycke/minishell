/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:05:46 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/09/19 12:53:44 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
ssize_t     too_few_args(void)
{
    ft_putendl_fd("unsetenv: Too few arguments.", 2);
    return (FAILURE);
}

ssize_t     error_chdir(int error, char *path)
{
    struct stat     f_stat;
    if (lstat(path, &f_stat) < 0)
        return (FAILURE);
    if (path && !(path[0]))
        return (FAILURE);
    if (error == -1 && !(opendir(path)))
    {
        ft_putstr_fd(path, 2);
        if (!(f_stat.st_mode & S_IXUSR))
            ft_putendl_fd(": Permissions denied.", 2);
        else
            ft_putendl_fd(": No such file or directory.", 2);
    }
    return (FAILURE);
}

ssize_t     undefined_variable(char *var)
{
    ft_putstr_fd(var, 2);
    ft_putendl_fd(": Undefined variable.", 2);
    return (FAILURE);
}