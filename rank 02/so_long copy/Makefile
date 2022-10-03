# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abastida <abastida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 19:32:04 by abastida          #+#    #+#              #
#    Updated: 2022/09/22 14:51:03 by abastida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
RM = rm -fr
CFLAGS = -Wall -Werror -Wextra -MMD

SRC = so_long.c initial_checks.c map_utils.c get_next_line_utils.c get_next_line.c movements.c finding_path.c images.c map_utils2.c

OBJ = $(addprefix .,$(addsuffix .o,$(basename $(SRC))))
DEPS = $(addprefix .,$(addsuffix .d,$(basename $(SRC))))
HEADER = so_long.h get_next_line.h libft.h


LIBS =  libmlx.dylib
#en libs añado los .a (en este caso es dinamica y por eso es .dylib)


#en libpath, con -L y la carpeta donde esta la libreria
LIBPATH = -L mlx
#en LDLIBS, con -l va el nombre (sin el lib y sin el .a ) las librerias
LDLIBS = -lmlx 
FRAMES = -framework OpenGL -framework AppKit  
#este le dice a gcc donde buscar .h definidos dentro de los .c
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
	cp mlx/libmlx.dylib .

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
