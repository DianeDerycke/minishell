/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_find_path_variable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 09:28:10 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/09/12 17:13:53 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"

char        *ms_find_path_variable(char **ms_env)
{
	int		i;
	char	*value_path;

	value_path = NULL;
	i = 0;
	while (ms_env[i] && ft_strncmp("PATH=", ms_env[i], 5) != 0)
		i++;
	if (!(ms_env[i]))
	{
		value_path = ft_strdup(DEFAULT_PATH);
		return (value_path);
	}
	value_path = ft_strdup(ms_env[i] + 5);
	return (value_path);
}