/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_find_path_variable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 09:28:10 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/30 09:35:12 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"

char        *ms_find_path_variable(char **ms_env)
{
	int		i;

	i = 0;
	while (ms_env[i] && ft_strncmp("PATH=", ms_env[i], 5) != 0)
		i++;
	if (!(ms_env[i]))
		return (NULL);
	return (ms_env[i] + 5);
}