/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:37:29 by abastida          #+#    #+#             */
/*   Updated: 2022/10/17 11:32:53 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	open_map(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write (2, "Error: File cannot be opened\n", 30);
		return (0);
	}
	return (fd);
}

int	parse_the_map(int fd, t_game *game)
{
	char	*line;

	game->map_raw = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->map_raw = ft_strjoin(game->map_raw, line);
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	check_map_have_minimal_size(t_game *game)
{
	int	i;

	game->map_height = 0;
	game->map_width = 0;
	i = 0;
	while (game->map_raw[game->map_width] != '\n'
		&& game->map_raw[game->map_width] != '\0')
		game->map_width++;
	while (game->map_raw[i])
	{
		if (game->map_raw[i] == '\n' || game->map_raw[i + 1] == '\0')
			game->map_height++;
		i++;
	}
	if (game->map_width < 3)
	{
		write (2, "Error: the map width value is not enough to be valid\n", 52);
		return (0);
	}
	if (game->map_height < 3)
	{
		write (2, "Error: the map height value is not enough to be valid\n", 53);
		return (0);
	}
	return (1);
}

int	the_map_is_rectangular(t_game *game)
{
	int	tmp_line_width;
	int	i;

	i = 0;
	tmp_line_width = 0;
	while (game->map_raw[i])
	{
		if (game->map_raw[i] == '\n' || game->map_raw[i] == '\0')
		{
			if (tmp_line_width != game->map_width)
			{
				write (2, "Error: The map is not rectangular\n", 34);
				return (0);
			}
			else
			{
				tmp_line_width = 0;
			}
		}
		else
			tmp_line_width++;
		i++;
	}
	return (1);
}
