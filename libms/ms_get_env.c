/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:34:39 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/30 13:38:17 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"

char    **ms_get_env(void)
{
    extern char     **environ;
    char            **new_env;

    new_env = NULL;
    if (!(new_env = ft_copy_array(environ, ft_strlen_array(environ))))
        ms_malloc_error();
    return (new_env);
}