/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 02:35:04 by dideryck          #+#    #+#             */
/*   Updated: 2018/07/20 02:56:48 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_memdel((void *)&tab[i]);
		i++;
	}
	ft_memdel((void *)tab[i]);
	ft_memdel((void *)&tab);
}
