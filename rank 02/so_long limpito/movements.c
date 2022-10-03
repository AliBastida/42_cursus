/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:51 by abastida          #+#    #+#             */
/*   Updated: 2022/10/03 15:50:25 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int ft_movements(int keycode, t_game *game)
{
    game->new_position = keycode;
    if (game->new_position ==  W)
        check_up(game);
        //printf("ME MUEVO PARA ARRIBA\n");// en lugar del printf, llamo a la función check move y print move
    if (game->new_position ==  S)
        check_down(game);//printf("ME MUEVO PARA ABAJO\n");
    if (game->new_position == A)
        check_left(game);
        //printf("ME MUEVO PARA LA IZQUIERDA\n");
    if (game->new_position == D)
        check_right(game);        //printf("ME MUEVO PARA LA DERECHA\n");
    if (game->new_position == ESC)
    {
           printf("ADIOS\n");
           mlx_destroy(game->mlx);
           exit (0);
    }
    return (0);
}
