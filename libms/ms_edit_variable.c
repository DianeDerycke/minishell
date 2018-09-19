/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_edit_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:39:32 by dideryck          #+#    #+#             */
/*   Updated: 2018/09/19 12:39:58 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"

void    ms_edit_variable(char *var_name, char *var_value, char ***ms_env, size_t index)
{
    ft_strdel((*ms_env + index));
    *(*ms_env + index) = ms_create_variable(var_name, var_value);
}