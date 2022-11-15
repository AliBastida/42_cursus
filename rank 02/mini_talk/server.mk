# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    server.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abastida <abastida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 13:51:08 by abastida          #+#    #+#              #
#    Updated: 2022/11/15 13:55:59 by abastida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := server
SRC := server.c
NAME_BONUS := server_bonus
SRC_BONUS := server_bonus.c
OBJ := $(addsuffix .o, $(addprefix ., $(basename $(SRC))))
DEP := $(addsuffix .d, $(addprefix ., $(basename $(SRC))))
OBJ_BONUS := $(addsuffix .o, $(addprefix ., $(basename $(SRC_BONUS))))
DEP_BONUS := $(addsuffix .d, $(addprefix ., $(basename $(SRC_BONUS))))

CC := gcc
CFLAGS := -Wall -Werror -Wextra -g -MMD
RM := rm -rf
LIBS := libftprintf/libftprintf.a
LIBPATH := -L libftprintf -lftprintf
INCLUDE := -I libftprintf

.%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
.%.o: src_bonus%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

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
	$(RM) $(OBJ_BONUS)
	$(RM) $(DEP)
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

