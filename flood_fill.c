/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:59:47 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/08/08 21:31:57 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || map[x][y] == '1')
		return ;
	if (map[x][y] == 'C')
		game->flood_fill_c++;
	if (map[x][y] == 'P')
		game->flood_fill_p++;
	if (map[x][y] == 'E')
		game->flood_fill_e++;
	map[x][y] = '1';
	flood_fill(map, game, x, y - 1);
	flood_fill(map, game, x, y + 1);
	flood_fill(map, game, x - 1, y);
	flood_fill(map, game, x + 1, y);
	ft_printf("C:%d\n", game->flood_fill_c);
	ft_printf("E:%d\n", game->flood_fill_e);
	ft_printf("P:%d\n", game->flood_fill_p);
	if(game->flood_fill_c < 1 || game->flood_fill_e != 1 || game->flood_fill_p != 1)
	{
		ft_printf("Error\nFlood fill");
		exit(EXIT_SUCCESS);
	}
}
