/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:44:35 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/09/18 15:25:16 by dideryck         ###   ########.fr       */
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

char      **find_first_bin(char **split_cmd, int c)
{
    size_t      i;

    i = 0;
    if (!split_cmd || !c)
        return (NULL);
    while (split_cmd[i] && !(ft_strchr(split_cmd[i], c)))
        i++;
    if (split_cmd[i])
    {
        while (split_cmd[i] && ft_strchr(split_cmd[i], c))
            i++;
    }
    if (!(split_cmd[i]))
        return (NULL);
    return (split_cmd + i);
}

ssize_t     has_arg(char **split_cmd)
{
    size_t  i;

    i = 1;
    while (split_cmd[i] && !ft_strchr(split_cmd[i], VAL_EQUAL))
        i++;
    if (split_cmd[i] && ft_strchr(split_cmd[i], VAL_EQUAL))
        return (SUCCESS);
    return (FAILURE);
}

ssize_t    apply_options(char **split_cmd, t_opt opt, char **ms_env)
{
    char    **tmp_env;
    char    **start_bin;

    start_bin = NULL;
    if (opt.i)
    {
        tmp_env = create_tmp_env(split_cmd);
        if (!(start_bin = find_first_bin(split_cmd, VAL_EQUAL)))
            start_bin = split_cmd + 2;
        if ((start_bin && *start_bin && ft_strchr(*start_bin, VAL_EQUAL)) || (!start_bin || !(*start_bin)))
            ft_print_array(tmp_env);
        else if (ms_exec_binary(*start_bin, start_bin, tmp_env) == FAILURE)
        {
            ft_free_array(tmp_env);
            return (ms_no_such_file_or_dir(split_cmd[0], *start_bin));
        }
    }
    else
    {
        tmp_env = ft_copy_array(ms_env, ft_strlen_array(ms_env) + 1);
        add_argument_to_env(split_cmd, tmp_env);
        if (!(start_bin = find_first_bin(split_cmd, VAL_EQUAL)))
            start_bin = split_cmd + 1;
        if (ms_exec_binary(*start_bin, start_bin, tmp_env) == FAILURE)
        {
            ft_free_array(tmp_env);
            return (ms_no_such_file_or_dir(split_cmd[0], *start_bin));
        }
    }
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
        if (apply_options(split_cmd, opt, *ms_env) == FAILURE)
            return (FAILURE);
    }
    else
        ft_print_array(*ms_env);
    return (SUCCESS);
}