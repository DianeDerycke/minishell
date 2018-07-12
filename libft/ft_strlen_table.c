/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 01:09:16 by dideryck          #+#    #+#             */
/*   Updated: 2017/11/30 00:49:42 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen_table(char **tab)
{
	size_t		i;

	i = 0;
	while (*tab)
	{
		tab++;
		i++;
	}
	return (i);
}
