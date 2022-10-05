# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abastida <abastida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 19:32:04 by abastida          #+#    #+#              #
#    Updated: 2022/10/05 15:38:19 by abastida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
RM = rm -fr
CFLAGS = -Wall -Werror -Wextra -MMD -fsanitize=address -g3

SRC = src.c so_long.c map_utils.c matrix_utils.c movements.c finding_path.c images.c checking_the_map.c about_characters.c get_next_line .c get_next_line_utils.c exit.c print_map.c check_move.c print_move.c ft_printf.c

OBJ = $(addprefix .,$(addsuffix .o,$(basename $(SRC))))

DEPS = $(addprefix .,$(addsuffix .d,$(basename $(SRC))))

HEADER = so_long.h get_next_line.h libft.h libftprintf.h

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

-include $(DEPS)
$(NAME): $(OBJ) $(HEADER) #aqui añadiria los .a como dependencias para que si cambia vuelva a recmopilar 
	$(CC) $(CFLAGS) $(LIBPATH) $(LDLIBS) $(FRAMES) $(OBJ) -o $(NAME)
	#cp mlx/libmlx.a .

clean: 
	$(RM) $(OBJ) 
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
