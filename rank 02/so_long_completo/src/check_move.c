/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:04:02 by abastida          #+#    #+#             */
/*   Updated: 2022/10/14 11:58:16 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * @brief 
 * true: return 1 si se puede mover.
 * false: return 0 no se puede mover.
 * 
 * Una función que chequee si puede moverse en las 4 direcciones. 
 * Despues, hacer otra función para que segun el movimiento, cambie la imagen (donde está el P ahora, que ponga cesped, y donde avanza, que ponga al P). Si es coleccionable, tiene que cogerlo y contarlo y quitar el C y poner 0.  
 * 
 */

int check_is_exit(t_game *game)
{
    if ((game->num_collectives == 0) && ((game->map[game->player_y][game->player_x-1] == 'E') ||
        (game->map[game->player_y][game->player_x+1] == 'E')||
        (game->map[game->player_y-1][game->player_x] == 'E')||
        (game->map[game->player_y+1][game->player_x] == 'E')))
        {
		    write (1, "\e[1;35mYOU HAVE WIN \e[0m\n", 25);
            exit(0);
        }
    return (1);
}

int check_left (t_game *game)
{
    printf("pressed left\n");
    if (game->new_position == A)
    {
        if ((game->map[game->player_y][game->player_x-1] != '1') && (game->map[game->player_y][game->player_x-1] != 'E'))
        {
            if(game->map[game->player_y][game->player_x-1] == 'C')
                game->num_collectives--;
            game->player_x--;
            game->map[game->player_y][game->player_x] = 'P';
            game->map[game->player_y][game->player_x + 1] = '0';
            return (1);
        }
    }
    return (0);
}

int check_right (t_game *game)
{
        printf("pressed right\n");
    if (game->new_position == D)
    {
        if ((game->map[game->player_y][game->player_x+1] != '1') && (game->map[game->player_y][game->player_x+1] != 'E'))
        {
            if(game->map[game->player_y][game->player_x+1] == 'C')
                game->num_collectives--;
            game->player_x++;
            game->map[game->player_y][game->player_x] = 'P';
            game->map[game->player_y][game->player_x - 1] = '0';
            return (1);
        }
    }
    return (0);
}

int check_up (t_game *game)
{
    printf("pressed up\n");
    if (game->new_position == W)
    {
        if ((game->map[game->player_y - 1][game->player_x] != '1') && (game->map[game->player_y - 1][game->player_x] != 'E'))
        {
            if(game->map[game->player_y - 1][game->player_x] == 'C')
                game->num_collectives--;
            game->player_y--;
            game->map[game->player_y][game->player_x] = 'P';
            game->map[game->player_y + 1][game->player_x] = '0';
            return (1);
        }
    }
    return (0);
}

int check_down (t_game *game)
{
    printf("Posicion del player y: %d, x: %d\n", game->player_y , game->player_x);
    if (game->new_position == S)
    {
        if ((game->map[game->player_y+1][game->player_x] != '1') && (game->map[game->player_y+1][game->player_x] != 'E'))//Si me puedo mover porque lo que hay es un 0
        {
            if(game->map[game->player_y+1][game->player_x] == 'C')
                game->num_collectives--;
            game->player_y++;  //Ahora me muevo y actualizo la posicion y del jugador
            game->map[game->player_y][game->player_x] = 'P'; //Actualizo la informacion del mapa
            game->map[game->player_y - 1][game->player_x] = '0'; //Actualizo la informacion del mapa
            return (1);
        }
    }
    return (0);
}