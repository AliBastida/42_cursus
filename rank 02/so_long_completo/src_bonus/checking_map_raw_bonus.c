/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map_raw_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:45:03 by abastida          #+#    #+#             */
/*   Updated: 2022/11/02 13:09:15 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

int	check_the_map_raw_is_valid(t_game *game)
{
	if (!characters_are_valid(game))
		exit_error_map_raw(game);
	if (!characters_needed(game))
		exit_error_map_raw(game);
	if (!check_map_have_minimal_size(game))
		exit_error_map_raw(game);
	if (!the_map_is_rectangular(game))
		exit_error_map_raw(game);
	return (1);
}

int	map_is_surrounded_by_one(t_game *game)
{
	int	y;
	int	x;

	y = game->map_height;
	x = 0;
	while (game->map_width > x)
	{
		if (game->map[0][x] != '1' || game->map[y - 1][x] != '1')
		{
			printf ("game->map[0][%d] = %c\n", x, game->map[0][x]);
			exit_error_matrix(game);
		}
		x++;
	}
	y = 0;
	x = game->map_width;
	while (game->map_height > y)
	{
		if (game->map[y][0] != '1' || game->map[y][x - 1] != '1')
			exit_error_matrix(game);
		y++;
	}
	return (1);
}
