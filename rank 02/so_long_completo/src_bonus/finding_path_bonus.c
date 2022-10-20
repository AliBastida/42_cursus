/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_path_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:12:21 by abastida          #+#    #+#             */
/*   Updated: 2022/10/20 14:25:59 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	find_path(t_game *game, int y, int x)
{
	if ((game->is_exit == 1) || (game->map[y][x] == 'V'))
		return (IS_TRUE);
	if (game->map[y][x] == '1')
		return (IS_FALSE);
	if (game->map[y][x] == 'C' && game->there_is_c > 0)
		game->there_is_c--;
	if (game->map[y][x] == 'E')
		game->is_exit = 1;
	game->map[y][x] = 'V';
	find_path(game, y, x + 1);
	find_path(game, y, x - 1);
	find_path(game, y + 1, x);
	find_path(game, y - 1, x);
	if (game->is_exit == 1)
		return (IS_TRUE);
	return (IS_FALSE);
}
