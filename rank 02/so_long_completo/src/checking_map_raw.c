/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map_raw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:21:07 by abastida          #+#    #+#             */
/*   Updated: 2022/10/17 11:32:58 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

static int	error_message(void)
{
	write (2, "Error: The map is not surrounded by walls\n", 42);
	return (0);
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
			error_message();
		x++;
	}
	y = 0;
	x = game->map_width;
	while (game->map_height > y)
	{
		if (game->map[y][0] != '1' || game->map[y][x - 1] != '1')
			error_message();
		y++;
	}
	return (1);
}
