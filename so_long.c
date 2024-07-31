/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:47:45 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/07/31 13:22:51 by dpaluszk         ###   ########.fr       */
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
}
bool	length_check(char *line, size_t first_line)
{
	size_t	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len -= 1;
	if (first_line != len)
		return (false);

	return (true);
}

void	read_map(char *map, t_game *game)
{
	char	*line;
	char	*all_lines;
	char	*tmp;
	int		fd;
	size_t	line_len;

	tmp = NULL;
	game = NULL;
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n");
		return ;
	}
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return ;
	}
	line_len = ft_strlen(line) - 1;
	all_lines = line;
	while ((line = get_next_line(fd)) != NULL)
	{
		tmp = ft_strjoin(all_lines, line);
		if(!(length_check(line, line_len)))
			error();
		free(all_lines);
		free(line);
		all_lines = tmp;
	}
	printf("%s", all_lines);
	close(fd);
	// remember to free all_lines later
}

// bool	map_validation(t_game *game, char *map)
//{

//}

// void	open_window(void)
//{

//}

int	main(int argc, char **argv)
{
	t_game	*game;

	// mlx_t	*mlx;
	if (argc == 2)
	{
		game = ft_calloc(sizeof(t_game), 1);
		struct_init_function(game);
		read_map(argv[1], game);
		// map_validation(game, argv[1]);
	}
	// mlx_loop(mlx);
	// mlx_terminate(mlx);
	return (0);
}
