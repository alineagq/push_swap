# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 15:06:40 by aqueiroz          #+#    #+#              #
#    Updated: 2023/06/14 18:26:23 by aqueiroz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PATH_SRC =
PATH_INCLUDE =./
GCCFLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix $(PATH_SRC), \
    ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
    ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strlen.c \
    ft_strdup.c ft_strncmp.c ft_tolower.c ft_toupper.c ft_memchr.c ft_memcmp.c \
	ft_strlcat.c ft_strlcpy.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_striteri.c ft_substr.c ft_strjoin.c \
	ft_itoa.c ft_strmapi.c ft_strtrim.c ft_split.c get_next_line.c ft_printchar.c \
	ft_printf.c ft_printhex.c ft_printnbr.c ft_printptr.c ft_printstr.c ft_printunbr.c \
	ft_uitoa.c ft_open.c ft_strtok.c raise_error.c ft_strcmp.c ft_atoll.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c)

OBJS := ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	@cc $(GCCFLAGS) -I $(PATH_INCLUDE) -c $(SRCS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re