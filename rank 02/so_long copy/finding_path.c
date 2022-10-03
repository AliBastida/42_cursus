/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:12:21 by abastida          #+#    #+#             */
/*   Updated: 2022/09/22 14:48:41 by abastida         ###   ########.fr       */
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

void find_path(t_game *game, int y, int x)
{
    int encuentro_c; 

    encuentro_c = 0;
    if (game->map[y][x] == '1')
        return ;
    if (game->map[y][x] == 'C')
        encuentro_c++;
    if ((game->map[y][x] == 'E') && (encuentro_c == game->there_is_c))
        return ;
    game->map[y][x] = '1';
    find_path(game, y, x+1);
    printf("finding path 1");
    find_path(game, y, x-1);
    find_path(game, y+1, x);
    find_path(game, y-1, x);
} 