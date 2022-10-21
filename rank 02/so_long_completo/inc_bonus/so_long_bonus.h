/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:45:12 by abastida          #+#    #+#             */
/*   Updated: 2022/10/21 14:17:05 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "libftprintf.h"
# include "get_next_line.h"
# include "mlx.h"

# define IS_TRUE 1
# define IS_FALSE 0
# define ERROR_NO_PATH "Error: There is no valid path\n"
# define ESC		53
# define KEY_EXIT 	17
# define W			13
# define A			0
# define S			1
# define D			2
# define GRASS 			"img/xpm/grass.xpm"
# define WALL  			"img/xpm/wall.xpm"
# define FRONT_P 		"img/xpm/frontprincess.xpm"
# define EXIT			"img/xpm/exit.xpm"
# define BACK_P			"img/xpm/backprincess.xpm"
# define LEFT_P			"img/xpm/leftprincess.xpm"
# define RIGHT_P		"img/xpm/rightprincess.xpm"
# define COLL			"img/xpm/collectible.xpm"
# define BLACK_SQUARE	"img/xpm/blacksquare.xpm"

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	t_img	*img;
	char	*map_raw;
	char	**map;
	char	**map_copy;
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

//chec_move_bonus
int		check_is_exit(t_game *game);
int		check_left(t_game *game);
int		check_right(t_game *game);
int		check_up(t_game *game);
int		check_down(t_game *game);

//checking_the_map_raw
int		check_the_map_raw_is_valid(t_game *game);
int		map_is_surrounded_by_one(t_game *game);

//checking_the_map
int		check_num_params_are_valid(int argc);
int		check_filename_is_valid(char *filename);
int		checking_the_map(int fd, t_game *game);
int		take_the_map(char *filename, t_game *game);
int		check_params_are_valid(int argc, char **argv);

//exit
void	exit_error_map_raw(t_game *game);
int		exit_error_matrix(t_game *game);
int		free_and_exit(t_game *game);
int		close_window(t_game *game);
void	ft_exit(int n);

//finding_path
int		find_path(t_game *game, int y, int x);

//get_next_line
char	*filling_staatic_storage(int fd, char *storage);
char	*extract_line(char *storage);
char	*save_storage(char *storage);
char	*get_next_line(int fd);

//get_next_line_utils
int		ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*extract_line(char *storage);
char	*ft_strjoin(const char *s1, const char *s2);

//image_square
void	upload_black_square(t_game *game, int height, int width);

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
int		ft_movements(int keycode, t_game *game);
int		ft_movements_continue(int keycode, t_game *game);
int		move_if_escape(int keycode, t_game *game);

//print_map
void	print_map(t_game *game);

//print_move_bonus
void	upload_img(t_game *game);
void	print_left(t_game *game);
void	print_right(t_game *game);
void	print_up(t_game *game);
void	print_down(t_game *game);

#endif
