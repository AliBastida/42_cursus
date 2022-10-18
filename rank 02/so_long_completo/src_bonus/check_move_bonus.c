/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:04:02 by abastida          #+#    #+#             */
/*   Updated: 2022/10/18 11:39:34 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

int	check_is_exit(t_game *game)
{
	if ((game->num_collectives == 0)
		&& ((game->map[game->player_y][game->player_x - 1] == 'E')
		|| (game->map[game->player_y][game->player_x + 1] == 'E')
		|| (game->map[game->player_y - 1][game->player_x] == 'E')
		|| (game->map[game->player_y + 1][game->player_x] == 'E')))
	{
		write (1, "\e[1;35mYOU HAVE WIN \e[0m\n", 25);
		exit (0);
	}
	return (1);
}

int	check_left(t_game *game)
{
	if (game->new_position == A)
	{
		if ((game->map[game->player_y][game->player_x - 1] != '1')
			&& (game->map[game->player_y][game->player_x - 1] != 'E'))
		{
			if (game->map[game->player_y][game->player_x - 1] == 'C')
				game->num_collectives--;
				game->player_x--;
				game->map[game->player_y][game->player_x] = 'P';
				game->map[game->player_y][game->player_x + 1] = '0';
			return (1);
		}
	}
	return (0);
}

int	check_right(t_game *game)
{
	if (game->new_position == D)
	{
		if ((game->map[game->player_y][game->player_x + 1] != '1')
			&& (game->map[game->player_y][game->player_x + 1] != 'E'))
		{
			if (game->map[game->player_y][game->player_x + 1] == 'C')
				game->num_collectives--;
				game->player_x++;
				game->map[game->player_y][game->player_x] = 'P';
				game->map[game->player_y][game->player_x - 1] = '0';
			return (1);
		}
	}
	return (0);
}

int	check_up(t_game *game)
{
	if (game->new_position == W)
	{
		if ((game->map[game->player_y - 1][game->player_x] != '1')
			&& (game->map[game->player_y - 1][game->player_x] != 'E'))
		{
			if (game->map[game->player_y - 1][game->player_x] == 'C')
				game->num_collectives--;
				game->player_y--;
				game->map[game->player_y][game->player_x] = 'P';
				game->map[game->player_y + 1][game->player_x] = '0';
			return (1);
		}
	}
	return (0);
}

int	check_down(t_game *game)
{
	if (game->new_position == S)
	{
		if ((game->map[game->player_y + 1][game->player_x] != '1')
			&& (game->map[game->player_y + 1][game->player_x] != 'E'))
		{
			if (game->map[game->player_y + 1][game->player_x] == 'C')
				game->num_collectives--;
				game->player_y++;
				game->map[game->player_y][game->player_x] = 'P';
				game->map[game->player_y - 1][game->player_x] = '0';
			return (1);
		}
	}
	return (0);
}
