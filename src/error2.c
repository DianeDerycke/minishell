/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:05:46 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/30 13:25:53 by DERYCKE          ###   ########.fr       */
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
    if (path && !(path[0]))
        return (FAILURE);
    if (error == -1 && !(opendir(path)))
    {
        ft_putstr_fd(path, 2);
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