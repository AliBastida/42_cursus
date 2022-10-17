/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:17:51 by abastida          #+#    #+#             */
/*   Updated: 2022/10/17 12:10:38 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	error_message(void)
{
	write (2, "Error: There is a problem with the characters\n", 46);
	return (0);
}

int	characters_are_valid(t_game *game)
{
	int	i;

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
				error_message();
			i++;
		}
	}
	return (1);
}

int	characters_needed(t_game *game)
{
	int	i;

	game->there_is_c = 0;
	game->there_is_p = 0;
	game->there_is_e = 0;
	i = 0;
	while (game->map_raw[i] != '\0')
	{
		if (game->map_raw[i] == 'C')
			game->there_is_c++;
		else if (game->map_raw[i] == 'E')
			game->there_is_e++;
		else if (game->map_raw[i] == 'P')
			game->there_is_p++;
		i++;
	}
	game->num_collectives = game->there_is_c;
	if (game->there_is_p == 0 || game->there_is_c == 0 || game->there_is_e == 0)
		error_message();
	if (game->there_is_p != 1)
		error_message();
	return (1);
}
