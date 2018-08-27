/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:18:12 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/08/23 15:50:55 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct		s_pos
{
	int					fd;
	int					ret;
	char				buffer[BUFF_SIZE + 1];
	char				*rest;
}					t_pos;

ssize_t					get_next_line(const int fd, char **line);

#endif
