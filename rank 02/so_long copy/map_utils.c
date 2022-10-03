/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:24:04 by abastida          #+#    #+#             */
/*   Updated: 2022/09/22 14:55:45 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/**
 * @brief recuerda que en la funcion strjoin puede ser origen de leaks. Pon strjoin del get next line.
 * 
 * @param filename 
 * @return int 
 */
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

	line = get_next_line(fd);
	game->map_raw = line;
	while (line)
	{
		line = get_next_line(fd);
		if(line != NULL)
			game->map_raw = ft_strjoin(game->map_raw, line);
	}
	return(1);
}

int	characters_are_valid(t_game *game)
{
	int i;

	i = 0;
	if (game->map_raw)
	{
		while (game->map_raw[i] != '\0')
		{
			if (game->map_raw[i] != '0' 
				&& game->map_raw[i] != '1'
				&& game->map_raw[i] != 'C'
				&& game->map_raw[i] != 'E'
				&& game->map_raw[i] != 'P'
				&& game->map_raw[i] != '\n')
			{
				write(2 ,"Error: invalid characters in map\n", 35);
				return(0);
			}
			i++;
		}
	}
	return (1);
}

int	characters_needed(t_game *game)
{
	int	there_is_c;
	int there_is_p;
	int there_is_e;
	int i;

	there_is_c = 0;
	there_is_p = 0;
	there_is_e = 0;
   	i = 0;
	while (game->map_raw[i] != '\0')
	{
		if(game->map_raw[i] == 'C')
			there_is_c++;
		else if (game->map_raw[i] == 'E')
			there_is_e++;
		else if (game->map_raw[i] == 'P')
			there_is_p++; 
		i++;
	}
	if (there_is_p == 0 || there_is_c == 0 || there_is_e == 0)
	{
		write (2, "Error: Not found all needed characters\n", 39); 
		return (0);
	}	
	if (there_is_p > 1) 
	{
		write(2, "Error: There is more than one player\n", 38);
		return (0);
	}
		
	return (1);
}

int	check_the_map_raw_is_valid(t_game *game)
{
	//1. No hay caracteres que no sean validos(que sean diferentes a 0, 1, C, E, P).
	if (!characters_are_valid(game))
		return (0);
	//2 El mapa debe tener almeos un starting position, un exit y un collectible
	if (!characters_needed(game))
		return (0);
	//3 el mapa tiene un tamano minimo de 3x3?
	if	(!check_map_have_minimal_size(game))
		return (0);
	//4 el mapa tiene que ser rectangular
	if	(!the_map_is_rectangular(game))
		return (0);

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

//CONSTRUIR LA MATRIZ
//1. hacer malloc para construir la matriz de game->map_width y game->map_height
int	create_matrix(t_game *game)
{
	int	i;

	i = 0;
	game->map = malloc(sizeof(char *) * (game->map_height + 1)); //creamos el eje de las h, son punteros que apuntaeran a las columnas, todavia no tiene valor-direccion asignado
	if (!game->map)
		return (0);
	while (i < game->map_height)
	{
		game->map[i] = malloc(sizeof(char) * (game->map_width + 1)); //creo la columna, y pongo la direccion que me devuelve el malloc en el slot del eje X que corresponde
		if (!game->map[i])
			return (0);
		game->map[i][game->map_width] = '\0';
		i++;
	}
	game->map[i] = NULL;
	return(1);
}

/*

//El eje de las X son punteros, por eso los hemos creado como  **map = sizeof(char *) * lo que sea
// Las Y son las columnas en este caso son strings de caracteres, y cada posicion de la y contiene un char
// por eso las Y se han creado como:  map[count] = malloc(sizeof(char))
// y por eso cuando se crea una columna con malloc, el puntero que me devuelve malloc,
// yo lo asocio a uno de los punteros que habia creado en el eje de las X

Y        X
* ->    ['1'] ['1'] ['1' ] ['1'] ['P'] ['\0']
* ->    ['1'] ['1'] ['1' ] ['1'] ['P'] ['\0']
* ->    ['1'] ['1'] ['1' ] ['1'] ['P'] ['\0']
*  >    ['1']  ['1'] ['1' ] ['1'] ['P'] ['\0']
NULL
*/

int fill_the_matrix(t_game *game)
{ 
//RELLENAR LA MATRIZ
//1. Cojo el map raw y voy poniendo los valores en la matriz
	int cont_x;
	int cont_y;
	int i;

	cont_x = 0;
	cont_y = 0;
	i = 0;
	while(cont_y < game->map_height)
	{
		cont_x = 0;
		while(cont_x < game->map_width)
		{
			game->map[cont_y][cont_x] = game->map_raw[i];
			//printf("THE player is supossed to be in Y=%d X=%d | %c\n", cont_y, cont_x,  game->map[cont_y][cont_x]);
			cont_x++;
			i++;
		}
		i++;
		cont_y++;
		if(game->map_raw[i] == '\0')
		{
			return(1);
		}
	}
	return(0);
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
			write(2, "Error: The map is not surrounded be walls\n", 42);
			return (0);
		}
		x++;
	}
	//printf("THE POS IN WHICH I AM IS x = %d y = %d\n", x, y);
	//printf("AND WHAT I HAVE IS %c\n", game->map[2][0]);
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
	//printf("THE player is supossed to be in X=1, Y=3 x | %c\n", game->map[3][1]);
	//printf("retorno 1\n");
	return (1);
}


int	take_the_map(char *filename, t_game *game)
{
	int fd;
	
	fd = open_map(filename);
	if (fd == 0)
		return(0);
	if(!parse_the_map(fd, game))
		return(0);
	if(!check_the_map_raw_is_valid(game))
		return(0);
	if(!create_matrix(game))
		return(0);
	if(!fill_the_matrix(game))
		return(0);
	if (!map_is_surrounded_by_one(game))
		return (0);
	init_player_position(game);
	//if(!search_there_is_path_to_exit(game))
		//return (0);
	fill_the_matrix(game);
	find_path(game, game->player_y, game->player_x);

	//Aqui nos faltan nuestros ultimo chequeo
	//que haya una salida posible entre el player y el exit
	return(1);
}


