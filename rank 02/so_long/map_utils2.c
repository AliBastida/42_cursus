/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:24:04 by abastida          #+#    #+#             */
/*   Updated: 2022/09/22 15:59:51 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Return 0: I can't expand  from this square
//Return 1: I expanded
//Return 2: I found the exit
/*int try_to_expand(t_game *game, int x, int y)
{
    int expanded;

    expanded = 0;
    if(y > 0)
    {
        if(game->map[y - 1][x] == 'E')
            return (2);
        if(game->map[y - 1][x] == '0' || game->map[y - 1][x] == 'C')
        {
             expanded = 1;
             game->map[y - 1][x] = 'Z';
        }
    }
    
    if(y < game->map_height - 1)
    {
        if(game->map[y + 1][x] == 'E')
            return (2);
        if(game->map[y + 1][x] == '0' || game->map[y + 1][x] == 'C')
        {
             expanded = 1;
             game->map[y + 1][x] = 'Z';
        }
    }

    if(x < game->map_width - 1)
    {
        if(game->map[y][x + 1] == 'E')
            return (2);
        if(game->map[y][x + 1] == '0' || game->map[y][x + 1] == 'C')
        {
             expanded = 1;
             game->map[y][x + 1] = 'Z';
        }
    }

    if(x > 0)
    {
        if(game->map[y][x - 1] == 'E')
            return (2);
        if(game->map[y][x - 1] == '0' || game->map[y][x - 1] == 'C')
        {
             expanded = 1;
             game->map[y][x - 1] = 'Z';
        }
    }
    return(expanded);
}


int search_there_is_path_to_exit(t_game *game)
{
    int x;
    int y;
    int expanded_this_turn;
    int tmp_expansion;
    
    x = 0;
    y = 0;
    expanded_this_turn = 1;
    //Empiezo exapandiendo la posicion inicial del player
    tmp_expansion = try_to_expand(game, game->player_x, game->player_y);
    printf ("tmp_expansion es: %d\n", tmp_expansion);
    if(tmp_expansion == 0)
        return(0);
    else if(tmp_expansion == 2)
        return(1);

    //Si he podido expandir el player y no he encontrado aun el exit

    //mientras me pueda expandir
    while(expanded_this_turn == 1)
    {
        printf("Vuelta en el while principal\n");
        expanded_this_turn = 0;
        //vamos a recorrer toda la matriz en busca de Z
        while((y < game->map_height) && (game->map_height))
        {
            while((x < game->map_width) && (game->map_width != '\0'))
            {
                //Si en este reccorrido aqui hay una Z intento expandirla
                if(game->map[y][x] == 'Z')
                {
                    printf("Entro aqui %d %d\n", y, x);
                    tmp_expansion = try_to_expand(game, x, y);
                    printf("Entro aqui %d %d\n", y, x);
                    //como he intentado expandirla miro que me a devuelto la funcion de expand
                    if(tmp_expansion == 2)  // si me ha devuelto 2 ees que habia un exit
                        {
                            printf("Entro aqui %d %d\n", y, x);
                            return (1);
                            }
                    else if (tmp_expansion == 1) //Si me ha devuelto un 1 es que se ha podido expandir , lo guardamos en expanded_this_turn, porque el valor de tmp, se machacara en la proxima casilla a verificar
                        expanded_this_turn = 1;
                }
                x++;
                printf("muevo x\n");
            }
            y++;
            printf("muevo y\n");

            x = 0;
        }

        y = 0;
        if(expanded_this_turn == 0)
        {
            write(2, "There is not path to the exit\n", 30);
            return(0);
        }
           
    }

    return(0);
}
*/
//tiene que buscar la P en el mapa, y poner en game->player_x y game_player_y los valores que corresponden
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
