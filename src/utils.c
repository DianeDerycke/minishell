/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:50:46 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/07/19 00:39:37 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

char	*ms_getenv(char **ms_env)
{
	int		i;

	i = 0;
	while (ms_env[i] && ft_strncmp("PATH=", ms_env[i], 5) != 0)
		i++;
	return (ms_env[i] + 5);
}