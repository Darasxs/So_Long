# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/28 13:38:21 by dpaluszk          #+#    #+#              #
#    Updated: 2024/07/28 14:45:41 by dpaluszk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = so_long.c
OBJECTS = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = cc
LIBFT_DIR = libft
GET_NEXT_LINE_DIR = get_next_line
PRINTF_DIR = printf
LIBFT = $(LIBFT_DIR)/libft.a
GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/get_next_line.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX = ./MLX42
MLX_URL = https://github.com/codam-coding-college/MLX42

all: $(NAME)

$(MLX):
	if [ ! -d "$(MLX)" ]; then git clone $(MLX_URL) $(MLX); fi
	cd $(MLX) && cmake -B build && cmake --build build -j4

$(PRINTF):
	make -C $(PRINTF_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(GET_NEXT_LINE):
	make -C $(GET_NEXT_LINE_DIR)

$(NAME): $(OBJECTS) $(GET_NEXT_LINE) $(PRINTF) $(MLX)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME) -L$(LIBFT_DIR) -lft -L$(GET_NEXT_LINE_DIR) -lgnl -L$(PRINTF_DIR) -lftprintf -L$(MLX) -lmlx42

%.o: %.c so_long.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)
	make clean -C $(PRINTF_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(GET_NEXT_LINE_DIR)

fclean:	clean
	rm -rf $(NAME) $(MLX)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(GET_NEXT_LINE_DIR)

re: fclean all

.PHONY: all clean fclean re