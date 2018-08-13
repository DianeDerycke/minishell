/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:44:35 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/09 19:44:29 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
static void		valid_option(char c, t_opt *env_opt)
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

ssize_t     is_valid_env_options(char **split_cmd, t_opt env_opt)
{
	int		i;
    int     n;
	char	valid_opt[11];

	i = 0;
    n = 1;
    init_opt(&env_opt);
	ft_strcpy(valid_opt, "iPSuv");
    while (split_cmd[n])
    {
        if (split_cmd[n][i] == '-')
            i++;
        while (split_cmd[n][i])
        {
            if (!(ft_strchr(valid_opt, split_cmd[n][i])) ||
                (split_cmd[n][i] == '-' && ft_strlen(split_cmd[n]) > 2))
                    return (error_option(split_cmd[n][i]));
            else
                valid_option(split_cmd[n][i], &env_opt);
            i++;
        }
        n++;
    }
    return (SUCCESS);
}