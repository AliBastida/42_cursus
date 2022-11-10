# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    server.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abastida <abastida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 13:51:08 by abastida          #+#    #+#              #
#    Updated: 2022/11/10 17:24:12 by abastida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := server
SRC := server.c
OBJ := $(addsufix .o, $(addprefix ., $(basename $(SRC))))
DEP := $(addsufix .d, $(addprefix ., $(basename $(SRC))))

CC := gcc
CFLAGS := -Wall -Werror -Wextra -g -MMD
RM := rm -rf
LIBS := libftprintf/libftprintf.a
LIBPATH := -lftprintf
INCLUDE := -I libftprintf

.%.o = %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all := $(NAME)

-include $(DEP)
$(NAME): $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(LIBPATH) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(DEP)
	$(MAKE) clean -C libftprintf

fclean:
	$(MAKE) clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libftprintf

re: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re 

