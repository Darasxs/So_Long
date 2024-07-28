# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 12:02:53 by dpaluszk          #+#    #+#              #
#    Updated: 2024/07/28 13:37:33 by dpaluszk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

all: $(NAME)

SRC = ft_printf.c \
		helper_functions1.c \
		helper_functions2.c

OBJECTS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = cc

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re