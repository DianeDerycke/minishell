/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 23:38:32 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/14 18:20:48 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char    **delete_variable(char **ms_env, size_t index)
{
    size_t      i;
    size_t      j;
    char        **tmp_env;

    i = 0;
    j = 0;
    if (!(tmp_env = ft_copy_array(ms_env, ft_strlen_table(ms_env))))
        malloc_error();
    ft_free_array(ms_env);
    if (!(ms_env = malloc(sizeof(char *) * (ft_strlen_table(tmp_env)))))
        malloc_error();
    while (tmp_env[j])
    {
        if (i == index)
        {
            if (tmp_env[j + 1])
                j++;
            else
                break;
        }
        ms_env[i] = ft_strdup(tmp_env[j]);
        j++;
        i++;
    }
    ms_env[i] = NULL;
    ft_free_array(tmp_env);
    return (ms_env);
}

ssize_t    ms_unsetenv(char **split_cmd, char ***ms_env)
{
    size_t  i;
    size_t  index;

    i = 1;
    index = 0;
    if (ft_strlen_table(split_cmd) == 1)
        return (too_few_args());
    else
        while (split_cmd[i])
        {
            if (find_variable(split_cmd[i], *ms_env, &index) == -1)
                return (FAILURE);
            else
                *ms_env = delete_variable(*ms_env, index);
            i++;
        }
	return (SUCCESS);
}