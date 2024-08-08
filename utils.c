/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:19:54 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/08/08 19:41:39 by dpaluszk         ###   ########.fr       */
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
	my_struct->columns = 0;
	my_struct->rows = 0;
	my_struct->collectibles_number = 0;
	my_struct->exit_position = malloc(sizeof(*(my_struct->exit_position)) * 1);
	if (my_struct->exit_position)
	{
		my_struct->exit_position->x = 0;
		my_struct->exit_position->y = 0;
	}
	else
		my_struct->exit_position = NULL;
	my_struct->player_position = malloc(sizeof(*(my_struct->player_position))
			* 1);
	if (my_struct->player_position)
	{
		my_struct->player_position->x = 0;
		my_struct->player_position->y = 0;
	}
	else
		my_struct->player_position = NULL;
}
void	struct_init_2(t_game *my_struct)
{
	my_struct->exit_texture = NULL;
	my_struct->player_texture = NULL;
	my_struct->collectible_texture = NULL;
	my_struct->wall_texture = NULL;
	my_struct->background_texture = NULL;
	my_struct->exit_image = NULL;
	my_struct->player_image = NULL;
	my_struct->collectible_image = NULL;
	my_struct->wall_image = NULL;
	my_struct->background_image = NULL;
	my_struct->flood_fill_c = 0;
	my_struct->flood_fill_e = 0;
	my_struct->flood_fill_p = 0;
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
		ft_printf("Wrong map extension\n");
		return (false);
	}
	if (!ft_strnstr(map + len - ft_strlen(ext), ext, ft_strlen(ext)))
	{
		ft_printf("Wrong map extension\n");
		return (false);
	}
	return (true);
}
