/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 21:18:27 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/09 20:14:45 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	**ft_copy_array(char **src, size_t len)
{
	size_t		n;
	char	**dst;

	n = 0;
	dst = NULL;
	if (!src)
		return (NULL);
	if (!(dst = malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (n < len)
	{
		dst[n] = ft_strdup(src[n]);
		n++;		
	}
	dst[n] = NULL;
	return (dst);
}