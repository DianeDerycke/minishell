/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 19:11:59 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/09/11 16:34:46 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
ssize_t     is_valid_set_cmd(char **split_cmd)
{
    size_t      i;
    size_t      j;

    j = 0;
    i = 1;
    while (split_cmd[i])
    {
        if (ft_str_isalnum(split_cmd[i]) == 1)
            return (FAILURE);
        i++;
    }
    return (SUCCESS);
}

void    edit_variable(char *var_name, char *var_value, char ***ms_env, size_t index)
{
    ft_strdel((*ms_env + index));
    *(*ms_env + index) = ms_create_variable(var_name, var_value);
}

char    **add_variable(char *var_name, char *var_value, char **ms_env)
{
    char    **tmp_env;
    size_t  len_tmp;

    len_tmp = 0;
    if (!ms_env)
    {
        if (!(tmp_env = malloc(sizeof(char *) + 2)))
            ms_malloc_error();
        tmp_env[0] = NULL;
    }
    else if (!(tmp_env = ft_copy_array(ms_env, ft_strlen_array(ms_env) + 1)))
        ms_malloc_error();
    len_tmp = ft_strlen_array(tmp_env);
    tmp_env[len_tmp] = ms_create_variable(var_name, var_value);
    tmp_env[len_tmp + 1] = NULL;
    return (tmp_env);
}

ssize_t    ms_setenv(char **split_cmd, char ***ms_env)
{   
    size_t     index;
    size_t     len_cmd;
    char        **tmp;

    index = 1;
    len_cmd = ft_strlen_array(split_cmd);
    tmp = NULL;
    if (len_cmd == 1)
        ft_print_array(*ms_env);
    else if (len_cmd > 3)
        return (too_many_args("setenv"));
    else if ((is_valid_set_cmd(split_cmd)) == 1)
        return (unvalid_setenv_cmd());
    else if (find_variable(split_cmd[1], *ms_env, &index) == 0)
        edit_variable(split_cmd[1], split_cmd[2], ms_env, index);
    else
    {
        tmp = ft_copy_array(*ms_env, ft_strlen_array(*ms_env));
        ft_free_array(*ms_env);
        *ms_env = add_variable(split_cmd[1], split_cmd[2], tmp);
        ft_free_array(tmp);
    }
	return (SUCCESS);
}