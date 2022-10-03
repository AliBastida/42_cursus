/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:28:12 by abastida          #+#    #+#             */
/*   Updated: 2022/09/22 14:37:52 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
/**
 * @brief esta funcion carga las imgs.
 * 
 * @param game 
 */

void    upload_img(t_game *game)
{
	int		height;
	int		width;

	printf("hola");
    game->img = malloc(sizeof(t_img) * (10 + 1));
    game->img[0].img_ptr = mlx_xpm_file_to_image(game->mlx, "imgpersonales/pared.xpm", &width, &height);
	game->img[0].data = (int *)mlx_get_data_addr(game->img[0].img_ptr,
			&game->img[0].bpp, &game->img[0].size_l, &game->img[0].endian);

	game->img[1].img_ptr = mlx_xpm_file_to_image(game->mlx, "imgpersonales/suelo.xpm", &width, &height);
	game->img[1].data = (int *)mlx_get_data_addr(game->img[1].img_ptr,
			&game->img[1].bpp, &game->img[1].size_l, &game->img[1].endian);

    game->img[2].img_ptr = mlx_xpm_file_to_image(game->mlx, "imgpersonales/spiderman.xpm", &width, &height);
	game->img[2].data = (int *)mlx_get_data_addr(game->img[2].img_ptr,
			&game->img[2].bpp, &game->img[2].size_l, &game->img[2].endian);
            	
    game->img[3].img_ptr = mlx_xpm_file_to_image(game->mlx, "imgpersonales/exit.xpm", &width, &height);
	game->img[3].data = (int *)mlx_get_data_addr(game->img[3].img_ptr,
			&game->img[3].bpp, &game->img[3].size_l, &game->img[3].endian);
    
    game->img[4].img_ptr = mlx_xpm_file_to_image(game->mlx, "imgpersonales/dinosaurio.xpm", &width, &height);
	game->img[4].data = (int *)mlx_get_data_addr(game->img[4].img_ptr,
			&game->img[4].bpp, &game->img[4].size_l, &game->img[4].endian);

}
