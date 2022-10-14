/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:12:22 by abastida          #+#    #+#             */
/*   Updated: 2022/10/14 15:32:19 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void    print_left_skel(t_game *game)
{
     mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[12].img_ptr, (game->map_width * 50) - 150, (game->map_height * 50) + 25);
     mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0].img_ptr, 50 * (game->player_x + 1), 50 * (game->player_y));
      //Dibuja el personaje en su posicion actual
     mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[5].img_ptr, 50 * (game->player_x), 50 * (game->player_y));
    
}

void    print_right_skel(t_game *game)
{
     //Dibuja una casilla de cesped donde estaba
     mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0].img_ptr, 50 * (game->player_x - 1), 50 * (game->player_y));
      //Dibuja el personaje en su posicion actual
     mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[6].img_ptr, 50 * (game->player_x), 50 * (game->player_y));
}
    

void    print_up_skel(t_game *game)
{
     //Dibuja una casilla de cesped donde estaba
     mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[12].img_ptr, (game->map_width * 50) - 150, (game->map_height * 50) + 25);
     mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0].img_ptr, 50 * (game->player_x), 50 * (game->player_y + 1));
      //Dibuja el personaje en su posicion actual
     mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[4].img_ptr, 50 * (game->player_x), 50 * (game->player_y));
     
}

void    print_down_skel(t_game *game)
{
     mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[12].img_ptr, (game->map_width * 50) - 150, (game->map_height * 50) + 25);
     //Dibuja una casilla de cesped donde estaba
     mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0].img_ptr, 50 * (game->player_x), 50 * (game->player_y - 1));
      //Dibuja el personaje en su posicion actual
     mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[7].img_ptr, 50 * (game->player_x), 50 * (game->player_y));

}