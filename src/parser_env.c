/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:44:35 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/09/24 15:34:25 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		valid_option(char c, t_opt *env_opt)
{
	if (c == 'i')
		env_opt->i = 1;
	else if (c == 'v')
		env_opt->v = 1;
	else if (c == 'p')
		env_opt->p = 1;
	else if (c == 's')
		env_opt->s = 1;
	else if (c == 'u')
		env_opt->u = 1;
}

void		init_env_options(char **split_cmd, t_opt *env_opt)
{
	int		i;
	int		n;
	char	valid_opt[11];

	i = 0;
	n = 1;
	ft_strcpy(valid_opt, "iPSuv");
	while (split_cmd[n] && split_cmd[n][i] == '-')
	{
		i++;
		while (split_cmd[n][i])
		{
			if (!(ft_strchr(valid_opt, split_cmd[n][i])))
				return (error_option(split_cmd[n][i]));
			else
				valid_option(split_cmd[n][i], env_opt);
			i++;
		}
		i = 0;
		n++;
	}
}
