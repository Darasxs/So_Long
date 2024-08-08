/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:23:11 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/08/08 21:35:23 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_validation(t_game *game)
{
	if (check_wall_around(game) == false)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (check_collectibles(game) == false)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (check_exit(game) == false)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (check_player(game) == false)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (check_characters(game) == false)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

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
			return (false);
		j++;
	}
	i++;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][0] != '1' || game->map[i][len - 1] != '1')
				return (false);
			j++;
		}
		i++;
	}
	j = 0;
	i--;
	while (game->map[i][j])
	{
		if (game->map[i][j] != '1')
			return (false);
		j++;
	}
	return (true);
}

bool	check_collectibles(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (game->map[i] && game->map[i + 1])
	{
		j = 1;
		while (game->map[i][j] && game->map[i][j + 1])
		{
			if (game->map[i][j] == 'C')
				game->collectibles_number++;
			j++;
		}
		i++;
	}
	if (game->collectibles_number < 1)
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
			{
				game->exit_position->x = i;
				game->exit_position->y = j;
				exit_counter++;
			}
			j++;
		}
		i++;
	}
	if (exit_counter != 1)
		return (false);
	else
		return (true);
}

bool	check_player(t_game *game)
{
	size_t	i;
	size_t	j;
	size_t	player_counter;

	i = 1;
	player_counter = 0;
	while (game->map[i] && game->map[i + 1])
	{
		j = 1;
		while (game->map[i][j] && game->map[i][j + 1])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_position->x = i;
				game->player_position->y = j;
				player_counter++;
			}
			j++;
		}
		i++;
	}
	if (player_counter != 1)
		return (false);
	else
		return (true);
}

bool	check_characters(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (game->map[i] && game->map[i + 1])
	{
		j = 1;
		while (game->map[i][j] && game->map[i][j + 1])
		{
			if (!valid_char(game->map[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
