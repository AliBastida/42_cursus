/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:47:11 by abastida          #+#    #+#             */
/*   Updated: 2022/10/19 15:25:28 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_print_map(t_game *game)
{
    for (int y = 0; y < game->map_height; y++)
    {
        for (int x = 0; x < game->map_width; x++)
        {
            printf("%c", game->map[y][x]);
        }
        printf("\n");
    }
}

int	create_matrix(t_game *game)
{
	int	i;

	i = 0;
	game->map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (0);
	while (i < game->map_height)
	{
		game->map[i] = (char *)malloc(sizeof(char) * (game->map_width + 1));
		if (!game->map[i])
			return (0);
		game->map[i][game->map_width] = '\0';
		i++;
	}
	game->map[i] = NULL;
	return (1);
}


int	fill_the_matrix(t_game *game)
{
	int	cont_x;
	int	cont_y;
	int	i;

	cont_x = 0;
	cont_y = 0;
	i = 0;
	
	while (cont_y < game->map_height)
	{
		cont_x = 0;
		while (cont_x < game->map_width)
		{
			game->map[cont_y][cont_x] = game->map_raw[i];
			cont_x++;
			i++;
		}
		cont_y++;
		while(game->map_raw[i] == '\n')
			i++;
		if (game->map_raw[i] == '\0')
			return (1);
	}
	ft_print_map(game);
	return (0);
}

void	init_player_position(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y] != NULL)
	{
		while ((game->map[y][x] != '\0'))
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				break ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}
