/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_create_variable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:14:23 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/23 14:18:02 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"

char    *ms_create_variable(char *var_name, char *var_value)
{
    size_t  i;
    char    *tmp;
    char    *tmp1; 

    i = 1;
    if (!(tmp = ft_strdup(var_name)) || !(tmp1 = ft_strjoin_free(tmp, "=")))
		ms_malloc_error();
    if (var_value)
    {
        if (!(tmp = ft_strjoin_free(tmp1, var_value)))
			ms_malloc_error();
        return (tmp);
    }
    return (tmp1);
}