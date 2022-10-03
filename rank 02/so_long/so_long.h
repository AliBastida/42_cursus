/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:45:12 by abastida          #+#    #+#             */
/*   Updated: 2022/09/23 16:33:56 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "mlx.h"

# define IS_TRUE 1
# define IS_FALSE 0
# define ERROR_NO_PATH "Error: There is no valid path\n"

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	t_img	*img;
	char 	*map_raw; //Aqui va el mapa en sucio
	char 	**map;
	int 	map_height;
	int 	map_width;
	int 	player_x;
	int		player_y;
	char	new_position;
	int 	there_is_c;
	int		is_path;
	int		is_exit;
}	t_game;

// UTILS
int		ft_strlen(char *str);
char	*ft_strjoin(const char *s1, const char *s2);
char	*get_next_line(int fd);
char	*extract_line(char *storage);
char	*save_storage(char *storage);


// MOVIMIENTOS
int 	ft_movements(int keycode, t_game *game);
char    ft_get_direction(int keycode);
void	init_player_position(t_game *game);

// MAPA
int		create_matrix(t_game *game);
int		open_map(char *filename);
int		take_the_map(char *filename, t_game *game);

int		the_map_is_rectangular(t_game *game);
int 	fill_the_matrix(t_game *game);

//IMAGENES
void    upload_img(t_game *game);


// CHECKER
int		check_num_params_are_valid(int argc);
int		check_filename_is_valid(char *filename);
int		check_params_are_valids(int argc, char **argv);
int		check_map_have_minimal_size(t_game *game);
int		map_is_surrounded_by_one(t_game *game);
int		find_path(t_game *game, int y, int x);
int		characters_are_valid(t_game *game);
int		characters_needed(t_game *game);

#endif
