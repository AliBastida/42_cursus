/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:04:02 by abastida          #+#    #+#             */
/*   Updated: 2022/10/03 11:38:31 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief 
 * true: return 1 si se puede mover.
 * false: return 0 no se puede mover.
 * 
 * Una función que chequee si puede moverse en las 4 direcciones. 
 * Despues, hacer otra función para que segun el movimiento, cambie la imagen (donde está el P ahora, que ponga cesped, y donde avanza, que ponga al P). Si es coleccionable, tiene que cogerlo y contarlo y quitar el C y poner 0.  
 * 
 */

int check_left (t_game *game)
{
    if (game->map[game->player_y][game->player_x - 1] == '0')
        {
            printf("nueva posición: game->player_x %d y game->player_x-1 %d \n", game->player_x, game->player_x-1);
            game->map[game->player_y][game->player_x] = '0';
            game->map[game->player_y][game->player_x--] = 'P';
            printf("nueva posición: game->player_x %d y game->player_x-1 %d \n", game->player_x, game->player_x-1);
            return (1);
        }
        return (0);
}
