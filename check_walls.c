/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:02:22 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/08/10 13:37:35 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_top_wall(t_game *game)
{
	size_t	j;

	j = 0;
	while (game->map[0][j])
	{
		if (game->map[0][j] != '1')
			return (false);
		j++;
	}
	return (true);
}

bool	check_bottom_wall(t_game *game)
{
	size_t	j;
	size_t	i;

	i = 0;
	while (game->map[i + 1] == NULL)
		i++;
	j = 0;
	while (game->map[i][j])
	{
		if (game->map[i][j] != '1')
			return (false);
		j++;
	}
	return (true);
}

bool	check_side_walls(t_game *game)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 1;
	len = ft_strlen(game->map[i]);
	while (game->map[i])
	{
		j = 1;
		while (game->map[i][j])
		{
			if (game->map[i][0] != '1' || game->map[i][len - 1] != '1')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_wall_around(t_game *game)
{
	if (check_top_wall(game) == false)
		return (false);
	if (check_bottom_wall(game) == false)
		return (false);
	if (check_side_walls(game) == false)
		return (false);
	return (true);
}
