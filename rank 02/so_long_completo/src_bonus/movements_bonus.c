/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:51 by abastida          #+#    #+#             */
/*   Updated: 2022/10/19 18:22:53 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libftprintf.h"

int	ft_movements_continue(int keycode, t_game *game)
{
	game->new_position = keycode;
	if (game->new_position == A)
	{
		if (check_left(game))
		{
			game->n_moves++;
			print_left(game);
		}
	}
	if (game->new_position == D)
	{
		if (check_right(game))
		{
			game->n_moves++;
			print_right(game);
		}
	}
	return (0);
}

int	move_if_escape(int keycode, t_game *game)
{
	game->new_position = keycode;
	if (game->new_position == ESC)
	{
		mlx_destroy(game->mlx);
		exit (0);
	}
	ft_printf ("\rNumber of moves: %d", game->n_moves);
	write(1, "\a", 1);
	check_is_exit(game);
	return (0);
}

int	ft_movements(int keycode, t_game *game)
{
	game->new_position = keycode;
	if (game->new_position == W)
	{
		if (check_up(game))
		{
			game->n_moves++;
			print_up(game);
		}
	}
	if (game->new_position == S)
	{
		if (check_down(game))
		{
			game->n_moves++;
			print_down(game);
		}
	}
	ft_movements_continue(keycode, game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[8].img_ptr,
		(game->map_width * 50) - 150, (game->map_height * 50));
	mlx_string_put(game->mlx, game->mlx_win, (game->map_width * 50) - 150,
		(game->map_height * 50) + 25, 2813300, ft_itoa(game->n_moves));
	move_if_escape(keycode, game);
	return (0);
}
