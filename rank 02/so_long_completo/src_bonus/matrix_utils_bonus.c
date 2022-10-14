/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:47:11 by abastida          #+#    #+#             */
/*   Updated: 2022/10/14 12:43:26 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"
/**
 * @brief en este archivo tengo todo lo relativo a la matriz
 * 
 */

int	create_matrix(t_game *game)
{
	int	i;

	i = 0;
	game->map = (char **)malloc(sizeof(char *) * (game->map_height + 1)); //creamos el eje de las h, son punteros que apuntaeran a las columnas, todavia no tiene valor-direccion asignado
	if (!game->map)
		return (0);
	while (i < game->map_height)
	{
		game->map[i] = (char *)malloc(sizeof(char) * (game->map_width + 1)); //creo la columna, y pongo la direccion que me devuelve el malloc en el slot del eje X que corresponde
		if (!game->map[i])
			return (0);
		game->map[i][game->map_width] = '\0';
		i++;
	}
	game->map[i] = NULL;
	return(1);
}

int fill_the_matrix(t_game *game)
{ 
//RELLENAR LA MATRIZ
//1. Cojo el map raw y voy poniendo los valores en la matriz
	int cont_x;
	int cont_y;
	int i;

	cont_x = 0;
	cont_y = 0;
	i = 0;
	while(cont_y < game->map_height)
	{
		cont_x = 0;
		while(cont_x < game->map_width)
		{
			game->map[cont_y][cont_x] = game->map_raw[i];
			cont_x++;
			i++;
		}
		i++;
		cont_y++;
		if(game->map_raw[i] == '\0')
			return(1);
	}
	return(0);
}

void    init_player_position(t_game *game)
{
    int x;
    int y;

    x = 0;
    y = 0;

    while (game->map[y] != NULL)
    {
        printf ("entro en el while \n");
        while ((game->map[y][x] != '\0'))
        {  
            if (game->map[y][x] == 'P')
            {
                game->player_x = x;
                game->player_y = y;
                break;
            }
            x++;
            printf ("la x antes de resetear es = %d\n", x);
        }
        x = 0;
        printf ("la x es = %d\n", x);
        y++;
        printf ("la y es = %d\n", y);
    } 
    printf ("El P esta en: %d, %d\n", game->player_y, game->player_x);
}
