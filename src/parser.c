/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 02:31:12 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/07/17 21:21:43 by DERYCKE          ###   ########.fr       */
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