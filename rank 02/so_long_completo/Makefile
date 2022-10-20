# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abastida <abastida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 19:32:04 by abastida          #+#    #+#              #
#    Updated: 2022/10/20 14:12:27 by abastida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = .bonus
CC = gcc
RM = rm -fr
CFLAGS = -Wall -Werror -Wextra -MMD

SRC = /src/so_long.c \
	/src/map_utils.c \
	/src/matrix_utils.c \
	/src/movements.c \
	/src/finding_path.c \
	/src/images.c \
	/src/checking_the_map.c \
	/src/about_characters.c \
	/src/exit.c \
	/src/print_map.c \
	/src/check_move.c \
	/src/print_move.c \
	/src/checking_map_raw.c \
	/src/get_next_line.c \
	/src/get_next_line_utils.c \


SRC_BONUS = /src_bonus/so_long_bonus.c \
	/src_bonus/map_utils_bonus.c \
	/src_bonus/matrix_utils_bonus.c \
	/src_bonus/movements_bonus.c \
	/src_bonus/finding_path_bonus.c \
	/src_bonus/images_bonus.c \
	/src_bonus/checking_the_map_bonus.c \
	/src_bonus/about_characters_bonus.c \
	/src_bonus/exit_bonus.c \
	/src_bonus/print_map_bonus.c \
	/src_bonus/check_move_bonus.c \
	/src_bonus/print_move_bonus.c \
	/src_bonus/checking_map_raw_bonus.c \
	/src_bonus/get_next_line.c \
	/src_bonus/get_next_line_utils.c \
	/src_bonus/image_square_bonus.c \
	

OBJ = $(addprefix .,$(addsuffix .o,$(notdir $(basename $(SRC)))))

OBJ_BONUS = $(addprefix .,$(addsuffix .o,$(notdir $(basename $(SRC_BONUS)))))

DEPS = $(addprefix .,$(addsuffix .d,$(notdir $(basename $(SRC)))))

DEPS_BONUS = $(addprefix .,$(addsuffix .d,$(notdir$(basename $(SRC_BONUS)))))

HEADER = inc/ 

LIBS = mlx/libmlx.a ft_printf/libftprintf.a
LIBS_B = mlx/libmlx.a ft_printf/libftprintf.a libft/libft.a

HEADER_BONUS = inc_bonus/

LIBPATH = -L mlx -L ft_printf -L libft

LDLIBS = -lmlx -lftprintf 
LDLIBS_B = -lmlx -lftprintf -lft

FRAMES = -framework OpenGL -framework AppKit  

INCLUDES = -I mlx -I $(HEADER) 
INCLUDES_BONUS = -I mlx -I $(HEADER_BONUS) -I libft

.%.o: src/%.c
	$(CC) $(CFLAGS)  $(INCLUDES) -c  $< -o $@ 
	#$< imprime lo de la derecha y $@ imprime lo de la izquierda
.%.o: src_bonus/%.c
	$(CC) $(CFLAGS)  $(INCLUDES_BONUS) -c  $< -o $@ 
	#$< imprime lo de la derecha y $@ imprime lo de la izquierda

all: make_libs $(NAME) 
		
make_libs : 
	#esta es para llamar a los Makefiles de otros programas.
	$(MAKE) -C mlx 
	$(MAKE) -C ft_printf

make_libs_B : 
	#esta es para llamar a los Makefiles de otros programas.
	$(MAKE) -C mlx 
	$(MAKE) -C ft_printf
	$(MAKE) -C libft
	

-include $(DEPS)
$(NAME): $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(LIBPATH) $(LDLIBS) $(FRAMES) $(OBJ) -o $(NAME)
	
bonus:  make_libs_B $(NAME_BONUS)

-include $(DEPS_BONUS)	
$(NAME_BONUS) : $(OBJ_BONUS) $(LIBS_B)
	$(CC) $(CFLAGS) $(LIBPATH) $(LDLIBS_B) $(FRAMES) $(OBJ_BONUS) -o $(NAME)
	touch $@
	

clean: 
	$(RM) $(OBJ)
	$(RM) $(DEPS)
	$(RM) $(OBJ_BONUS)
	$(RM) $(DEPS_BONUS)
	$(MAKE) clean -C mlx
	$(MAKE) clean -C ft_printf
	$(MAKE) clean -C libft
	

fclean:
	$(MAKE) clean
	$(RM) $(NAME) 
	$(MAKE) clean -C mlx
	$(MAKE) fclean -C ft_printf
	$(MAKE) fclean -C libft
	

re: 
	$(MAKE)	fclean
	$(MAKE)
	

.PHONY: make_libs  make_libs_B all clean fclean re bonus #aun no está funcional. No me borra los .o 

# los .o dependen de los .c y los .h
# del ejecutable son los .o y los .a 
#
# los .a es una carpeta con .o
