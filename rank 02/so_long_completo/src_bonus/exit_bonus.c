/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:34:58 by abastida          #+#    #+#             */
/*   Updated: 2022/10/21 14:17:32 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	ft_printf ("There is an error creating the game\n");
	free (game->map);
	exit (1);
}

int	free_and_exit(t_game *game)
{
	int	i;

	i = 0;
	while (game->img[i++].img_ptr)
		free(game->img);
	exit (1);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit (EXIT_SUCCESS);
}

void ft_exit (int n)
{
	if (n == 1)
	{
		ft_printf("Error: File cannot be opened\n");
		exit (0);
	}

}