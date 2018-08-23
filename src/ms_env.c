/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:44:35 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/23 00:31:32 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
ssize_t    exec_env_cmd(char **split_cmd, char **ms_env, t_opt env_opt)
{
    (void)split_cmd;
    (void)ms_env;
    (void)env_opt;
    ft_putendl("Options not handle yet");
    return (SUCCESS);
}


ssize_t    ms_env(char **split_cmd, char ***ms_env)
{
    ssize_t     error;
    t_opt       env_opt;

    error = 0;
    init_opt(&env_opt);
    if (!split_cmd || !ms_env || 
            (error = is_valid_env_options(split_cmd, env_opt)) == 1)
        return (EAGAIN);
    else if (ft_strlen_array(split_cmd) > 1)
        exec_env_cmd(split_cmd, *ms_env, env_opt);
    else
        ft_print_array(*ms_env);
    return (SUCCESS);
}

// doesn't take input with '='sign
//Deal with permissions denied f.e env -S $HOME (trying accessing
//and changing argument ?