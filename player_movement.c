/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:21:36 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/08/09 14:31:29 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->player_position->x - 1][game->player_position->y] == 'E'
		&& game->collectibles_number == 0)
			free_map(game);
	if (game->map[game->player_position->x][game->player_position->y] == 'E')
	{
		mlx_image_to_window(game->mlx, game->exit_image,
			game->player_position->y * 50, game->player_position->x * 50);
	}
	else
		mlx_image_to_window(game->mlx, game->background_image,
			game->player_position->y * 50, game->player_position->x * 50);
	game->player_position->x--;
	if (game->map[game->player_position->x][game->player_position->y] == 'C')
	{
		game->collectibles_number--;
		mlx_image_to_window(game->mlx, game->background_image,
			game->player_position->y * 50, game->player_position->x * 50);
		game->map[game->player_position->x][game->player_position->y] = '0';
	}
	mlx_image_to_window(game->mlx, game->player_image, game->player_position->y
		* 50, game->player_position->x * 50);
	game->move_count++;
	ft_printf("Move count:%d\n", game->move_count);
}

void	move_down(t_game *game)
{
	if (game->map[game->player_position->x + 1][game->player_position->y] == 'E'
		&& game->collectibles_number == 0)
			free_map(game);
	if (game->map[game->player_position->x][game->player_position->y] == 'E')
		mlx_image_to_window(game->mlx, game->exit_image,
			game->player_position->y * 50, game->player_position->x * 50);
	else
		mlx_image_to_window(game->mlx, game->background_image,
			game->player_position->y * 50, game->player_position->x * 50);
	game->player_position->x++;
	if (game->map[game->player_position->x][game->player_position->y] == 'C')
	{
		game->collectibles_number--;
		mlx_image_to_window(game->mlx, game->background_image,
			game->player_position->y * 50, game->player_position->x * 50);
		game->map[game->player_position->x][game->player_position->y] = '0';
	}
	mlx_image_to_window(game->mlx, game->player_image, game->player_position->y
		* 50, game->player_position->x * 50);
	game->move_count++;
	ft_printf("Move count:%d\n", game->move_count);
}

void	move_left(t_game *game)
{
	if (game->map[game->player_position->x][game->player_position->y + 1] == 'E'
		&& game->collectibles_number == 0)
			free_map(game);
	if (game->map[game->player_position->x][game->player_position->y] == 'E')
		mlx_image_to_window(game->mlx, game->exit_image,
			game->player_position->y * 50, game->player_position->x * 50);
	else
		mlx_image_to_window(game->mlx, game->background_image,
			game->player_position->y * 50, game->player_position->x * 50);
	game->player_position->y++;
	if (game->map[game->player_position->x][game->player_position->y] == 'C')
	{
		game->collectibles_number--;
		mlx_image_to_window(game->mlx, game->background_image,
			game->player_position->y * 50, game->player_position->x * 50);
		game->map[game->player_position->x][game->player_position->y] = '0';
	}
	mlx_image_to_window(game->mlx, game->player_image, game->player_position->y
		* 50, game->player_position->x * 50);
	game->move_count++;
	ft_printf("Move count:%d\n", game->move_count);
}

void	move_right(t_game *game)
{
	if (game->map[game->player_position->x][game->player_position->y - 1] == 'E'
		&& game->collectibles_number == 0)
			free_map(game);
	if (game->map[game->player_position->x][game->player_position->y] == 'E')
		mlx_image_to_window(game->mlx, game->exit_image,
			game->player_position->y * 50, game->player_position->x * 50);
	else
		mlx_image_to_window(game->mlx, game->background_image,
			game->player_position->y * 50, game->player_position->x * 50);
	game->player_position->y--;
	if (game->map[game->player_position->x][game->player_position->y] == 'C')
	{
		game->collectibles_number--;
		mlx_image_to_window(game->mlx, game->background_image,
			game->player_position->y * 50, game->player_position->x * 50);
		game->map[game->player_position->x][game->player_position->y] = '0';
	}
	mlx_image_to_window(game->mlx, game->player_image, game->player_position->y
		* 50, game->player_position->x * 50);
	game->move_count++;
	ft_printf("Move count:%d\n", game->move_count);
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
		free_map(game);
	else if (key.key == MLX_KEY_W && key.action == MLX_PRESS && game->map[x
		- 1][y] != '1')
		move_up(game);
	else if (key.key == MLX_KEY_S && key.action == MLX_PRESS && game->map[x
		+ 1][y] != '1')
		move_down(game);
	else if (key.key == MLX_KEY_D && key.action == MLX_PRESS && game->map[x][y
		+ 1] != '1')
		move_left(game);
	else if (key.key == MLX_KEY_A && key.action == MLX_PRESS && game->map[x][y
		- 1] != '1')
		move_right(game);
}
