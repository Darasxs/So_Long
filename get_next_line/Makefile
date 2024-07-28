# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/28 13:36:16 by dpaluszk          #+#    #+#              #
#    Updated: 2024/07/28 13:37:33 by dpaluszk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

all: $(NAME)

SRC = get_next_line.c get_next_line_utils.c

OBJECTS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = cc

%.o: %.c get_next_line.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re