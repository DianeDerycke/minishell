/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 02:20:39 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/30 10:25:11 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_print_array(char **array)
{
	int		i;

	i = 0;
	if (!array)
		return;
	while (array[i])
	{
		ft_putendl(array[i]);
		i++;
	}
}