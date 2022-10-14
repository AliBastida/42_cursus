# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abastida <abastida@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 14:38:08 by abastida          #+#    #+#              #
#    Updated: 2022/10/14 10:50:18 by abastida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_isalpha.c ft_isdigit.c ft_strlcat.c ft_isalnum.c ft_isascii.c \
	   ft_isprint.c ft_strlen.c ft_memset.c ft_toupper.c ft_strlcpy.c \
	   ft_memcpy.c ft_bzero.c ft_memmove.c ft_strchr.c ft_strrchr.c \
	   ft_strncmp.c ft_memchr.c ft_memcmp.c ft_atoi.c ft_strnstr.c \
	   ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	   ft_itoa.c ft_putchar_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
	   ft_putstr_fd.c ft_striteri.c ft_strmapi.c ft_split.c ft_tolower.c


SRCSBONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = ${SRCS:%.c=%.o}

OBJSBONUS = ${SRCSBONUS:.c=.o}

HEADER = libft.h
CC = gcc
RM = rm -f 
CFLAGS = -Wall -Wextra -Werror

%.o : %.c #${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

all: 		${NAME}

${NAME}:    ${OBJS}	${HEADER}
			ar rcs ${NAME} ${OBJS}
			ranlib ${NAME}

bonus:		${OBJS} ${OBJSBONUS} ${HEADER}
			ar rcs ${NAME} ${OBJS} ${OBJSBONUS}
			ranlib ${NAME}
			@touch $@

clean: 		
			${RM} ${OBJS} ${OBJSBONUS}

fclean: 	clean
			${RM} ${NAME}
			${RM} bonus

re:			fclean all

.PHONY: all clean fclean re
