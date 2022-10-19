/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:06:11 by abastida          #+#    #+#             */
/*   Updated: 2022/10/19 17:57:43 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	print_map_continue(t_game *game)
{
	game->map_height = 0;
	while (game->map[game->map_height])
	{
		game->map_width = 0;
		while (game->map[game->map_height][game->map_width])
		{
			if (game->map[game->map_height][game->map_width] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img[2].img_ptr, game->map_width * 50,
					game->map_height * 50);
			else if (game->map[game->map_height][game->map_width] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img[7].img_ptr, game->map_width * 50,
					game->map_height * 50);
			game->map_width++;
		}
		game->map_height++;
	}
}

void	print_map(t_game *game)
{
	print_map_continue(game);
	game->map_height = 0;
	while (game->map[game->map_height])
	{
		game->map_width = 0;
		while (game->map[game->map_height][game->map_width])
		{
			if (game->map[game->map_height][game->map_width] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img[1].img_ptr, game->map_width * 50,
					game->map_height * 50);
			else if (game->map[game->map_height][game->map_width] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img[0].img_ptr, game->map_width * 50,
					game->map_height * 50);
			else if (game->map[game->map_height][game->map_width] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img[3].img_ptr, game->map_width * 50,
					game->map_height * 50);
			game->map_width++;
		}
		game->map_height++;
	}
}
