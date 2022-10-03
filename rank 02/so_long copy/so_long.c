/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:54:11 by abastida          #+#    #+#             */
/*   Updated: 2022/09/22 14:47:52 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Funcion principal de mi programa
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main(int argc, char **argv)
{
	t_game game;

	
	//PAso 1: Chequear numero de parametros
	//Paso 2: Validar el parametro
	if(!check_params_are_valids(argc, argv))
		return(0);
	if(!take_the_map(argv[1], &game))
		return(0);
	//PAso 3: Abrir el mapa
	/* fd = open("map.ber", O_RDONLY);
	if (fd == -1)
	{
		write (2, "Error: File cannot be opened\n", 30);
		exit(0);
	}
	else
	{
		line = get_next_line(fd);
		game.map_raw = line;
		printf ("Esta es la primera línea |%s|\n", game.map_raw);
	} */

	// si no se puede abrir, lanzo error y salgo del programa
	// si se puede abrir lo leo entero con get next line, y lo voy guardando en game->map_raw
//	if (!try_parse_map(argv[1], &game))
//		return(0);

	//PAso 4: Poner el contenido del mapa dentro de un array (game->map_raw)
	//Paso 5: Valido el mapa , como por ejemplo, todo carrecteres validos
	//Hay un C, un P un E
	//todo esta rodeado de paredes
	//que la extension sea .ber.
	//Paso 6: Si el mapa esta bien, hago una matriz y lo pongo en (game->map)
	//PAso 7: Printar el mapa en la pantalla
	
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.map_width * 32, game.map_height * 32, "so_long");
	
	upload_img(&game);


	//Una vez tengo el tampon  lo uso tantas veces como quiera
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.img[0].img_ptr, 500, 500);
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.img[0].img_ptr, (200), (200));

	mlx_put_image_to_window(game.mlx, game.mlx_win, game.img[1].img_ptr, (100), (100));
	mlx_hook(game.mlx_win, 2, 0, ft_movements, &game);
	mlx_loop(game.mlx);

}

