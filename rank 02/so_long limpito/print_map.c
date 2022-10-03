/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:06:11 by abastida          #+#    #+#             */
/*   Updated: 2022/10/03 10:34:44 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void    print_map(t_game *game)
{
    int height;
    int width;

    height = 0;
    
    while (game->map[height])
    {
        width = 0;
        while (game->map[height][width]) 
        {
            if (game->map[height][width] == '1')
                mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[1].img_ptr, width*50, height*50);
            else if (game->map[height][width] == '0')
                mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0].img_ptr, width*50, height*50);
            else if (game->map[height][width] == 'E')
                mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[3].img_ptr, width*50, height*50);
            else if (game->map[height][width] == 'C')
                mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[2].img_ptr, width*50, height*50);
            else if (game->map[height][width] == 'P')
                mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[7].img_ptr, width*50, height*50);
            width++;
        }
        height++;
    }
}