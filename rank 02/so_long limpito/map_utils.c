/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:37:29 by abastida          #+#    #+#             */
/*   Updated: 2022/09/29 15:33:38 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file map_utils.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-23
 * En este archivo está todo lo relacionado con el mapa. 
 * 1. Lo abro, y si no puedo, lanzo un mensaje de error. 
 * 2. Lo leo con GNL y lo meto en un array para poder hacer los chequeos. 
 * 3. En check map->raw hago las comprobaciones del mapa.
 * 4. Finalmente, chequeo en la matriz si está rodeado de unos. 
 * @copyright Copyright (c) 2022
 * 
 */

#include "so_long.h"

int	open_map(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write (2, "Error: File cannot be opened\n", 30);
		return(0);
	}
	return (fd);
}

int	parse_the_map(int fd, t_game *game)
{
	char *line;
	int take_more_lines;

	take_more_lines = 1;
	game->map_raw = NULL;

	//while ((take_more_lines) || (!line))
	//{

		line = get_next_line(fd);
		printf("Cojo la linea |%s|\n", line);
		while(line != NULL)
		{
			printf("Antes de strjoin line vale |%s|", line);
			game->map_raw = ft_strjoin(game->map_raw, line);
			printf("Despues de strjoin line vale |%s|", line);
			free(line);
			line = get_next_line(fd);
		}
	//	else
	//		take_more_lines = 0;		
	//}
	return(1);
}

int	check_the_map_raw_is_valid(t_game *game)
{
	//1. No hay caracteres que no sean validos(que sean diferentes a 0, 1, C, E, P).
	if (!characters_are_valid(game))
		exit_error_map_raw(game);
	//2 El mapa debe tener almeos un starting position, un exit y un collectible
	if (!characters_needed(game))
		exit_error_map_raw(game);
	//3 el mapa tiene un tamano minimo de 3x3?
	if	(!check_map_have_minimal_size(game))
		exit_error_map_raw(game);
	//4 el mapa tiene que ser rectangular
	if	(!the_map_is_rectangular(game))
		exit_error_map_raw(game);
	return (1);
}


//Miramos si el mapa hace minimo 3x3
// de paso ya cojemos el game->map_width
// y el game->map_height
int	check_map_have_minimal_size(t_game *game)
{
	int i;
	game->map_height = 0;
	game->map_width = 0;
	i = 0;
	//cojo el "supuesto" ancho del mapa
	while (game->map_raw[game->map_width] != '\n' && game->map_raw[game->map_width] != '\0')
		game->map_width++;

	//cojo el height del mapa(altura)
	//cada vez que se encuentre un \n que sume uno a game->map_height
	while (game->map_raw[i])
	{
		//si hay un salto de linea mapheight es mapheight+1
		if (game->map_raw[i] == '\n' || game->map_raw[i + 1] == '\0')
			game->map_height++;
		i++;
	}
	if(game->map_width < 3)
	{
		write(2, "Error: the map width value is not enough to be valid\n", 52);
		return(0);
	}
	if(game->map_height < 3)
	{
		write(2, "Error: the map height value is not enough to be valid\n", 53);
		return(0);
	}
	return (1);
}

int the_map_is_rectangular(t_game *game)
{
	int tmp_line_width;
	int i;

	i = 0;
	tmp_line_width = 0;
	while(game->map_raw[i])
	{
		if(game->map_raw[i] == '\n' || game->map_raw[i] == '\0')
		{
			if(tmp_line_width != game->map_width)
			{
				write(2, "Error: The map is not rectangular\n", 34);
				return(0);
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
	return(1);
}
int	map_is_surrounded_by_one(t_game *game)
{
	int y;
	int i;
	int x;

	y = game->map_height;
	i = 0;
	x = 0;
	
	while (game->map_width > x)
	{
		if (game->map[0][x] != '1' || game->map[y-1][x] != '1')
		{
			write(2, "Error: The map is not surrounded by walls\n", 42);
			return (0);
		}
		x++;
	}
	y = 0;
	x = game->map_width;

	while (game->map_height > y)
	{
		if (game->map[y][0] != '1' || game->map[y][x-1] != '1')
		{
			write(2, "Error: The map is not surrounded be walls\n", 42);
			return (0);
		}
		y++;	
	}
	return (1);
}
