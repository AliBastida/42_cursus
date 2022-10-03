/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:12:21 by abastida          #+#    #+#             */
/*   Updated: 2022/09/23 16:42:45 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief funcion para encontrar el camino
 * 
 * @param game 
 * @param x 
 * @param y 
 * @return int 
 */

int find_path(t_game *game, int y, int x)
{
    if ((game->there_is_c == 0) && (game->is_exit == 1))
        return (IS_TRUE);
    if (game->map[y][x] == '1')
        return (IS_FALSE);
    if (game->map[y][x] == 'C') //&& game->there_is_c > 0)
        //game->there_is_c--;
    if (game->map[y][x] == 'E')
            game->is_exit = 1;

   game->map[y][x] = '1';
    find_path(game, y, x+1);
    find_path(game, y, x-1);
    find_path(game, y+1, x);
    find_path(game, y-1, x);
    if ((game->is_exit == 1))
    printf("el camino seguido: %d %d\n", y, x);
    if (game->is_exit == 1)
        return (IS_TRUE);
    write(2, ERROR_NO_PATH, 30);
    return (IS_FALSE);
    
} 