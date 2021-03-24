# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 11:13:40 by ldutriez          #+#    #+#              #
#    Updated: 2021/03/24 17:31:53 by ldutriez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1		= push_swap
NAME2		= checker

CC =		clang

SRCS_DIR = $(shell find srcs -type d)
PUSH_SWAP_SRC_DIR = $(shell find srcs/push_swap -type d)
CHECKER_SRC_DIR = $(shell find srcs/checker -type d)

INC_DIR = 	$(shell find includes -type d) \
			$(shell find libft/includes -type d)
LIB_DIR =	libft

PUSH_SWAP_OBJ_DIR = push_swap_obj
CHECKER_OBJ_DIR = checker_obj

vpath %.c $(foreach dir, $(SRCS_DIR), $(dir):)

# List de toute les library a linker au projet (le nom - le lib et - le .a)
LIB = ft

# SRC = $(foreach dir, $(SRCS_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))

CHECKER_SRC	=	checker_main.c \
				checker_apply_operation.c swap.c push.c rotate.c reverse_rotate.c \
				checker_engine.c checker_load.c checker_parsing.c \
				\
				checker_visualizer.c \
				SDL_ColorInit.c SDL_RectInit.c SDL_PointInit.c \
				SDL_TextureManagement.c

PUSH_SWAP_SRC =	push_swap_main.c \
				swap.c push.c rotate.c reverse_rotate.c \
				push_swap_engine.c push_swap_load.c push_swap_parsing.c \
				push_swap_peculiar_cases.c push_swap_algos.c

# OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

PUSH_SWAP_OBJ = $(addprefix $(PUSH_SWAP_OBJ_DIR)/, $(PUSH_SWAP_SRC:%.c=%.o))
CHECKER_OBJ = $(addprefix $(CHECKER_OBJ_DIR)/, $(CHECKER_SRC:%.c=%.o))

#Compilation flag
CFLAGS = -Wall -Wextra -Werror -g3

DEBUG =
ifdef DEBUG
    CFLAGS += -fsanitize=address
endif

IFLAGS =	$(foreach dir, $(INC_DIR), -I$(dir))

LFLAGS =	$(foreach dir, $(LIB_DIR), -L $(dir)) \
			$(foreach lib, $(LIB), -l $(lib))

SDL_FILE = /usr/include/SDL2/SDL.h

# Colors

_GREY=	$'\033[30m
_RED=	$'\033[31m
_GREEN=	$'\033[32m
_YELLOW=$'\033[33m
_BLUE=	$'\033[34m
_PURPLE=$'\033[35m
_CYAN=	$'\033[36m
_WHITE=	$'\033[37m

all:			$(NAME1) $(NAME2)

show:
				@echo "$(_BLUE)SRC :\n$(_YELLOW)$(PUSH_SWAP_SRC) || $(CHECKER_SRC)$(_WHITE)"
				@echo "$(_BLUE)SRC_DIR :\n$(_YELLOW)$(PUSH_SWAP_SRC_DIR) || $(CHECKER_SRC_DIR)$(_WHITE)"
				@echo "$(_BLUE)OBJ :\n$(_YELLOW)$(PUSH_SWAP_OBJ) || $(CHECKER_OBJ)$(_WHITE)"
				@echo "$(_BLUE)OBJ_DIR :\n$(_YELLOW)$(PUSH_SWAP_OBJ_DIR) || $(CHECKER_OBJ_DIR)$(_WHITE)"
				@echo "$(_BLUE)CFLAGS :\n$(_YELLOW)$(CFLAGS)$(_WHITE)"
				@echo "$(_BLUE)IFLAGS :\n$(_YELLOW)$(IFLAGS)$(_WHITE)"
				@echo "$(_BLUE)LFLAGS :\n$(_YELLOW)$(LFLAGS)$(_WHITE)"
				@echo "$(_BLUE)LIB_DIR:\n$(_YELLOW)$(LIB_DIR)$(_WHITE)"
				@echo "$(_BLUE)INC_DIR :\n$(_YELLOW)$(INC_DIR)$(_WHITE)"

libft/libft.a:
				@echo -n "$(_PURPLE)"
				$(foreach dir, $(LIB_DIR), make DEBUG=$(DEBUG) -C $(dir) ; )
				@echo -n "$(_WHITE)"		

