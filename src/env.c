/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:44:35 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/07/21 04:28:47 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void    ms_env(char **split_cmd, char **ms_env)
{
    (void)split_cmd;
    ft_print_array(ms_env);
}

void    ms_setenv(char **split_cmd, char **ms_env)
{
    (void)ms_env;
    (void)split_cmd;
    printf("MS_SETENV\n");
}

void    ms_unsetenv(char **split_cmd, char **ms_env)
{
    (void)ms_env;
    (void)split_cmd;
    printf("MS UNSETENV\n");
}

//create parser for env options such as -P etc
// doesn't take input with '='sign
//Deal with permissions denied f.e env -S $HOME (mb trying accessing
//and changing argument ?