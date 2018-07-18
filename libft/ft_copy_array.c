/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 21:18:27 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/07/18 19:23:08 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	**ft_copy_array(char **src)
{
	int		i;
	int		n;
	char	**dst;

	i = 0;
	n = 0;
	dst = NULL;
	if (!src)
		return (NULL);
	i = ft_strlen_table(src);
	if (!(dst = malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	while (n < i)
	{
		dst[n] = ft_strdup(src[n]);
		n++;		
	}
	dst[n] = NULL;
	return (dst);
}