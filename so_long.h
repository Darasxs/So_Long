/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:47:48 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/08/05 19:52:48 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define WIDTH 1920
# define HEIGHT 1080

# include "./MLX42/include/MLX42/MLX42.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_position
{
	size_t			x;
	size_t			y;
}					t_position;

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	t_position		*exit;
	t_position		*player;
	size_t			collectible;
	size_t			rows;
	size_t			columns;
	int				move_count;
	mlx_texture_t	*exit;
	mlx_texture_t	*player;
	mlx_texture_t	*collectible;
	mlx_texture_t	*wall;
	mlx_texture_t	*background;
}					t_game;

void				error(void);
void				read_map(char *map, t_game *game);
bool				check_wall_around(t_game *game);
bool				length_check(char *line, size_t first_line);
void				struct_init_function(t_game *my_struct);
bool				map_validation(t_game *game);
bool				check_collectibles(t_game *game);
bool				check_exit(t_game *game);
bool				check_player(t_game *game);
bool				check_characters(t_game *game);
bool				valid_char(char c);
void				render_map(t_game *game);
void				load_textures(t_game *game);
void				clean_textures(t_game *game);
mlx_image_t			texture_to_image(t_game *game, mlx_image_t *img);

#endif