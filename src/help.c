/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:15:28 by dideryck          #+#    #+#             */
/*   Updated: 2018/09/27 16:46:07 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void     ms_help_cd(void)
{
    ft_putstr(BLUE);
    ft_putendl("    - cd [dir]\n");
    ft_putstr(RESET);
    ft_putendl("        Change the shell working directory\n");
    ft_putstr("            Change the current directory to DIR.  The default");
    ft_putendl(" DIR is the value of the\n            HOME shell variable.\n");
}

static void     ms_help_echo(void)
{
    ft_putstr(BLUE);
    ft_putendl("    - echo [-n] [string...]\n");
    ft_putstr(RESET);
    ft_putstr("        The echo utility writes its arguments to standard output");
    ft_putendl(", followed by a <newline>\n");
    ft_putendl("        -n : Do not output the trailing newline.");
}

ssize_t		ms_help(char **split_cmd, char ***ms_env)
{
    (void)ms_env;
    (void)split_cmd;
    ft_putstr(YELLOW);
    ft_putendl("                MINISHELL HELP\n");
    ft_putstr(RESET);
    ms_help_cd();
    ms_help_echo();
    return (SUCCESS);
}
