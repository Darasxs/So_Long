/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:47:48 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/07/29 20:05:23 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#define WIDTH 1920
#define HEIGHT 1080

typedef struct mlx_game_s
{
	mlx_t	*mlx
	int		count_moves;
}				mlx_game_t;

void	error(void);



# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	error(void);

#endif