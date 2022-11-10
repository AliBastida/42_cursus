# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abastida <abastida@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 13:51:08 by abastida          #+#    #+#              #
#    Updated: 2022/11/10 14:28:32 by abastida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
SRC_CLIENT = client.c
SRC_SERVER = server.c
OBJ_CLIENT = $(addsufix .o, $(addprefix ., $(basename $(SRC_CLIENT))))
OBJ_SERVER = $(addsufix .o, $(addprefix ., $(basename $(SRC_SERVER))))
DEPS_CLIENT = $(addsufix .d, $(addprefix ., $(basename $(SRC_CLIENT))))
DEPS_SERVER = $(addsufix .d, $(addprefix ., $(basename $(SRC_SERVER))))


CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf
LIBS = libftprintf/libftprintf.a
LIBPATH = -L libftprintf
LDLIBS = -llibftprintf
INCLUDE = -I libftprintf

.%.o = %.c Makefile
	$(CC) $(CFLAGS)  $(INCLUDES) -c  $< -o $@ 

all: make


