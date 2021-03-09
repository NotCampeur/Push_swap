# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 11:13:40 by ldutriez          #+#    #+#              #
#    Updated: 2021/03/09 14:32:36 by ldutriez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC =		clang

SRC_DIR = 	$(shell find srcs -type d)
INC_DIR = 	$(shell find includes -type d) \
			$(shell find libft/includes -type d)
LIB_DIR =	libft
OBJ_DIR = 	obj

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

# List de toute les library a linker au projet (le nom - le lib et - le .a)
LIB = ft

SRC = $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))

# SRC_CHECKER =	

# SRC_PUSH_SWAP =	

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

# OBJ_CHECKER = $(addprefix $(OBJ_DIR)/, $(SRC_CHECKER:%.c=%.o))
# OBJ_PUSH_SWAP = $(addprefix $(OBJ_DIR)/, $(SRC_PUSH_SWAP:%.c=%.o))

#Compilation flag
CFLAGS = -Wall -Wextra -Werror -g3 $(ARGS)

IFLAGS = $(foreach dir, $(INC_DIR), -I$(dir))

LFLAGS =	$(foreach dir, $(LIB_DIR), -L $(dir)) \
			$(foreach lib, $(LIB), -l $(lib))

# Colors

_GREY=	$'\033[30m
_RED=	$'\033[31m
_GREEN=	$'\033[32m
_YELLOW=$'\033[33m
_BLUE=	$'\033[34m
_PURPLE=$'\033[35m
_CYAN=	$'\033[36m
_WHITE=	$'\033[37m

all:			$(NAME)

show:
				@echo "$(_BLUE)SRC :\n$(_YELLOW)$(SRC)$(_WHITE)"
				@echo "$(_BLUE)OBJ :\n$(_YELLOW)$(OBJ)$(_WHITE)"
				@echo "$(_BLUE)CFLAGS :\n$(_YELLOW)$(CFLAGS)$(_WHITE)"
				@echo "$(_BLUE)IFLAGS :\n$(_YELLOW)$(IFLAGS)$(_WHITE)"
				@echo "$(_BLUE)LFLAGS :\n$(_YELLOW)$(LFLAGS)$(_WHITE)"
				@echo "$(_BLUE)LIB_DIR:\n$(_YELLOW)$(LIB_DIR)$(_WHITE)"
				@echo "$(_BLUE)LIB_INC :\n$(_YELLOW)$(LIB_INC)$(_WHITE)"
				@echo "$(_BLUE)INC_DIR :\n$(_YELLOW)$(INC_DIR)$(_WHITE)"

libft/libft.a:
				@echo -n "$(_PURPLE)"
				$(foreach dir, $(LIB_DIR), make $(ARG) -C $(dir) ; )
				@echo -n "$(_WHITE)"		

re-install:
				@echo "$(_PURPLE)"
				$(foreach dir, $(LIB_DIR), make $(ARG) -C $(dir) re ; )
				@echo "$(_WHITE)"

$(OBJ_DIR)/%.o : %.c
				@echo -n "Compiling $(_YELLOW)$@$(_WHITE) ... "
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo "$(_GREEN)DONE$(_WHITE)"


$(NAME): 		libft/libft.a $(INC_DIR) $(OBJ) Makefile
				@echo -n "-----\nCreating Executable $(_YELLOW)$@$(_WHITE) ... "
				@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"
				@echo -n "Creating Executable $(_YELLOW)checker$(_WHITE) ... "
				@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o checker
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

norme:
				norminette $(SRC_DIR)

re:				fclean all

check:			$(NAME)
				@echo "Launch Binary File $(_BLUE)checker$(_WHITE)\n-----"
				@./checker $(ARG)
				@echo "-----\n$(_BLUE)checker $(_GREEN)successfully end$(_WHITE)\n-----"

sort: 			$(NAME)
				@echo "Launch Binary File $(_BLUE)$(NAME)$(_WHITE)\n-----"
				@./$(NAME) $(ARG)
				@echo "-----\n$(_BLUE)$(NAME) $(_GREEN)successfully end$(_WHITE)\n-----"

clean:
				@echo -n "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... "
				@rm -rf $(OBJ_DIR)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:			clean
				@echo -n "Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... "
				@echo "$(_GREEN)DONE$(_WHITE)"
				@echo -n "Deleting Binary File $(_YELLOW)checker$(_WHITE) ... "
				@rm -f $(NAME) $(BONUS_NAME)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY: all clean flcean re show norme sort check install re-install
