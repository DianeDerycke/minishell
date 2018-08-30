/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:44:35 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/29 12:09:15 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char    **create_tmp_env(char **split_cmd, size_t *index)
{
    size_t      n;
    char        **array;

    array = NULL;
    n = 0;
    if (!split_cmd)
        return (NULL);
    while(split_cmd[*index] && !ft_strchr(split_cmd[*index], '='))
        (*index)++;
    while(split_cmd[*index] && ft_strchr(split_cmd[*index], '='))
    {
        if (!(array[n] = ft_strdup(split_cmd[*index])))
        {
            ft_free_array(array);
            ms_malloc_error();
        }
        n++;
        (*index)++;
    }
    return (array);
}

ssize_t    apply_options(char **split_cmd, t_opt env_opt)
{
    size_t      index;
    char        **tmp_env;

    index = 0;
    tmp_env = NULL;
    if (env_opt.i == 1)
    {
        tmp_env = create_tmp_env(split_cmd, &index);
        ms_exec_binary(split_cmd[index], split_cmd, tmp_env);
        ft_free_array(tmp_env);
    }
    return (SUCCESS);
}


ssize_t    ms_env(char **split_cmd, char ***ms_env)
{
    ssize_t     error;
    t_opt       env_opt;
    char        **tmp_env;

    tmp_env = NULL;
    error = 0;
    init_opt_struct(&env_opt);
    if (!split_cmd || !ms_env)
        return (PAGAIN);
    else if (ft_strlen_array(split_cmd) > 1)
    {
        init_env_options(split_cmd, env_opt);
        apply_options(split_cmd, env_opt);
    }
    else
        ft_print_array(*ms_env);
    return (SUCCESS);
}
//to do : handle binaries
// doesn't take input with '='sign
//Deal with permissions denied f.e env -S $HOME (trying accessing
//and changing argument ?