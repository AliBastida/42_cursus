# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    server.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abastida <abastida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 13:51:08 by abastida          #+#    #+#              #
#    Updated: 2022/11/11 12:22:21 by abastida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := server
SRC := server.c
OBJ := $(addsuffix .o, $(addprefix ., $(basename $(SRC))))
DEP := $(addsuffix .d, $(addprefix ., $(basename $(SRC))))

CC := gcc
CFLAGS := -Wall -Werror -Wextra -g -MMD
RM := rm -rf
LIBS := libftprintf/libftprintf.a
LIBPATH := -L libftprintf -lftprintf
INCLUDE := -I libftprintf

.%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

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

