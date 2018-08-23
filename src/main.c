/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:44:35 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/23 15:38:26 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main(void)
{
	t_builtin		builtin_tab[ARRAY_SIZE];
	char			*input;
	extern char 	**environ;
	char			**ms_env;
	char			**cmd;
	int 	 		error;

	input = NULL;
	init_builtin_struct(builtin_tab);
	if (!(ms_env = ft_copy_array(environ, ft_strlen_array(environ))))
		ms_malloc_error();
	while (1)
	{
		ft_putstr("minishell$ ");
		if ((error = ms_read_input(&input)) == PAGAIN)
			continue ;
		if (error == -1 || (!(cmd = ms_clean_input(&input))))
		{
			ft_free_array(ms_env);
			return (EINTR);
		}
		exec_cmd(&ms_env, &cmd, builtin_tab);
		ft_free_array(cmd);
	}
	ft_free_array(ms_env);
	return (SUCCESS);
}