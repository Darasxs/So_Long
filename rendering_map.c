/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:18:42 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/08/05 20:40:54 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_textures(t_game *game)
{
	mlx_delete_texture();
}

mlx_image_t	*texture_to_image(t_game *game, mlx_image_t *img)
{
	if (game->map[x][y] == '1')
	{
		img = mlx_texture_to_image();
	}
	return (img);
}

void	load_textures(t_game *game)
{
	game->exit = mlx_load_png("/Users/dpaluszk/Documents/projects/so_long/images/exit.png");
	game->player = mlx_load_png("/Users/dpaluszk/Documents/projects/so_long/images/player.png");
	game->collectible = mlx_load_png("/Users/dpaluszk/Documents/projects/so_long/images/collectible.png");
	game->wall = mlx_load_png("/Users/dpaluszk/Documents/projects/so_long/images/wall.png");
	game->background = mlx_load_png("/Users/dpaluszk/Documents/projects/so_long/images/background.png");
}

void	render_map(t_game *game)
{
	mlx_image_t *img;
	size_t i;
	size_t j;

	i = 0;
	load_textures(game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			img = texture_to_image(game, img);
			mlx_image_to_window();
			j++;
		}
		i++;
	}
}