/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isalnum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 20:07:26 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/10/01 15:58:49 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_isalnum(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != '_' && str[i] != '/'
				&& str[i] != ':' && str[i] != 92 && str[i] != '.' && 
				str[i] != ' ')
				{
					printf("str[i]=====>>>%c<<<\n", str[i]);
					return (1);
				}
		i++;
	}
	return (0);
}
