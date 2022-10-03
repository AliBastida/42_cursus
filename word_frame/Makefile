NAME = word_frame
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -fr
SRC = word_frame.c word_frame_utils.c
OBJ = $(SRC)
HEADER = word_frame.h

%o : %c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean: 
	${RM} ${OBJS}

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
	
