# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmormont <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 12:44:34 by cormund           #+#    #+#              #
#    Updated: 2019/12/14 20:15:01 by vmormont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := lem-in
VISUAL := visual
LIBFT := libft.a
HEADERS := libft.h lem_in.h li_visualizer.h SDL.h SDL2_gfxPrimitives.h
CC := clang
CFLAGS := -Wall -Wextra -Werror -O3 -g
REMOVE := /bin/rm -rf
DIR_BIN := bin
DIR_INCLUDE := -I include
DIR_LIBS := src/libs
DIR_LIBFT := $(DIR_LIBS)/libft
DIR_SRC := src/$(NAME) src/visualizer

DIR_SDLLIBS := $(DIR_LIBS)/libSDL2
DIR_INCLUDE_SDL := -I $(DIR_SDLLIBS)/SDL2.framework/Headers -I $(DIR_SDLLIBS)/SDL2_gfx/include
SDL_LIBS := -Wl,-rpath,$(DIR_SDLLIBS) -F $(DIR_SDLLIBS) -framework SDL2
SDL2_GFX := $(DIR_SDLLIBS)/SDL2_gfx/lib/libSDL2_gfx.a

vpath %.c $(DIR_SRC)
vpath %.o $(DIR_BIN)/$(NAME) $(DIR_BIN)/$(VISUAL)
vpath %.h $(DIR_INCLUDE) $(DIR_INCLUDE_SDL)
vpath %.a $(DIR_LIBFT) $(SDL2_GFX)

SRC_NAME := lem_in.c\
			read_input.c\
			parsing.c\
			adjacencies.c\
			suurballe.c\
			bfs.c\
			queue.c\
			check_paths.c\
			validation.c\
			push_ants.c\
			bonus.c\
			hash_table.c\
			find_paths.c\
			get_count_steps_and_ants.c\
			clear.c\
			help.c\
			vertex.c

SRC_VIS := visualization.c\
			background.c\
			collection_steps.c\
			loop.c\
			rendering.c\
			collect_paths.c\
			next_step.c\
			collect_ant_move.c

OBJ_NAME := $(SRC_NAME:.c=.o)
OBJ_VIS := $(SRC_VIS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_NAME) $(OBJ_VIS)
	@$(CC) $(CFLAGS) $(addprefix $(DIR_BIN)/, $(addprefix $(NAME)/, $(OBJ_NAME)) $(addprefix $(VISUAL)/, $(OBJ_VIS))) -lft -L $(DIR_LIBFT) $(SDL_LIBS) $(SDL2_GFX) -o $@
	@printf "\r\e[J\e[32m$@\e[0m done!\n\e[?25h"

$(OBJ_NAME): %.o: %.c $(HEADERS)
	@mkdir -p $(DIR_BIN)/$(NAME)
	@$(CC) $(CFLAGS) -c $< $(DIR_INCLUDE) $(DIR_INCLUDE_SDL) -o $(DIR_BIN)/$(NAME)/$@
	@printf "\r\e[?25l\e[Jcompiling \e[32m$(notdir $<)\e[0m"

$(OBJ_VIS): %.o: %.c $(HEADERS)
	@mkdir -p $(DIR_BIN)/$(VISUAL)
	@$(CC) $(CFLAGS) -c $< $(DIR_INCLUDE) $(DIR_INCLUDE_SDL) -o $(DIR_BIN)/$(VISUAL)/$@
	@printf "\r\e[?25l\e[Jcompiling \e[32m$(notdir $<)\e[0m"

$(LIBFT):
	@$(MAKE) -C $(DIR_LIBFT)
	@$(MAKE) -C $(DIR_LIBFT) clean

clean:
	@rm -rf $(DIR_BIN)
	@$(MAKE) -C $(DIR_LIBFT) fclean

fclean: clean
	@$(REMOVE) $(NAME)
	@$(REMOVE) $(PUSH_SWAP)

re: fclean all
