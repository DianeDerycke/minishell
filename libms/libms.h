/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libms.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:09:16 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/27 14:27:24 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMS_H
# define LIBMS_H

#include "../libft/libft.h"
#include "get_next_line.h"

# define PAGAIN 1
# define ERR_INTR -1
# define BACKSPACE 92

ssize_t     ms_read_input(char **input);
char	    **ms_clean_input(char **input);
char        *ms_create_variable(char *var_name, char *var_value);
void	    ms_malloc_error(void);
void	    ms_exec_binary(char *path, char **split_cmd, char **ms_env);

#endif