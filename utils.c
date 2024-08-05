/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:19:54 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/08/05 09:45:48 by dpaluszk         ###   ########.fr       */
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
	my_struct->exit = NULL;
	my_struct->player = NULL;
}
