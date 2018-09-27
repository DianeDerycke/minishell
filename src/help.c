/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:15:28 by dideryck          #+#    #+#             */
/*   Updated: 2018/09/27 18:19:47 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void     ms_help_cd(void)
{
    ft_putstr(L_BLUE);
    ft_putendl("    - cd [dir]\n");
    ft_putstr(RESET);
    ft_putendl("        Change the shell working directory\n");
    ft_putstr("        Change the current directory to DIR.  The default");
    ft_putendl(" DIR is the value of the\n        HOME shell variable.\n");
}

static void     ms_help_echo(void)
{
    ft_putstr(L_BLUE);
    ft_putendl("    - echo [-n] [string...]\n");
    ft_putstr(RESET);
    ft_putstr("        The echo utility writes arguments to standard output");
    ft_putendl(", followed by a <newline>\n");
    ft_putendl("        -n : Do not output the trailing newline.\n");
}

static void     ms_help_env(void)
{
    ft_putstr(L_BLUE);
    ft_putendl("    - env [-i] [name=value] [utility [argument...]]\n");
    ft_putstr(RESET);
    ft_putstr("        The env utility shall obtain the current environment,");
    ft_putendl(" modify it according to its arguments,");
    ft_putstr("        then invoke the utility named by the utility operand");
    ft_putendl(" the modified environment.\n");
    ft_putstr("        -i : Invoke utility with exactly the environment");
    ft_putendl(" specified by the arguments;");
    ft_putendl("        the inherited environment is ignored completely.");
    ft_putchar('\n');
}

static void     ms_help_set_unset_env(void)
{
    ft_putstr(L_BLUE);
    ft_putendl("    - setenv [NAME] [VALUE]\n");
    ft_putstr(RESET);
    ft_putstr("        Setenv adds the variable NAME to the environment");
    ft_putendl(" with the value value, if NAME does not");
    ft_putstr("        alread exist. If NAME does exist in the environment,");
    ft_putendl(" then its value is changed to VALUE;");
    ft_putstr("        if overwrite is nonzero;If overwrite is zero,");
    ft_putendl(" then the value of NAME is not changed.\n");
    ft_putstr(L_BLUE);
    ft_putendl("    - unsetenv [NAMES...]\n");
    ft_putstr(RESET);
    ft_putstr("        Unsetenv deletes variables name from the environment.");
    ft_putendl("If name doesn not exist in the environment,");
    ft_putendl("        the environment is unchanged.\n");
}

void            clear_screen(void)
{
  const char *clear;

  clear = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, clear, 12);
  write(STDOUT_FILENO, "\r", 1);
}

ssize_t		ms_help(char **split_cmd, char ***ms_env)
{
    (void)ms_env;
    (void)split_cmd;
    clear_screen();
    ft_putstr(YELLOW);
    ft_putendl("                            MINISHELL HELP\n");
    ft_putstr(RESET);
    ms_help_cd();
    ms_help_echo();
    ms_help_env();
    ms_help_set_unset_env();
    ft_putstr(YELLOW);
    ft_putendl("                                END");
    ft_putstr(RESET);
    ft_putstr("Press ENTER to exit...");
    ft_pause();
    clear_screen();
    return (SUCCESS);
}
