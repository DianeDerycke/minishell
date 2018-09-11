/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:44:35 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/09/11 17:24:08 by DERYCKE          ###   ########.fr       */
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
    while (split_cmd[i] && !(ft_strchr(split_cmd[i], VAL_EQUAL)))
        i++;
    while(split_cmd[i] && ft_strchr(split_cmd[i], VAL_EQUAL))
    {
        ft_find_char(split_cmd[i], VAL_EQUAL, &index);
        var_name = get_variable_name(split_cmd[i], index);
        var_value = ft_strdup(*split_cmd + (index + i));
        if (find_variable(var_name, env, &index) == SUCCESS)
            edit_variable(var_name, var_value, &env, index);
        ft_strdel(&var_value);
        ft_strdel(&var_name);
        i++;
    }
}

char        **create_tmp_env(char **split_cmd)
{
    size_t      i;
    size_t      j;
    size_t      len;
    char        **tmp_env;

    i = 1;
    j = 0;
    tmp_env = NULL;
    while (split_cmd[i] && ft_strchr(split_cmd[i], VAL_DASH))
        i++;
    len = ft_strlen_array(split_cmd + i);
    if (!(tmp_env = malloc(sizeof(char *) * (len + 1))))
        ms_malloc_error();
    while (split_cmd[i] && ft_strchr(split_cmd[i], VAL_EQUAL))
    {
        if (!(tmp_env[j] = ft_strdup(split_cmd[i])))
            ms_malloc_error();
        i++;
        j++;
    }
    tmp_env[j] = NULL; 
    return (tmp_env);
}

ssize_t    apply_options(char **split_cmd, t_opt opt, char **ms_env)
{
    char    **tmp_env;
    size_t  len_cmd;

    tmp_env = NULL;
    len_cmd = ft_strlen_array(split_cmd);
    if (opt.i)
        tmp_env = create_tmp_env(split_cmd);
    else
    {
        tmp_env = ft_copy_array(ms_env, ft_strlen_array(ms_env) + 1);
        add_argument_to_env(split_cmd, tmp_env);
    }
    ms_exec_binary(split_cmd[len_cmd - 1], split_cmd + len_cmd - 1, tmp_env);
    if (tmp_env)
        ft_free_array(tmp_env);
    return (SUCCESS);
}

ssize_t    ms_env(char **split_cmd, char ***ms_env)
{
    ssize_t     error;
    t_opt       opt;

    error = 0;
    init_opt_struct(&opt);
    if (!split_cmd || !ms_env)
        return (PAGAIN);
    else if (ft_strlen_array(split_cmd) > 1)
    {
        init_env_options(split_cmd, &opt);
        apply_options(split_cmd, opt, *ms_env);
    }
    else
        ft_print_array(*ms_env);
    return (SUCCESS);
}