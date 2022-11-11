# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    client.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abastida <abastida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 16:40:54 by abastida          #+#    #+#              #
#    Updated: 2022/11/11 15:11:15 by abastida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := client
SRC := client.c
#OBJ := $(addsuffix .o, $(addprefix ., $(basename $(SRC))))
OBJ := $(SRC:.c=.o)
Esta es para que me cree los .o de los .c directamente
DEP := $(addsuffix .d, $(addprefix ., $(basename $(SRC))))

CC := gcc
CFLAGS := -Wall -Werror -Wextra -g -MMD -I libftprintf
RM := rm -rf
LIBS := libftprintf/libftprintf.a
LIBPATH := -L libftprintf -lftprintf

#.%.o: %.c
#	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

-include $(DEP)
$(NAME): $(LIBS) $(OBJ)
	$(CC) $(CFLAGS) $(LIBPATH) $(OBJ) -o $(NAME)

$(LIBS):
	$(MAKE) -C libftprintf

clean:
	$(RM) $(OBJ)
	$(RM) $(DEP)
	$(MAKE) clean -C libftprintf

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libftprintf

re: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re 

