/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:28:12 by abastida          #+#    #+#             */
/*   Updated: 2022/10/19 17:17:49 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	upload_accesories(t_game *game, int height, int width)
{
	game->img[0].img_ptr = mlx_xpm_file_to_image(game->mlx, GRASS, &height,
			&width);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->img[0].img_ptr, height, width);
	game->img[1].img_ptr = mlx_xpm_file_to_image(game->mlx, WALL, &height,
			&width);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->img[1].img_ptr, height, width);
	game->img[2].img_ptr = mlx_xpm_file_to_image(game->mlx, COLL, &height,
			&width);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->img[2].img_ptr, height, width);
	game->img[3].img_ptr = mlx_xpm_file_to_image(game->mlx, EXIT, &height,
			&width);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->img[3].img_ptr, height, width);
}

static void	upload_princess(t_game *game, int height, int width)
{
	game->img[4].img_ptr = mlx_xpm_file_to_image(game->mlx, BACK_P, &width,
			&height);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->img[4].img_ptr, height, width);
	game->img[5].img_ptr = mlx_xpm_file_to_image(game->mlx, LEFT_P, &width,
			&height);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->img[5].img_ptr, height, width);
	game->img[6].img_ptr = mlx_xpm_file_to_image(game->mlx, RIGHT_P, &width,
			&height);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->img[6].img_ptr, height, width);
	game->img[7].img_ptr = mlx_xpm_file_to_image(game->mlx, FRONT_P, &width,
			&height);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->img[7].img_ptr, height, width);
}

void	upload_img(t_game *game)
{
	int		height;
	int		width;

	height = 0;
	width = 0;
	game->img = (t_img *)malloc(sizeof(t_img) * (8 + 1));
	upload_accesories (game, height, width);
	upload_princess (game, height, width);
}
