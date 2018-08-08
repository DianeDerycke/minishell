/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:44:35 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/07/21 04:28:47 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

int		main(void)
{
	t_builtin		builtin_tab[6];
	char			*input;
	extern char 	**environ;
	char			**ms_env;
	char			**cmd;
	int 	 		error;

	input = NULL;
	init_builtin_struct(builtin_tab);
	if (!(ms_env = ft_copy_array(environ)))
		return (1);
	while (1)
	{
		ft_putstr("minishell$ ");
		if ((error = ms_read_input(&input)) == EAGAIN)
			continue ;
		if (error == -1 || (!(cmd = ms_split_input(&input))))
			return (EINTR);
		exec_cmd(ms_env, cmd, builtin_tab);
	}
	ft_free_array(cmd);
	return (SUCCESS);
}

//add alias -G avec le ls
//regler le type de variables utilisés