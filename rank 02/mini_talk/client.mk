# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    client.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abastida <abastida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 16:40:54 by abastida          #+#    #+#              #
#    Updated: 2022/11/15 13:56:03 by abastida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := client
SRC := client.c
NAME_BONUS := client_bonus
SRC_BONUS := client_bonus.c
OBJ := $(SRC:.c=.o)
OBJ_BONUS := $(SRC_BONUS:.c=.o)
#Esta es para que me cree los .o de los .c directamente
DEP := $(SRC:.c=.d)
DEP_BONUS := $(SRC_BONUS:.c=.d)

CC := gcc
CFLAGS := -Wall -Werror -Wextra -g -MMD -I libftprintf
RM := rm -rf
LIBS := libftprintf/libftprintf.a
LIBPATH := -L libftprintf -lftprintf
INCLUDE := -I libftprintf

all: $(NAME)

-include $(DEP)
$(NAME): $(LIBS) $(OBJ)
	$(CC) $(CFLAGS) $(LIBPATH) $(OBJ) -o $(NAME)

-include $(DEP_BONUS)
$(NAME_BONUS): $(LIBS) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(LIBPATH) $(OBJ_BONUS) -o $(NAME_BONUS)

$(LIBS):
	$(MAKE) -C libftprintf

clean:
	$(RM) $(OBJ)
	$(RM) $(DEP)
	$(RM) $(OBJ_BONUS)
	$(RM) $(DEP_BONUS)
	$(MAKE) clean -C libftprintf

fclean: 
	$(MAKE) clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	$(MAKE) fclean -C libftprintf

re: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus

