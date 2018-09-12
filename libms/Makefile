# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/23 13:11:33 by DERYCKE           #+#    #+#              #
#    Updated: 2018/09/13 01:25:45 by DERYCKE          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libms.a

FILES = ms_clean_input ms_create_variable ms_malloc_error ms_read_input \
		get_next_line ms_exec_binary ms_command_not_found ms_get_valid_cmd \
		ms_find_path_variable ms_get_env ms_no_such_file_or_dir
SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	gcc -c -Wall -Werror -Wextra -I . -o $@ $< 

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -rf libms.a

re: fclean all