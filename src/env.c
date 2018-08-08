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

ssize_t    exec_env_cmd(char **split_cmd, char **ms_env)
{
    (void)split_cmd;
    (void)ms_env;
    printf("TEST");
    return (SUCCESS);
}


ssize_t    ms_env(char **split_cmd, char **ms_env)
{
    ssize_t     error;
    t_opt       env_opt;

    init_opt(&env_opt);
    error = 0;
    if (!split_cmd || !ms_env || (error = is_valid_cmd(split_cmd, env_opt)) == 1)
        return (EAGAIN);
    else if (ft_strlen_table(split_cmd) > 1)
        exec_env_cmd(split_cmd, ms_env);
    else
        ft_print_array(ms_env);
    return (SUCCESS);
}

//create parser for env options such as -P etc
// doesn't take input with '='sign
//Deal with permissions denied f.e env -S $HOME (mb trying accessing
//and changing argument ?