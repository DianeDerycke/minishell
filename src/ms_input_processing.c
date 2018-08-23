/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_input_processing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 21:34:01 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/23 00:41:35 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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