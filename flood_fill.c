/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:59:47 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/08/14 13:12:05 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **map, t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || (size_t)x >= game->rows || (size_t)y >= game->columns
		|| map[x][y] == '1')
		return ;
	if (map[x][y] == 'C')
		game->flood_fill_c++;
	if (map[x][y] == 'P')
		game->flood_fill_p++;
	if (map[x][y] == 'E')
		game->flood_fill_e++;
	map[x][y] = '1';
	fill(map, game, x - 1, y);
	fill(map, game, x + 1, y);
	fill(map, game, x, y - 1);
	fill(map, game, x, y + 1);
}

void	flood_fill(char **map, t_game *game)
{
	fill(map, game, game->player_position->x, game->player_position->y);
	if (game->flood_fill_c != game->collectibles_number
		|| game->flood_fill_e != 1 || game->flood_fill_p != 1)
	{
		ft_printf("Error\nFlood fill");
		exit(EXIT_SUCCESS);
	}
}
