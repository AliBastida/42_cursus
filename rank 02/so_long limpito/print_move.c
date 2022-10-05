/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:31:30 by abastida          #+#    #+#             */
/*   Updated: 2022/10/04 17:59:05 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    print_left(t_game *game)
{
     //Dibuja una casilla de cesped donde estaba
     mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0].img_ptr, 50 * (game->player_x + 1), 50 * (game->player_y));
      //Dibuja el personaje en su posicion actual
     mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[5].img_ptr, 50 * (game->player_x), 50 * (game->player_y));
}

void    print_right(t_game *game)
{
     //Dibuja una casilla de cesped donde estaba
     mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0].img_ptr, 50 * (game->player_x - 1), 50 * (game->player_y));
      //Dibuja el personaje en su posicion actual
     mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[6].img_ptr, 50 * (game->player_x), 50 * (game->player_y));
}

void    print_up(t_game *game)
{
     //Dibuja una casilla de cesped donde estaba
     mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0].img_ptr, 50 * (game->player_x), 50 * (game->player_y + 1));
      //Dibuja el personaje en su posicion actual
     mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[4].img_ptr, 50 * (game->player_x), 50 * (game->player_y));
}

void    print_down(t_game *game)
{
     printf("Llamo a PRINT DOWN!!!!\n");
     //Dibuja una casilla de cesped donde estaba
     mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0].img_ptr, 50 * (game->player_x), 50 * (game->player_y - 1));
      //Dibuja el personaje en su posicion actual
     mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[7].img_ptr, 50 * (game->player_x), 50 * (game->player_y));
}
