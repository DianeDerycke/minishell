# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/12 12:42:27 by DERYCKE           #+#    #+#              #
#    Updated: 2018/08/14 14:05:32 by DERYCKE          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT = ./libft/
LIBNAME = ./libft/libft.a

SRC_PATH = ./src
SRC_NAME = main.c ms_parser.c ms_error.c ms_utils.c ms_exec_cmd.c ms_builtins.c ms_echo.c \
			get_next_line.c	ms_env.c ms_cd.c ms_init.c ms_parser_env.c ms_setenv.c \
			ms_unsetenv.c ms_error2.c
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = ./obj
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CPPFLAGS = -Iincludes
LDFLAGS = -Llibft
LDLIBS = -lft
CC = clang
CFLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	make -C $(LIBFT) clean

fclean: clean
	rm -fv $(NAME)
	rm -fv $(LIBNAME)

re: fclean all