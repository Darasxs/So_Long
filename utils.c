/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:19:54 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/08/05 13:23:51 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(void)
{
	ft_printf("Error\n");
	mlx_strerror(mlx_errno);
	exit(EXIT_FAILURE);
}

void	struct_init_function(t_game *my_struct)
{
	my_struct->map = NULL;
	my_struct->move_count = 0;
	my_struct->exit = malloc(sizeof(*(my_struct->exit)) * 1);
	if (my_struct->exit)
	{
		my_struct->exit->x = 0;
		my_struct->exit->y = 0;
	}
	else
		my_struct->exit = NULL;
	my_struct->player = malloc(sizeof(*(my_struct->player)) * 1);
	if (my_struct->player)
	{
		my_struct->player->x = 0;
		my_struct->player->y = 0;
	}
	else
		my_struct->player = NULL;
}
