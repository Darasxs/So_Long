/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:21:36 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/08/08 12:12:53 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->player_position->x][game->player_position->y] == 'E')
	{
		mlx_image_to_window(game->mlx, game->exit_image, game->player_position->y
			* 50, game->player_position->x * 50);
	}
	else
	{	
		mlx_image_to_window(game->mlx, game->background_image,
			game->player_position->y * 50, game->player_position->x * 50);
	}
	game->player_position->x--;
	if (game->map[game->player_position->x][game->player_position->y] == 'C')
	{
		mlx_image_to_window(game->mlx, game->background_image,
			game->player_position->y * 50, game->player_position->x * 50);
		game->collectibles_number--;
	}
	mlx_image_to_window(game->mlx, game->player_image, game->player_position->y
		* 50, game->player_position->x * 50);
}

void	move_down(t_game *game)
{
	if (game->map[game->player_position->x][game->player_position->y] == 'E')
	{
		mlx_image_to_window(game->mlx, game->exit_image, game->player_position->y
			* 50, game->player_position->x * 50);
	}
	else
	{	
		mlx_image_to_window(game->mlx, game->background_image,
			game->player_position->y * 50, game->player_position->x * 50);
	}
	game->player_position->x++;
	if (game->map[game->player_position->x][game->player_position->y] == 'C')
	{
		mlx_image_to_window(game->mlx, game->background_image,
			game->player_position->y * 50, game->player_position->x * 50);
		game->collectibles_number--;
	}
	mlx_image_to_window(game->mlx, game->player_image, game->player_position->y
		* 50, game->player_position->x * 50);
}

void	move_left(t_game *game)
{
	if (game->map[game->player_position->x][game->player_position->y] == 'E')
	{
		mlx_image_to_window(game->mlx, game->exit_image, game->player_position->y
			* 50, game->player_position->x * 50);
	}
	else
	{	
		mlx_image_to_window(game->mlx, game->background_image,
			game->player_position->y * 50, game->player_position->x * 50);
	}
	game->player_position->y++;
	if (game->map[game->player_position->x][game->player_position->y] == 'C')
	{
		mlx_image_to_window(game->mlx, game->background_image,
			game->player_position->y * 50, game->player_position->x * 50);
		game->collectibles_number--;
	}
	mlx_image_to_window(game->mlx, game->player_image, game->player_position->y
		* 50, game->player_position->x * 50);
}

void	move_right(t_game *game)
{
	if (game->map[game->player_position->x][game->player_position->y] == 'E')
	{
		mlx_image_to_window(game->mlx, game->exit_image, game->player_position->y
			* 50, game->player_position->x * 50);
	}
	else
	{	
		mlx_image_to_window(game->mlx, game->background_image,
			game->player_position->y * 50, game->player_position->x * 50);
	}
	game->player_position->y--;
	if (game->map[game->player_position->x][game->player_position->y] == 'C')
	{
		mlx_image_to_window(game->mlx, game->background_image,
			game->player_position->y * 50, game->player_position->x * 50);
		game->collectibles_number--;
	}
	mlx_image_to_window(game->mlx, game->player_image, game->player_position->y
		* 50, game->player_position->x * 50);
}

void	player_movement(mlx_key_data_t key, void *param)
{
	t_game	*game;
	int		x;
	int		y;

	game = param;
	x = game->player_position->x;
	y = game->player_position->y;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
	{
		// free
		exit(0);
	}
	else if (key.key == MLX_KEY_W && key.action == MLX_PRESS && game->map[x
		- 1][y] != '1')
	{
		move_up(game);
		game->move_count++;
		ft_printf("Move count:%d\n", game->move_count);
	}
	 else if (key.key == MLX_KEY_S && key.action == MLX_PRESS && game->map[x
		+ 1][y] != '1')
	{
		move_down(game);
		game->move_count++;
		ft_printf("Move count:%d\n", game->move_count);
	}
	 else if (key.key == MLX_KEY_D && key.action == MLX_PRESS
		&& game->map[x][y
		+ 1] != '1')
	{
		move_left(game);
		game->move_count++;
		ft_printf("Move count:%d\n", game->move_count);
	}
	 else if (key.key == MLX_KEY_A && key.action == MLX_PRESS
		&& game->map[x][y
		- 1] != '1')
	{
		move_right(game);
		game->move_count++;
		ft_printf("Move count:%d\n", game->move_count);
	}
}
