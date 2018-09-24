/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_valid_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:16:30 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/09/24 17:56:56 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"

char		*ms_get_valid_cmd(char *cmd, char **ms_env)
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
	if (!(dir_path = ms_find_path_variable(ms_env)))
		ms_malloc_error();
	path_array = ft_strsplit(dir_path, ':');
	ft_strdel(&dir_path);
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