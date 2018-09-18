# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/12 12:42:27 by DERYCKE           #+#    #+#              #
#    Updated: 2018/09/18 13:40:29 by dideryck         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT = ./libft/
LIBMS = ./libms/
LIBNAME = ./libft/libft.a ./libms/libms.a

SRC_PATH = ./src
SRC_NAME = main.c error.c utils.c exec_cmd.c builtins.c echo.c \
			env.c cd.c init.c parser_env.c setenv.c unsetenv.c error2.c \
			expansions.c
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = ./obj
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CPPFLAGS = -Iincludes
LDFLAGS = -Llibft -Llibms
LDLIBS = -lft -lms
CC = gcc
CFLAGS = -g -o0 -Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT) 
	make -C $(LIBMS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	make -C $(LIBFT) clean
	make -C $(LIBMS) clean

fclean: clean
	rm -fv $(NAME)
	rm -fv $(LIBNAME)

re: fclean all