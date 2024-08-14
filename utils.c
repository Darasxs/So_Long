/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:19:54 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/08/14 13:06:30 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(t_game *game)
{
	size_t	i;

	i = 0;
	ft_printf("Error\n");
	if (game->map)
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
		game->map = NULL;
	}
	i = 0;
	if (game->map_copy)
	{
		while (game->map_copy[i])
			free(game->map_copy[i++]);
		free(game->map_copy);
		game->map_copy = NULL;
	}
	if(game->exit_position)
		free(game->exit_position);
	if(game->player_position)
		free(game->player_position);
	exit(EXIT_FAILURE);
}

void	free_map(t_game *game)
{
	size_t	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
		game->map = NULL;
	}
	i = 0;
	if (game->map_copy)
	{
		while (game->map_copy[i])
			free(game->map_copy[i++]);
		free(game->map_copy);
		game->map_copy = NULL;
	}
	if(game->exit_position)
		free(game->exit_position);
	if(game->player_position)
		free(game->player_position);
	exit(EXIT_SUCCESS);
}

void	game_success(t_game *game)
{
	size_t	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
		game->map = NULL;
	}
	i = 0;
	if (game->map_copy)
	{
		while (game->map_copy[i])
			free(game->map_copy[i++]);
		free(game->map_copy);
		game->map_copy = NULL;
	}
	game->move_count++;
	if(game->exit_position)
		free(game->exit_position);
	if(game->player_position)
		free(game->player_position);
	ft_printf("Move count:%d\n", game->move_count);
	exit(EXIT_SUCCESS);
}

bool	valid_char(char c)
{
	if (c != 'P' && c != 'E' && c != 'C' && c != '1' && c != '0')
		return (false);
	return (true);
}

bool	extension_check(char *map)
{
	size_t		len;
	const char	*ext;

	ext = ".ber";
	len = ft_strlen(map);
	if (len < ft_strlen(ext))
	{
		ft_printf("Error\nWrong map extension\n");
		return (false);
	}
	if (!ft_strnstr(map + len - ft_strlen(ext), ext, ft_strlen(ext)))
	{
		ft_printf("Error\nWrong map extension\n");
		return (false);
	}
	return (true);
}
