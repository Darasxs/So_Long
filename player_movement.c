/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:21:36 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/08/07 17:46:57 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	mlx_image_t	*img;
	
}

void	player_movement(mlx_key_data_t key, void *param)
{
	t_game *game;
	int x;
	int y;

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
	else if (key.key == MLX_KEY_D && key.action == MLX_PRESS && game->map[x][y
		+ 1] != '1')
	{
		move_left(game);
		game->move_count++;
		ft_printf("Move count:%d\n", game->move_count);
	}
	else if (key.key == MLX_KEY_A && key.action == MLX_PRESS && game->map[x][y
		- 1] != '1')
	{
		move_right(game);
		game->move_count++;
		ft_printf("Move count:%d\n", game->move_count);
	}
}
