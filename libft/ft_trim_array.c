/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 00:21:30 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/23 12:20:18 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    **ft_trim_array(char **array)
{
    char    **new_array;
    size_t  i;

    i = 0;
    if (!(new_array = malloc(sizeof(char *) * (ft_strlen_array(array) + 1))))
        return (NULL);
    while (array[i])
    {
        if (!(new_array[i] = ft_strtrim(array[i])))
        {
            ft_free_array(new_array);
            return (NULL);
        }
        i++;
    }
    new_array[i] = NULL;
    return (new_array);
}