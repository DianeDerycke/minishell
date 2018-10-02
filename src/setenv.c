/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 19:11:59 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/10/02 17:23:45 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static ssize_t		is_valid_set_cmd(char **split_cmd)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 1;
	while (split_cmd[i])
	{
		if (i == 1 && ft_strchr(split_cmd[i], VAL_SLASH))
			return (FAILURE);
		if (ms_is_env_var_name(split_cmd[i]) == 1)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

char				**add_variable(char *v_name, char *v_value, char **ms_env)
{
	char	**tmp_env;
	size_t	len_tmp;

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
	tmp_env[len_tmp] = ms_create_variable(v_name, v_value);
	tmp_env[len_tmp + 1] = NULL;
	return (tmp_env);
}

ssize_t				ms_setenv(char **split_cmd, char ***ms_env)
{
	size_t		index;
	size_t		len_cmd;
	char		**tmp;

	index = 1;
	len_cmd = ft_strlen_array(split_cmd);
	tmp = NULL;
	if (len_cmd == 1)
		ft_print_array(*ms_env);
	else if (len_cmd > 3)
		return (too_many_args("setenv"));
	else if ((is_valid_set_cmd(split_cmd)) == 1)
		return (unvalid_setenv_cmd());
	else if (ms_find_variable(split_cmd[1], *ms_env, &index) == 0)
		ms_edit_var(split_cmd[1], split_cmd[2], ms_env, index);
	else
	{
		tmp = ft_copy_array(*ms_env, ft_strlen_array(*ms_env));
		ft_free_array(*ms_env);
		*ms_env = add_variable(split_cmd[1], split_cmd[2], tmp);
		ft_free_array(tmp);
	}
	return (SUCCESS);
}
