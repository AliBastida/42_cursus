/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:45:12 by abastida          #+#    #+#             */
/*   Updated: 2022/10/19 18:03:29 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <unistd.h>
# include <stdio.h>
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

// UTILS
int		ft_strlen(char *str);
char	*ft_strjoin(const char *s1, const char *s2);
char	*get_next_line(int fd);
char	*extract_line(char *storage);
char	*save_storage(char *storage);
void	struct_init(t_game *game);
int		ft_format(va_list arg, const char type);
int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
size_t	ft_len(long n);
char	*ft_itoa(int n);
int		ft_putnbr(int n);

//FREEDOM
void	exit_error_map_raw(t_game *game);
int		exit_error_matrix(t_game *game);

// MOVIMIENTOS
int		ft_movements(int keycode, t_game *game);
char	ft_get_direction(int keycode);
void	init_player_position(t_game *game);
int		check_left(t_game *game);
int		check_right(t_game *game);
int		check_up(t_game *game);
int		check_down(t_game *game);
int		check_is_exit(t_game *game);

// MAPA
int		create_matrix(t_game *game);
int		open_map(char *filename);
int		take_the_map(char *filename, t_game *game);
int		the_map_is_rectangular(t_game *game);
int		fill_the_matrix(t_game *game);
int		parse_the_map(int fd, t_game *game);
void	ft_print_map(t_game *game);
void	print_map(t_game *game);

// IMAGENES
void	upload_img(t_game *game);
void	print_left(t_game *game);
void	print_right(t_game *game);
void	print_up(t_game *game);
void	print_down(t_game *game);

// CHECKER
int		check_num_params_are_valid(int argc);
int		check_filename_is_valid(char *filename);
int		check_params_are_valids(int argc, char **argv);
int		check_map_have_minimal_size(t_game *game);
int		the_map_is_surrounded_by_one(t_game *game);
int		find_path(t_game *game, int y, int x);
int		characters_needed(t_game *game);
int		characters_are_valid(t_game *game);
int		check_the_map_raw_is_valid(t_game *game);
int		checking_the_map(int fd, t_game *game);

#endif
