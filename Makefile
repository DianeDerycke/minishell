# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/12 12:42:27 by DERYCKE           #+#    #+#              #
#    Updated: 2018/10/01 14:29:18 by dideryck         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT = ./libft/
LIBMS = ./libms/
LIBNAME = ./libft/libft.a ./libms/libms.a

SRC_PATH = ./src
SRC_NAME = main.c error.c utils.c exec_cmd.c builtins.c echo.c \
			env.c cd.c init.c parser_env.c setenv.c unsetenv.c \
			expansions.c utils2.c help.c
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = ./obj
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CPPFLAGS = -Iincludes
LDFLAGS = -Llibft -Llibms
LDLIBS = -lft -lms
CC = gcc
CFLAGS = -Werror -Wextra -Wall

all: compile

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

compile: 
	@make -s -C $(LIBFT) 
	@make -s -C $(LIBMS)
	@make -s $(NAME)
	@echo "COMPILATION DONE"
	
clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@make -C $(LIBFT) clean
	@make -C $(LIBMS) clean
	@echo "CLEAN DONE"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBNAME)
	@echo "FCLEAN DONE"

re: fclean all
	@echo "RE DONE"