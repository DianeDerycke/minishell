/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_clean_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:20:38 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/23 15:39:09 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"

char	**ms_clean_input(char **input)
{
	char		**tmp;

    tmp = NULL;
    if (!input || !*input)
        return (NULL);
    ft_replace(*input, '"', ' ');
    ft_replace_whitespaces(*input, ' ');
	if (!(tmp = ft_strsplit(*input, ' ')))
        return (NULL);
	ft_strdel(input);
	return (tmp);
}