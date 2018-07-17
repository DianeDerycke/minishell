/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 02:31:12 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/07/17 04:09:55 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"


int		cmd_is_valid(char *path)
{
	struct stat 	buf;

	if (stat(path, &buf) == 0 && (S_ISREG(buf.st_mode) && (buf.st_mode & S_IXUSR)))
		return (0);
	return (1);
}