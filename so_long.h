/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:47:48 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/08/10 12:21:34 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	char			**map_copy;
	t_position		*exit_position;
	t_position		*player_position;
	size_t			collectibles_number;
	size_t			rows;
	size_t			columns;
	size_t			move_count;
	mlx_texture_t	*exit_texture;
	mlx_texture_t	*player_texture;
	mlx_texture_t	*collectible_texture;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*background_texture;
	mlx_image_t		*exit_image;
	mlx_image_t		*player_image;
	mlx_image_t		*collectible_image;
	mlx_image_t		*wall_image;
	mlx_image_t		*background_image;
	size_t			flood_fill_c;
	size_t			flood_fill_p;
	size_t			flood_fill_e;
}					t_game;

void				error(t_game *game);
void				free_map(t_game *game);
void				read_map(char *map, t_game *game);
bool				check_wall_around(t_game *game);
bool				check_top_wall(t_game *game);
bool				check_bottom_wall(t_game *game);
bool				check_side_walls(t_game *game);
bool				length_check(char *line, size_t first_line);
void				struct_init_function(t_game *my_struct);
void				struct_init_2(t_game *my_struct);
void				map_validation(t_game *game);
bool				check_collectibles(t_game *game);
bool				check_exit(t_game *game);
bool				check_player(t_game *game);
bool				check_characters(t_game *game);
bool				valid_char(char c);
void				render_map(t_game *game);
void				load_textures(t_game *game);
void				clean_textures(t_game *game);
mlx_image_t			*texture_to_image(t_game *game, char map_char);
void				clean_textures(t_game *game);
bool				extension_check(char *map);
void				player_movement(mlx_key_data_t key, void *param);
void				player_movement(mlx_key_data_t key, void *param);
void				render_textures(t_game *game);
void				move_up(t_game *game);
void				move_down(t_game *game);
void				move_left(t_game *game);
void				move_right(t_game *game);
void				fill(char **map, t_game *game, int x, int y);
void				flood_fill(char **map, t_game *game);

#endif