/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:34:58 by abastida          #+#    #+#             */
/*   Updated: 2022/10/18 11:50:14 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	exit_error_map_raw(t_game *game)
{
	free (game->map_raw);
	exit (1);
}

int	exit_error_matrix(t_game *game)
{
	int	y;

	free(game->map_raw);
	y = 0;
	while (game->map[y])
	{
		free(game->map[y]);
		y++;
	}
	free (game->map);
	return (0);
}
