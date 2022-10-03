/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_the_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:51:33 by abastida          #+#    #+#             */
/*   Updated: 2022/09/29 10:45:34 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief en este archivo tengo todo lo relativo para chequear el mapa y ver si se puede crear la matriz o no.
 * 
 */



int check_num_params_are_valid(int argc)
{
	if(argc != 2)
	{
		write(2, "Error: num params are invalid\n", 30);
		return(0);
	}
	return(1);
}

int	check_filename_is_valid(char *filename)
{
	int length;
	int error;

	error = 0;
	length = ft_strlen(filename); 
	//si no  ocupa almenos 5 caracteres (x.ber)
	if(length < 5)
		error = 1; 
	else
	{
		//Termina en .ber
		if (filename[length -1] != 'r')
			error = 1;
		else if (filename[length -2] != 'e')
			error = 1;
		else if (filename[length -3] != 'b')
			error = 1;
		else if (filename[length -4] != '.')
			error = 1;
	}
	if(error == 1)
	{
		write(2, "Error Invalid Filename\n", 24);
		return(0);
	}
	return(1);
}

int checking_the_map(int fd, t_game *game)
{
	if(!parse_the_map(fd, game))
		return(0);
	if(!check_the_map_raw_is_valid(game))
		return(0);
	if(!create_matrix(game))
		return (exit_error_matrix(game));
	if(!fill_the_matrix(game))
		return (exit_error_matrix(game));
	if (!map_is_surrounded_by_one(game))
		return (exit_error_matrix(game));
	init_player_position(game);
	if (!find_path(game, game->player_y, game->player_x))
	{
		write(2, ERROR_NO_PATH, 30);
		return (exit_error_matrix(game));
	}
	if(!fill_the_matrix(game))
		return (exit_error_matrix(game));
	return(1);
}

int	take_the_map(char *filename, t_game *game)
{
	int fd;
	
	fd = open_map(filename);
	if (fd == 0)
		return(0);
	if (!checking_the_map(fd, game))
		return(0);
	return(1);
}

int check_params_are_valids(int argc, char **argv)
{
	if(!check_num_params_are_valid(argc))
		return(0);
	if(!check_filename_is_valid(argv[1]))
		return(0);

	return(1);
}
