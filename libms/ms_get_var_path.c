/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_var_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:14:28 by dideryck          #+#    #+#             */
/*   Updated: 2018/09/26 16:28:39 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"

char		*ms_get_var_path(char *var)
{
	char	*path;
	size_t	i;

	i = 0;
	if (!var)
		return (NULL);
	while (var[i] != '=')
		i++;
	if (!(path = ft_strdup(var + i + 1)))
		ms_malloc_error();
	return (path);
}
