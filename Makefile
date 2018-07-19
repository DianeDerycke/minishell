# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/12 12:42:27 by DERYCKE           #+#    #+#              #
#    Updated: 2018/07/19 02:22:15 by DERYCKE          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT = ./libft/
LIBNAME = ./libft/libft.a

SRC_PATH = ./src
SRC_NAME = main.c parser.c error.c utils.c exec_cmd.c builtins.c echo.c
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