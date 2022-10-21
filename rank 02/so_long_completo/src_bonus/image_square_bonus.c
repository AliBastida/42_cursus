/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_square_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:11:29 by abastida          #+#    #+#             */
/*   Updated: 2022/10/21 11:37:33 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	upload_black_square(t_game *game, int height, int width)
{
	game->img[8].img_ptr = mlx_xpm_file_to_image(game->mlx, BLACK_SQUARE,
			&height, &width);
	if (!game->img[8].img_ptr)
	{
		ft_printf("Error with the images");
		exit(1);
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->img[8].img_ptr, height, width);
}
