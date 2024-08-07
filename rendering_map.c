/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:18:42 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/08/07 17:46:44 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_textures(t_game *game)
{
	mlx_delete_texture(game->exit_texture);
	mlx_delete_texture(game->player_texture);
	mlx_delete_texture(game->wall_texture);
	mlx_delete_texture(game->background_texture);
	mlx_delete_texture(game->collectible_texture);
}

mlx_image_t	*texture_to_image(t_game *game, char map_char)
{
	if (map_char == '0')
		return (game->background_image);
	else if (map_char == '1')
		return (game->wall_image);
	else if (map_char == 'E')
		return (game->exit_image);
	else if (map_char == 'P')
		return (game->player_image);
	else if (map_char == 'C')
		return (game->collectible_image);
	else
		return (NULL);
}

void	load_textures(t_game *game)
{
	game->exit_texture = mlx_load_png("/Users/dpaluszk/Documents/projects/so_long/images/exit.png");
	game->player_texture = mlx_load_png("/Users/dpaluszk/Documents/projects/so_long/images/player.png");
	game->collectible_texture = mlx_load_png("/Users/dpaluszk/Documents/projects/so_long/images/collectible.png");
	game->wall_texture = mlx_load_png("/Users/dpaluszk/Documents/projects/so_long/images/wall.png");
	game->background_texture = mlx_load_png("/Users/dpaluszk/Documents/projects/so_long/images/background.png");
}

void	render_textures(t_game *game)
{
	game->exit_image = mlx_texture_to_image(game->mlx, game->exit_texture);
	game->player_image = mlx_texture_to_image(game->mlx, game->player_texture);
	game->collectible_image = mlx_texture_to_image(game->mlx,
			game->collectible_texture);
	game->wall_image = mlx_texture_to_image(game->mlx, game->wall_texture);
	game->background_image = mlx_texture_to_image(game->mlx,
			game->background_texture);
}

void	render_map(t_game *game)
{
	mlx_image_t	*img;
	size_t		i;
	size_t		j;

	i = 0;
	load_textures(game);
	render_textures(game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			img = texture_to_image(game, game->map[i][j]);
			if (img)
				mlx_image_to_window(game->mlx, img, j * 50, i * 50);
			j++;
		}
		ft_printf("%s\n", game->map[i]);
		i++;
	}
	clean_textures(game);
}
