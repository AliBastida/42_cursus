/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:48:19 by abastida          #+#    #+#             */
/*   Updated: 2022/10/03 10:32:52 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief esta es la funcion principal de mi programa.
 * 1.Chequeo parametros.(que haya al menos, 2 params. Que el segundo sea un .ber)
 * 2.Valido parametros.
 * 3. Abro el mapa.(si no se puede abrir, lanzo mensaje de error y salgo del programa. Si se puede abrir, lo leo con get next line y lo guardo como array en mapraw para hacer los chequeos ahí.)
 * 4. Chequeo que esten los caracteres necesarios/  
 * 5. Está rodeado de paredes (1)
 * 6. Si el mapa está bien, lo meto en una matriz
 * 7. Printr el mapa por pantalla.
 * 
 * incializo todos los valores de la estructura para no tener problemas en el futuro. 
 */

void	struct_init(t_game *game)
{
	game->img = NULL;
	game->map_raw = NULL; //Aqui va el mapa en sucio
	game->map = NULL;
	game->map_copy = NULL;
	game->map_height = 0;
	game->map_width = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->new_position = 0;
	game->there_is_c = 0;
	game->is_path = 0;
	game->is_exit = 0;
}

int main(int argc, char **argv)
{
    t_game game;
	//void *img;
	//void *img2;
	//void *img3;
	//int img_width;
	//int img_height;

	struct_init (&game);
    if(!check_params_are_valids(argc, argv))
        return(0);
    if(!take_the_map(argv[1], &(game)))
        return(0);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.map_width * 50, game.map_height * 50, (char*)"so_long");
	printf("Esto mide\n");
	printf ("%d game->map_width\n", game.map_width);
	printf ("%d game->map_height\n" ,game.map_height);
	
	upload_img(&game);
	print_map(&game);
	/*img = mlx_xpm_file_to_image(game.mlx, GRASS, &img_width, &img_height);
	mlx_put_image_to_window(game.mlx, game.mlx_win, img, 0, 0);
	img2 = mlx_xpm_file_to_image(game.mlx, WALL, &img_width, &img_height);
	mlx_put_image_to_window(game.mlx, game.mlx_win, img, 31, 0);
	img3 = mlx_xpm_file_to_image(game.mlx, FRONT_P, &img_width, &img_height);
	mlx_put_image_to_window(game.mlx, game.mlx_win, img, 62, 0);*/
	
	mlx_hook(game.mlx_win, 2, 0, ft_movements, &game);
	mlx_loop(game.mlx);
	
}