/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 02:31:12 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/07/20 00:30:20 by DERYCKE          ###   ########.fr       */
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
	dir_path = ms_getenv(ms_env);
	path_array = ft_strsplit(dir_path, ':');
	while (path_array[i])
	{
		tmp = ft_strjoin(path_array[i], "/");
		filename = ft_strjoin_free(tmp, cmd);
		if (stat(filename, &buf) == 0 && (S_ISREG(buf.st_mode) && (buf.st_mode & S_IXUSR)))
			return (filename);
		ft_strdel(&filename);
		i++;
	}
	return (NULL);
}

char	**ms_split_input(char **input)
{
	size_t		len;
	size_t		i;
	char		**cmd;
	char		*tmp;

	i = 0;
	len = len_without_char(*input, '"');
	if (!(*input) || !(**input))
	{
		ft_strdel(input);
		return (NULL);
	}
	if (!(tmp = (char *)malloc(sizeof(char) * (len + 1))))
		malloc_error();
	len = 0;
	while ((*input)[i])
	{
		if ((*input)[i] != '"')
		{
			tmp[len] = (*input)[i];
			len++;
		}
		i++;
	}
	tmp[len] = '\0';
	cmd = ft_strsplit(tmp, ' ');
	ft_strdel(&tmp);
	ft_strdel(input);
	return (cmd);
}
//split in several function to clear code