re-install:
				@echo "$(_PURPLE)"
				$(foreach dir, $(LIB_DIR), make DEBUG=$(DEBUG) -C $(dir) re ; )
				@echo "$(_WHITE)"

$(PUSH_SWAP_OBJ_DIR)/%.o : %.c
				@echo -n "Compiling $(_YELLOW)$@$(_WHITE) ... "
				@mkdir -p $(PUSH_SWAP_OBJ_DIR)
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo "$(_GREEN)DONE$(_WHITE)"

$(CHECKER_OBJ_DIR)/%.o : %.c
				@echo -n "Compiling $(_YELLOW)$@$(_WHITE) ... "
				@mkdir -p $(CHECKER_OBJ_DIR)
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo "$(_GREEN)DONE$(_WHITE)"

$(NAME1): 		libft/libft.a $(INC_DIR) $(PUSH_SWAP_OBJ) Makefile
				@echo -n "-----\nCreating Executable $(_YELLOW)$@$(_WHITE) ... "
				@$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) $(LFLAGS) -o $(NAME1)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

$(NAME2): 		libft/libft.a $(INC_DIR) $(CHECKER_OBJ) Makefile
				@echo -n "-----\nCreating Executable $(_YELLOW)$@$(_WHITE) ... "
				@$(CC) $(CFLAGS) $(CHECKER_OBJ) $(LFLAGS) -o $(NAME2)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

$(SDL_FILE):
				@echo -n "-----\nInstalling $(_YELLOW)sdl2$(_WHITE) ... "
				@yes | sudo apt-get install libsdl2-2.0-0 libsdl2-gfx-1.0-0 libsdl2-image-dev libsdl2-mixer-2.0-0 libsdl2-net-2.0-0 libsdl2-ttf-dev
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"
				
bonus:			$(SDL_FILE) libft/libft.a $(NAME1) $(INC_DIR) $(CHECKER_OBJ) Makefile
				@echo -n "-----\nCreating Executable $(_YELLOW)checker$(_WHITE) ... "
				@$(CC) $(CFLAGS) $(CHECKER_OBJ) `sdl2-config --libs` -lSDL2_ttf -lSDL2_image $(LFLAGS) -o $(NAME2)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

norme:
				norminette $(PUSH_SWAP_SRC_DIR) ; norminette $(CHECKER_SRC_DIR)

re:				fclean all

correc:			$(NAME1) $(NAME2)
				@echo "Launch The Correction Test $(_BLUE)$(NAME1)$(_WHITE)\n-----"
				@./$(NAME1) $(ARGS) | wc -l; ./&(NAME1) $(ARGS) | ./$(NAME2) $(ARGS)
				@echo "-----\n$(_BLUE)$(NAME1) $(_GREEN)successfully end$(_WHITE)\n-----"

sort: 			$(NAME1)
				@echo "Launch Binary File $(_BLUE)$(NAME1)$(_WHITE)\n-----"
				@./$(NAME1) $(ARGS)
				@echo "-----\n$(_BLUE)$(NAME1) $(_GREEN)successfully end$(_WHITE)\n-----"

check:			$(NAME2)
				@echo "Launch Binary File $(_BLUE)$(NAME2)$(_WHITE)\n-----"
				@./$(NAME2) "$(ARGS)"
				@echo "-----\n$(_BLUE)$(NAME2) $(_GREEN)successfully end$(_WHITE)\n-----"

stack_gen:
				@echo -n "-----\nCreating Executable $(_YELLOW)$@$(_WHITE) ... "
				@g++ srcs/stack_generator/stack_generator.cpp -o stack_gen; ./stack_gen $(NB) > stack.txt
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

clean:
				@echo -n "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(PUSH_SWAP_OBJ_DIR)" \
				"$(_WHITE)and $(_YELLOW)$(CHECKER_OBJ_DIR)$(_WHITE) ... "
				@rm -rf $(PUSH_SWAP_OBJ_DIR) $(CHECKER_OBJ_DIR)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:			clean
				@echo -n "Deleting Binaries Files $(_YELLOW)$(NAME1)" \
				"$(_WHITE)& $(_YELLOW)$(NAME2)$(_WHITE) ... "
				@rm -f $(NAME1) $(NAME2)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY: all clean flcean re show norme sort check re-install debug_mod correc stack_gen
