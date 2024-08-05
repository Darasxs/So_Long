/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:22:33 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/08/05 15:08:55 by dpaluszk         ###   ########.fr       */
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
	char	*line;
	char	*all_lines;
	char	*tmp;
	int		fd;
	size_t	line_len;
	size_t	rows;

	tmp = NULL;
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
	game->columns = line_len;
	all_lines = line;
	rows = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		tmp = ft_strjoin(all_lines, line);
		if (!(length_check(line, line_len)))
			error();
		free(all_lines);
		free(line);
		all_lines = tmp;
		rows++;
	}
	close(fd);
	game->rows = rows;
	game->map = ft_split(all_lines, '\n');
	// remember to free all_lines later
}
