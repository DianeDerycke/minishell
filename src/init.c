/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:44:35 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/10/01 15:12:42 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_builtin_struct(t_builtin *builtin_tab)
{
	ft_strcpy(builtin_tab[0].name, "echo");
	builtin_tab[0].function = ms_echo;
	ft_strcpy(builtin_tab[1].name, "cd");
	builtin_tab[1].function = ms_cd;
	ft_strcpy(builtin_tab[2].name, "setenv");
	builtin_tab[2].function = ms_setenv;
	ft_strcpy(builtin_tab[3].name, "unsetenv");
	builtin_tab[3].function = ms_unsetenv;
	ft_strcpy(builtin_tab[4].name, "env");
	builtin_tab[4].function = ms_env;
	ft_strcpy(builtin_tab[5].name, "help");
	builtin_tab[5].function = ms_help;
}

void	init_opt_struct(t_opt *env_opt)
{
	env_opt->i = 0;
	env_opt->p = 0;
	env_opt->s = 0;
	env_opt->u = 0;
	env_opt->v = 0;
}
