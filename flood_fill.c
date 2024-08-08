/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:59:47 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/08/08 23:50:06 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **map, t_game *game, int x, int y, int max_x, int max_y)
{
	if (x < 0 || y < 0 || x >= max_x || y >= max_y || map[x][y] == '1')
		return ;
	if (map[x][y] == 'C')
		game->flood_fill_c++;
	if (map[x][y] == 'P')
		game->flood_fill_p++;
	if (map[x][y] == 'E')
		game->flood_fill_e++;
	map[x][y] = '1';
	fill(map, game, x - 1, y, max_x, max_y);
	fill(map, game, x + 1, y, max_x, max_y);
	fill(map, game, x, y - 1, max_x, max_y);
	fill(map, game, x, y + 1, max_x, max_y);
}

void	flood_fill(char **map, t_game *game)
{
	fill(map, game, game->player_position->x, game->player_position->y, game->rows, game->columns);

	if (game->flood_fill_c < 1 || game->flood_fill_e != 1 || game->flood_fill_p != 1)
	{
		ft_printf("Error\nFlood fill");
		exit(EXIT_SUCCESS);
	}
}