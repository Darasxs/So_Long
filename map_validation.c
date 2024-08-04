/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:23:11 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/08/04 20:05:30 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// maybe i will creat map_validation_utils if there will be many functions for this

bool	map_validation(t_game *game)
{
	if (check_wall_around(game) == false)
		return (false);
	if (check_collectibles(game) == false)
		return (false);
	if (check_exit(game) == false)
		return (false);
	return (true);
}

// still need to split this funtion, it's too long
bool	check_wall_around(t_game *game)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(game->map[i]);
	while (game->map[0][j])
	{
		if (game->map[0][j] != '1')
		{
			printf("false");
			return (false);
		}
		j++;
	}
	i++;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][0] != '1' || game->map[i][len - 1] != '1')
			{
				printf("false");
				return (false);
			}
			j++;
		}
		i++;
	}
	j = 0;
	i--;
	while (game->map[i][j])
	{
		if (game->map[i][j] != '1')
		{
			printf("false");
			return (false);
		}
		j++;
	}
	return (true);
}

bool	check_collectibles(t_game *game)
{
	size_t	collectible;
	size_t	i;
	size_t	j;

	collectible = 0;
	i = 1;
	while (game->map[i] && game->map[i + 1])
	{
		j = 1;
		while (game->map[i][j] && game->map[i][j + 1])
		{
			if (game->map[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	if (collectible < 1)
		return (false);
	else
		return (true);
}
bool	check_exit(t_game *game)
{
	size_t	i;
	size_t	j;
	size_t	exit_counter;

	i = 1;
	exit_counter = 0;
	while (game->map[i] && game->map[i + 1])
	{
		j = 1;
		while (game->map[i][j] && game->map[i][j + 1])
		{
			if (game->map[i][j] == 'E')
				exit_counter++;
			j++;
		}
		i++;
	}
	if (exit_counter != 1)
		return (false);
	else
		return (true);
}
