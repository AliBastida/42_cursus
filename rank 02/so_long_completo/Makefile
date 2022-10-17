# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abastida <abastida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 19:32:04 by abastida          #+#    #+#              #
#    Updated: 2022/10/14 15:42:47 by abastida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
RM = rm -fr
CFLAGS = -Wall -Werror -Wextra -MMD -fsanitize=address -g3

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
	/gnl/get_next_line.c \
	/gnl/get_next_line_utils.c \
	/printf/ft_printf.c\
	/printf/src.c 

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
	/gnl/get_next_line.c \
	/gnl/get_next_line_utils.c \
	/printf/ft_printf.c\
	/printf/src.c 

OBJ = $(addprefix .,$(addsuffix .o,$(basename $(SRC))))

OBJ_BONUS = $(addprefix .,$(addsuffix .o,$(basename $(SRC_BONUS))))

DEPS = $(addprefix .,$(addsuffix .d,$(basename $(SRC))))

DEPS_BONUS = $(addprefix .,$(addsuffix .d,$(basename $(SRC_BONUS))))

HEADER = ./inc/so_long.h \
	./inc/get_next_line.h \
	./inc/libftprintf.h \


HEADER_BONUS = ./inc_bonus/so_long_bonus.h \
	./inc/get_next_line.h \
	./inc/libftprintf.h \

LIBS =  libmlx.dylib

LIBPATH = -L mlx

LDLIBS = -lmlx 

FRAMES = -framework OpenGL -framework AppKit  

INCLUDES = -I mlx 

.%.o: %.c 
	$(CC) $(CFLAGS)  $(INCLUDES) -c  $< -o $@ 
	#$< imprime lo de la derecha y $@ imprime lo de la izquierda

all: make_libs $(NAME) 

make_libs : 
	#esta es para llamar a los Makefiles de otros programas.
	$(MAKE) -C mlx 
	cp mlx/libmlx.a .

-include $(DEPS)
$(NAME): $(OBJ) $(HEADER) #aqui añadiria los .a como dependencias para que si cambia vuelva a recmopilar 
	$(CC) $(CFLAGS) $(LIBPATH) $(LDLIBS) $(FRAMES) $(OBJ) -o $(NAME)
	

-include $(DEPS_BONUS)	
bonus: $(OBJ_BONUS) $(HEADER_BONUS) make_libs

	$(CC) $(CFLAGS) $(LIBPATH) $(LDLIBS) $(FRAMES) $(OBJ_BONUS) -o $(NAME)
	

clean: 
	$(RM) $(OBJ)
	$(RM) $(DEPS)
	#$(RM) $(OBJ_BONUS)
	#$(RM) $(DEPS_BONUS)
	$(MAKE) clean -C mlx
	

fclean: clean
	$(RM) $(NAME) $(LIBS)

re: fclean
	$(MAKE)

.PHONY: make_libs all clean fclean re #aun no está funcional. No me borra los .o 

# los .o dependen de los .c y los .h
# del ejecutable son los .o y los .a 
#
# los .a es una carpeta con .o
