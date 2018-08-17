/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:05:46 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/17 14:06:01 by DERYCKE          ###   ########.fr       */
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

ssize_t     missing_char(char c)
{
    ft_putstr_fd("Missing", 2);
    ft_putchar_fd(c, 2);
    ft_putendl_fd(".", 2);
    return (FAILURE);
}