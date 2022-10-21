/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:48:19 by abastida          #+#    #+#             */
/*   Updated: 2022/10/21 13:52:15 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	struct_init(t_game *game)
{
	game->img = NULL;
	game->map_raw = NULL;
	game->map = NULL;
	game->map_height = 0;
	game->map_width = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->new_position = 0;
	game->there_is_c = 0;
	game->is_path = 0;
	game->is_exit = 0;
	game->n_moves = 0;
	game->num_collectives = game->there_is_c;
}

int	main(int argc, char **argv)
{
	t_game	game;

	struct_init (&game);
	if (!check_params_are_valids(argc, argv))
		return (0);
	if (!take_the_map(argv[1], &(game)))
		return (0);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.map_width * 50,
			(game.map_height * 50), (char*)"so_long");
	upload_img(&game);
	print_map(&game);
	mlx_hook(game.mlx_win, 2, 0, ft_movements, &game);
	mlx_hook(game.mlx_win, KEY_EXIT, 0, close_window, &game);
	mlx_loop(game.mlx);
}
