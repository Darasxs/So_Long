/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:47:45 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/08/04 19:52:46 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	// mlx_t	*mlx;
	if (argc == 2)
	{
		game = ft_calloc(sizeof(t_game), 1);
		struct_init_function(game);
		read_map(argv[1], game);
		check_wall_around(game);
		check_collectibles(game);
		// map_validation(game);
	}
	// mlx_loop(mlx);
	// mlx_terminate(mlx);
	return (0);
}
