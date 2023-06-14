# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 19:39:40 by aqueiroz          #+#    #+#              #
#    Updated: 2023/06/14 18:15:33 by aqueiroz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

## COLORS DEFINITIONS

red:=$(shell tput setaf 1)
green:=$(shell tput setaf 2)
yellow:=$(shell tput setaf 3)
blue:=$(shell tput setaf 4)
purple:=$(shell tput setaf 5)
cyan:=$(shell tput setaf 6)
white:=$(shell tput setaf 7)
reset:=$(shell tput sgr0)

color:
	@make -s _color-test

_color-test:
	$(info $(red)Message$(reset))
	$(info $(green)Message$(reset))
	$(info $(yellow)Message$(reset))
	$(info $(blue)Message$(reset))
	$(info $(purple)Message$(reset))
	$(info $(cyan)Message$(reset))
	$(info $(white)Message$(reset))

# PATHS

SRC_PATH = srcs
LIB_PATH = libs
OBJ_PATH = objs
PATH_INC = includes
LIBFT_PATH = $(LIB_PATH)/libft

# MANDATORY FILES

NAME = push_swap
PUSH_FILES = push_swap validators parsing
PUSH_SRCS = $(addprefix $(SRC_PATH)/, $(addsuffix .c, $(PUSH_FILES)))
PUSH_OBJS = $(PUSH_SRCS:.c=.o)

# FLAGS

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LIBFLAGS = -L./$(LIBFT_PATH) -lft

# TARGETS

all: $(NAME)

LIBFT:
	@$(MAKE) -s -k -C $(LIBFT_PATH)
	$(info $(green)Libft installed!$(reset))

$(NAME): LIBFT $(PUSH_OBJS)
	@$(CC) $(PUSH_OBJS) $(INCLUDE) $(LIBFLAGS) -o $@
	$(info $(purple)Server created. Run './push_swap' to start.$(reset))

valgrind:
	valgrind --track-origins=yes --error-exitcode=42 --leak-check=full --show-leak-kinds=all --quiet ./push_swap

clean:
	@rm -f $(PUSH_OBJS)
	@$(MAKE) -C $(LIBFT_PATH) --silent clean
	$(info $(yellow)All libs files were removed.$(reset))

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) --silent fclean
	$(info $(yellow)Executables files were removed.$(reset))

re: fclean all LIBFT
	
.PHONY: all color-test clean fclean re