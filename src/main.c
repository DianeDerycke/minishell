/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:44:35 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/09/24 15:39:24 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main(void)
{
	int				ret;
	char			**cmd;
	char			*input;
	char			**ms_env;
	t_builtin		builtin_tab[ARRAY_SIZE];

	ret = 0;
	input = NULL;
	ms_env = ms_get_env();
	init_builtin_struct(builtin_tab);
	while (1)
	{
		ft_putstr("minishell$ ");
		if ((ret = ms_read_input(&input)) == PAGAIN ||
			(!(cmd = ms_clean_input(&input))))
		{
			if (ret == -1)
				break ;
			continue ;
		}
		ret = exec_cmd(&ms_env, &cmd, builtin_tab);
	}
	ft_free_array(ms_env);
	return (ret);
}
