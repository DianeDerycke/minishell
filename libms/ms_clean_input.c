/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_clean_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:20:38 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/23 13:25:01 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"

char	**ms_clean_input(char **input)
{
	char		**tmp;
    char        **cmd;

    tmp = NULL;
    cmd = NULL;
    if (!input || !*input)
        return (NULL);
    ft_replace(*input, '"', ' ');
	if (!(tmp = ft_strsplit(*input, ' ')))
        return (NULL);
    cmd = ft_trim_array(tmp);
    ft_free_array(tmp);
	ft_strdel(input);
	return (cmd);
}