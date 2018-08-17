/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isalnum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 20:07:26 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/17 16:29:43 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int         ft_str_isalnum(char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if (ft_isalnum(str[i]) == 0 && str[i] != '_' && str[i] != '/' && str[i] != ':')
            return (1);
        i++;
    }
    return (0);
}