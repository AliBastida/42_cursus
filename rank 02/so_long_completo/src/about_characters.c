/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:17:51 by abastida          #+#    #+#             */
/*   Updated: 2022/10/14 11:58:02 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * @brief en este archivo tengo los chequeos de los caracteres. 
 * 
 */

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
				write(2 ,"Error: invalid characters in map\n", 34);
				return(0);
			}
			i++;
		}
	}
	return (1);
}

int	characters_needed(t_game *game)
{
	
	int there_is_p;
	int there_is_e;
	int i;

	game->there_is_c = 0;
	there_is_p = 0;
	there_is_e = 0;
   	i = 0;
	while (game->map_raw[i] != '\0')
	{
		if(game->map_raw[i] == 'C')
			game->there_is_c++;
		else if (game->map_raw[i] == 'E')
			there_is_e++;
		else if (game->map_raw[i] == 'P')
			there_is_p++; 
		i++;
	}
	game->num_collectives = game->there_is_c;
	if (there_is_p == 0 || game->there_is_c == 0 || there_is_e == 0)
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