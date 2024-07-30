/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:47:45 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/07/30 19:02:49 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(void)
{
	mlx_strerror(mlx_errno);
	exit(EXIT_FAILURE);
}

void	struct_init_function(t_game *my_struct)
{
	my_struct->map = NULL;
	my_struct->move_count = 0;
}

void	read_map(char *map)
{
	char		*line;
	char		*all_lines;
	char		*tmp;
	int			fd;
	size_t		line_len;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		perror("Error openin file.");
			return ;
	}
	all_lines = NULL;
	line = get_next_line(fd);
	if(!line)
	{
		close(fd);
		return ;
	}
	line_len = ft_strlen(line);
	all_lines = line;
	while((line = get_next_line(fd)) != NULL)
	{
		tmp = ft_strjoin(all_lines, line);
		if(ft_strlen(line) != line_len)
			error();
		free(all_lines);
		free(line);
		all_lines = tmp;
	}
	close(fd);
	// remember to free all_lines later
}

bool	map_validation(t_game *game, char *map)
{
		
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		game = ft_calloc(sizeof(t_game), 1);
		struct_init_function(game);
		read_map(argv[1]);
		map_validation(game, argv[1]);
		
	}
}

	//	mlx_t			*mlx;
	//	mlx_texture_t	*texture;
	//	mlx_image_t		*img;
	//	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", false);
	//	if (!mlx)
	//		error();
	//	texture = mlx_load_png("./images/background.png");
	//	if(!texture)
	//		error();
	//	img = mlx_texture_to_image(mlx, texture);
	//	if (!img)
	//		error();
	//	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
	//		error();
	//	mlx_delete_image(mlx, img);
	//	mlx_delete_texture(texture);
	//	mlx_loop(mlx);
	//	mlx_terminate(mlx);
	// return (0);
