/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:22:33 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/08/09 18:27:02 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	char *line;
	char *all_lines;
	char *tmp;
	int fd;
	size_t line_len;
	size_t rows;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		error(game);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		error(game);
	}
	line_len = ft_strlen(line) - 1;
	game->columns = line_len;
	all_lines = line;
	rows = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		tmp = ft_strjoin(all_lines, line);
		free(all_lines);
		free(line);
		if (!tmp || !(length_check(line, line_len)))
		{
			free(tmp);
			close(fd);
			error(game);
		}
		all_lines = tmp;
		rows++;
	}
	close(fd);
	game->rows = rows;
	game->map = ft_split(all_lines, '\n');
	game->map_copy = ft_split(all_lines, '\n');
	if (!game->map || !game->map_copy)
	{
		free(all_lines);
		error(game);
	}
	free(all_lines);
}
