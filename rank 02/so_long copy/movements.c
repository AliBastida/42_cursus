/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:51 by abastida          #+#    #+#             */
/*   Updated: 2022/09/20 12:27:43 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    ft_get_direction(int keycode)
{
    if (keycode == 13)
        return ('W');
    else if (keycode == 0)
        return ('A');
    else if (keycode == 1)
        return ('S');
    else if (keycode == 2)
        return ('D');
    else if (keycode == 53)
        return (-1);
    return ('0');
}

int ft_movements(int keycode, t_game *game)
{
    game->new_position = ft_get_direction(keycode);
    if (game->new_position ==  'W')
        printf("ME MUEVO PARA ARRIBA\n");
    if (game->new_position ==  'S')
        printf("ME MUEVO PARA ABAJO\n");
    if (game->new_position == 'A')
        printf("ME MUEVO PARA LA IZQUIERDA\n");
    if (game->new_position == 'D')
        printf("ME MUEVO PARA LA DERECHA\n");
    if (game->new_position == -1)
    {
           printf("ADIOS\n");
           exit (0);
    }
    return (0);
}
