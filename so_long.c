/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:47:45 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/08/06 11:52:20 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	mlx_t	*mlx;
	if (argc == 2)
	{
		game = ft_calloc(sizeof(t_game), 1);
		struct_init_function(game);
		struct_init_2(game);
		read_map(argv[1], game);
		map_validation(game);
		mlx = mlx_init(50 * game->columns, 50 * game->rows, "so_long", true);
		game->mlx = mlx;
		render_map(game);
		mlx_loop(mlx);
		mlx_terminate(mlx);
	}
	else
		ft_printf("Wrong number of arguments");
	return (0);
}
