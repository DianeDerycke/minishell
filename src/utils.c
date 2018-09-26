/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:50:46 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/09/26 17:31:01 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		*get_variable_name(char *arg, size_t end)
{
	char	*tmp;

	tmp = NULL;
	if (!arg)
		return (NULL);
	if (end > 0)
		tmp = ft_strndup(arg, end);
	else
		tmp = ft_strdup(arg);
	if (!tmp)
		ms_malloc_error();
	return (tmp);
}

void		join_path_rest(char **arg, char *v_path, size_t bs_index)
{
	char	*rest_arg;

	rest_arg = ft_strdup(*arg + (bs_index + 1));
	ft_strdel(arg);
	if (rest_arg)
		*arg = ft_strjoin_free(v_path, rest_arg);
	else
		*arg = v_path;
	ft_strdel(&rest_arg);
}

char		*join_begin_path(char *str, char *str2, char c)
{
	size_t		i;
	char		*tmp;
	char		*cpy;

	i = 0;
	cpy = NULL;
	if (!(tmp = ft_dup_until(str, c)))
		return (NULL);
	if (!(cpy = ft_strjoin_free(tmp, str2)))
		return (NULL);
	ft_strdel(&str);
	ft_strdel(&str2);
	return (cpy);
}

ssize_t		has_arg(char **split_cmd)
{
	size_t		i;

	i = 1;
	while (split_cmd[i] && !ft_strchr(split_cmd[i], VAL_EQUAL))
		i++;
	if (split_cmd[i] && ft_strchr(split_cmd[i], VAL_EQUAL))
		return (SUCCESS);
	return (FAILURE);
}

ssize_t		exec_simple_env(char **cmd, char **s_bin, char **env)
{
	char	**tmp_env;
	ssize_t	ret;

	ret = 0;
	tmp_env = ft_copy_array(env, ft_strlen_array(env));
	add_argument_to_env(cmd, &tmp_env);
	if (!(s_bin = find_first_bin(cmd, VAL_EQUAL)))
		s_bin = cmd + 1;
	if (ms_find_path_variable(tmp_env))
	{
		if (ms_exec_binary(*s_bin, s_bin, tmp_env, tmp_env) == FAILURE)
			ret = ms_no_such_file_or_dir(cmd[0], *s_bin);
	}
	else if (ms_exec_binary(*s_bin, s_bin, env, tmp_env) == FAILURE)
		ret = ms_no_such_file_or_dir(cmd[0], *s_bin);
	if (tmp_env)
		ft_free_array(tmp_env);
	return (ret);
}
