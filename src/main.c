/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:44:35 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/09/19 13:06:58 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main(void)
{
	t_builtin		builtin_tab[ARRAY_SIZE];
	char			*input;
	char			**ms_env;
	char			**cmd;
	ssize_t 	 	error;
	ssize_t			ret;

	input = NULL;
	init_builtin_struct(builtin_tab);
	ms_env = ms_get_env();
	ret = 0;
	while (1)
	{
		ft_putstr("minishell$ ");
		if ((error = ms_read_input(&input)) == PAGAIN)
			continue ;
		if (error == -1 || (!(cmd = ms_clean_input(&input))))
		{
			ft_free_array(ms_env);
			return (ERR_INTR);
		}
		ret = exec_cmd(&ms_env, &cmd, builtin_tab);
	}
	ft_free_array(ms_env);
	return (ret);
}