/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:23:11 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/08/04 16:25:52 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


//bool	map_validation(t_game *game)
//{

//}


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
	j = 0;
	i++;
	while (game->map[i])
	{
		j = 0;
		while(game->map[i][j])
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



// maybe i will creat map_validation_utils if there will be many functions for this