# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmormont <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 15:46:43 by vmormont          #+#    #+#              #
#    Updated: 2019/11/01 15:46:44 by vmormont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
FLAGS = -Wall -Wextra -Werror
SRC_NAME =	main.c
OBJ_NAME = $(SRC_NAME:%.c=%.o)

OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))
INC = -I$(INC_DIR)

INC_DIR = include/
LIB_DIR = libft/
SRC_DIR = srcs/
OBJ_DIR = obj/

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(NAME) $(OBJ) -L $(LIB_DIR) -lft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -o $@ -c  $< $(INC)

clean:
	@make -C $(LIB_DIR) clean --silent
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIB_DIR) fclean --silent
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
