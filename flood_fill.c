/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:59:47 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/08/08 19:41:43 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
		game->flood_fill_c++;
	if (map[y][x] == 'P')
		game->flood_fill_p++;
	if (map[y][x] == 'E')
		game->flood_fill_e++;
	map[y][x] = '1';
	flood_fill(map, game, x, y - 1);
	flood_fill(map, game, x, y + 1);
	flood_fill(map, game, x - 1, y);
	flood_fill(map, game, x + 1, y);
}
