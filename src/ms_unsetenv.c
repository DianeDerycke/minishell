/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 23:38:32 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/11 23:49:55 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

ssize_t    ms_unsetenv(char **split_cmd, char **ms_env)
{
    (void)ms_env;
    (void)split_cmd;
    printf("MS UNSETENV\n");
	return (SUCCESS);
}