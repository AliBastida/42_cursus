/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:51 by abastida          #+#    #+#             */
/*   Updated: 2022/10/13 13:38:35 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_movements(int keycode, t_game *game)
{
    game->new_position = keycode;

    if (game->new_position ==  W)
    {
        if(check_up(game))
        {
            game->n_moves++;
            print_up(game);
        }
    }

    if (game->new_position ==  S)
    {
        if(check_down(game)) //printf("ME MUEVO PARA ABAJO\n");*/
            {
                game->n_moves++;
                print_down(game);
            }
    }
    if (game->new_position == A)
    {
        if(check_left(game))
        {
            game->n_moves++;
            print_left(game);
        }
    }
    if (game->new_position == D)
    {
        if(check_right(game))
        {
            game->n_moves++;
            print_right(game);
        }
    }

    if (game->new_position == ESC)
    {
        printf("ADIOS\n");
        mlx_destroy(game->mlx);
        exit (0);
    }
    ft_printf("Number of moves: %d\n", game->n_moves);
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[12].img_ptr, (game->map_width * 50) - 150, (game->map_height * 50));
    mlx_string_put(game->mlx, game->mlx_win, (game->map_width * 50) - 150, (game->map_height * 50) + 25, 66000000, ft_itoa(game->n_moves));
    //mlx_string_put(game->mlx, game->mlx_win, 0, 0, 0xFFFFFFFF, ft_itoa(game->n_moves));
    check_is_exit(game);
    return (0);
}