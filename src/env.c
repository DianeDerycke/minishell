/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:44:35 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/09/25 18:01:58 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void			add_argument_to_env(char **split_cmd, char **env)
{
	size_t	i;
	size_t	index;
	char	*var_name;
	char	*var_value;

	i = 1;
	index = 0;
	var_name = NULL;
	var_value = NULL;
	while (split_cmd[i] && !(ft_strchr(split_cmd[i], VAL_EQUAL)))
		i++;
	while (split_cmd[i] && ft_strchr(split_cmd[i], VAL_EQUAL))
	{
		ft_find_char(split_cmd[i], VAL_EQUAL, &index);
		var_name = get_variable_name(split_cmd[i], index);
		var_value = ft_strdup(*split_cmd + (index + i));
		if (ms_find_variable(var_name, env, &index) == SUCCESS)
			ms_edit_var(var_name, var_value, &env, index);
		ft_strdel(&var_value);
		ft_strdel(&var_name);
		i++;
	}
}

static char			**create_tmp_env(char **split_cmd)
{
	size_t		i;
	size_t		j;
	size_t		len;
	char		**tmp_env;
	char		**tmp;

	i = 1;
	j = 0;
	tmp_env = NULL;
	tmp = NULL;
	while (split_cmd[i] && ft_strchr(split_cmd[i], VAL_DASH))
	{
		if (ft_strncmp(split_cmd[i], "PATH", 4) == SUCCESS)
			j = 1;
		i++;
	}
	len = ft_strlen_array(split_cmd + i);
	if (j == 0 || len == 0)
		j++;
	if (!(tmp_env = malloc(sizeof(char *) * (len + 1 + j))))
		ms_malloc_error();
	if (j == 0)
		tmp_env[] = ft_strdup(DEFAULT_PATH);
	j = 0;
	while (split_cmd[i] && ft_strchr(split_cmd[i], VAL_EQUAL))
	{
		if (!(tmp_env[j] = ft_strdup(split_cmd[i])))
			ms_malloc_error();
		i++;
		j++;
	}
	tmp_env[j] = NULL;
	printf("HERE\n");
	return (tmp_env);
}

static char			**find_first_bin(char **split_cmd, int c)
{
	size_t		i;

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

static ssize_t		apply_opt(char **cmd, t_opt opt, ssize_t ret, char **s_bin, char **env)
{
	char	**tmp_env;

	if (opt.i)
	{
		tmp_env = create_tmp_env(cmd);
		if (!(s_bin = find_first_bin(cmd, VAL_EQUAL)))
			s_bin = cmd + 2;
		if ((s_bin && *s_bin && ft_strchr(*s_bin, VAL_EQUAL)) ||
				(!s_bin || !(*s_bin)))
			ft_print_array(tmp_env);
		else if (ms_exec_binary(*s_bin, s_bin, tmp_env) == FAILURE)
			ret = error_chdir(ERR_INTR, *s_bin, "env");
	}
	else
	{
		tmp_env = ft_copy_array(env, ft_strlen_array(env));
		add_argument_to_env(cmd, tmp_env);
		if (!(s_bin = find_first_bin(cmd, VAL_EQUAL)))
			s_bin = cmd + 1;
		if (ms_exec_binary(*s_bin, s_bin, tmp_env) == FAILURE)
			ret = ms_no_such_file_or_dir(cmd[0], *s_bin);
	}
	ft_free_array(tmp_env);
	return (ret);
}

ssize_t				ms_env(char **split_cmd, char ***ms_env)
{
	ssize_t		ret;
	t_opt		opt;
	char		**s_bin;

	ret = 0;
	s_bin = NULL;
	init_opt_struct(&opt);
	if (!split_cmd || !ms_env)
		return (PAGAIN);
	else if (ft_strlen_array(split_cmd) > 1)
	{
		init_env_options(split_cmd, &opt);
		if (apply_opt(split_cmd, opt, ret, s_bin, *ms_env) == FAILURE)
			return (FAILURE);
	}
	else
		ft_print_array(*ms_env);
	return (SUCCESS);
}
