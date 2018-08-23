/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 02:31:12 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/22 21:18:24 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
char		*find_path(char *cmd, char **ms_env)
{
	struct stat 	buf;
	char			*dir_path;
	char			**path_array;
	char			*filename;
	char			*tmp;
	int				i;

	i = 0;
	if (!cmd)
		return (NULL);
	if (stat(cmd, &buf) == 0 && (S_ISREG(buf.st_mode) && (buf.st_mode & S_IXUSR)))
		return (ft_strdup(cmd));
	if (!(dir_path = ms_getenv(ms_env)))
		return (NULL);
	path_array = ft_strsplit(dir_path, ':');
	while (path_array[i])
	{
		tmp = ft_strjoin(path_array[i], "/");
		filename = ft_strjoin_free(tmp, cmd);
		if (stat(filename, &buf) == 0 && (S_ISREG(buf.st_mode) && (buf.st_mode & S_IXUSR)))
		{
			ft_free_array(path_array);
			return (filename);
		}
		ft_strdel(&filename);
		i++;
	}
	ft_free_array(path_array);
	return (NULL);
}
//to do: clean find path
//to do: change ms_getenv function name

char	**ms_split_input(char **input)
{
	size_t		i;
	char		**cmd;

	i = 0;
	while ((*input)[i])
	{
		if ((*input)[i] == '"')
			(*input)[i] = ' ';
		i++;
	}
	cmd = ft_strsplit(*input, ' ');
	ft_strdel(input);
	return (cmd);
}
//to do: split_input in several functions