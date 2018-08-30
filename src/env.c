/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:44:35 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/30 13:25:51 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    add_argument_to_env(char **split_cmd, char **env)
{
    size_t  i;
    size_t  index;
    char    *var_name;
    char    *var_value;

    i = 1;
    index = 0;
    var_name = NULL;
    var_value = NULL;
    while (split_cmd[i] && !(ft_strchr(split_cmd[i], C_EQUAL)))
        i++;
    while(split_cmd[i] && ft_strchr(split_cmd[i], C_EQUAL))
    {
        ft_find_char(split_cmd[i], C_EQUAL, &index);
        var_name = get_variable_name(split_cmd[i], index);
        var_value = ft_strdup(split_cmd[i] + index);
        find_variable(var_name, env, &index);
        edit_variable(var_name, var_value, env, index);
        ft_strdel(&var_name);
        ft_strdel(&var_value);
        i++;
    }
}

ssize_t    apply_options(char **split_cmd, char **env)
{
    add_argument_to_env(split_cmd, env);
    ms_exec_binary(split_cmd[0], split_cmd, env);
    if (env)
        ft_free_array(env);
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
        init_env_options(split_cmd, &env_opt);
        tmp_env = ft_copy_array(*ms_env, ft_strlen_array(*ms_env) + 1);
        apply_options(split_cmd, tmp_env);
    }
    else
        ft_print_array(*ms_env);
    return (SUCCESS);
}