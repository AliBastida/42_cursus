/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:45:12 by abastida          #+#    #+#             */
/*   Updated: 2022/11/11 13:38:03 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "mlx.h"
# include "get_next_line.h"
# include "libftprintf.h"

# define IS_TRUE 1
# define IS_FALSE 0
# define ERROR_NO_PATH "Error: There is no valid path\n"
# define KEY_EXIT 	17
# define ESC		53
# define W			13
# define A			0
# define S			1
# define D			2
# define GRASS 		"img/xpm/suelo.xpm"
# define WALL  		"img/xpm/wall.xpm"
# define FRONT_P 	"img/xpm/front.xpm"
# define EXIT		"img/xpm/exit.xpm"
# define BACK_P		"img/xpm/back.xpm"
# define LEFT_P		"img/xpm/left.xpm"
# define RIGHT_P	"img/xpm/right.xpm"
# define COLL		"img/xpm/coll.xpm"
# define BLACK_SQUARE "img/xpm/blacksquare.xpm"

typedef struct s_img
{
	void	*img_ptr;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	t_img	*img;
	char	*map_raw;
	char	**map;
	int		map_height;
	int		map_width;
	int		player_x;
	int		player_y;
	int		new_position;
	int		there_is_c;
	int		num_collectives;
	int		is_path;
	int		is_exit;
	int		n_moves;
	int		height;
	int		width;
	int		there_is_p;
	int		there_is_e;
}	t_game;

//about_characters
int		characters_are_valid(t_game *game);
int		characters_needed(t_game *game);

//check_move
int		check_is_exit(t_game *game);
int		check_left(t_game *game);
int		check_right(t_game *game);
int		check_up(t_game *game);
int		check_down(t_game *game);

//checking_map_raw
int		check_the_map_raw_is_valid(t_game *game);
int		map_is_surrounded_by_one(t_game *game);

//checking the map
int		check_num_params_are_valid(int argc);
int		check_filename_is_valid(char *filename);
int		checking_the_map(int fd, t_game *game);
int		take_the_map(char *filename, t_game *game);
int		check_params_are_valids(int argc, char **argv);

//exit
void	exit_error_map_raw(t_game *game);
int		exit_error_matrix(t_game *game);
int		close_window(t_game *game);
int		free_and_exit(t_game *game);
void	ft_exit(int n);

// finding path
int		find_path(t_game *game, int y, int x);

//get next line utils
int		ft_strlen(char *str);
char	*ft_strchr( char *s, int c);
void	ft_strjoin_fill_new_string(char *new, char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);

//get next line
char	*filling_static_storage(int fd, char *storage);
char	*extract_line(char *storage);
char	*save_storage(char *storage);
char	*get_next_line(int fd);

//images
void	upload_img(t_game *game);

//map_utils
int		open_map(char *filename);
int		parse_the_map(int fd, t_game *game);
int		check_map_have_minimal_size(t_game *game);
int		the_map_is_rectangular(t_game *game);

//matrix_utils
int		create_matrix(t_game *game);
int		fill_the_matrix(t_game *game);
void	init_player_position(t_game *game);

//movements
int		ft_movements_continue(int keycode, t_game *game);
int		move_if_escape(int keycode, t_game *game);
int		ft_movements(int keycode, t_game *game);

//print_map
void	print_map(t_game *game);

//print_move
void	print_left(t_game *game);
void	print_right(t_game *game);
void	print_up(t_game *game);
void	print_down(t_game *game);

//so_long
void	struct_init(t_game *game);

#endif
