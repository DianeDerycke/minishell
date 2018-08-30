/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_command_not_found.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 20:03:40 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/30 09:37:45 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"

ssize_t		ms_command_not_found(char *cmd)
{
	ft_putstr("minishell: command not found: ");
	ft_putendl(cmd);
	return (FAILURE);
}