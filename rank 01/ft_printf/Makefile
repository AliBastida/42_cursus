NAME := libftprintf.a
INCLUDE := inc/
HEADER := $(INCLUDE)/ft_printf.h
SRC_DIR := src/
OBJ_DIR := obj/
CC := gcc
CFLAGS := -g -Wall -Wextra -Werror
RM := rm -f
AR := ar -rcs
SRCS_FILES = ft_hexa.c ft_printf.c ft_src.c


DEF_COLOR := \033[0;39m
GRAY := \033[0;90m
RED := \033[0;91m
GREEN := \033[0;92m
YELLOW := \033[0;93m
BLUE := \033[0;94m
MAGENTA := \033[0;95m
CYAN := \033[0;96m
WHITE := \033[0;97m

SRCS 			=	$(addprefix $(SRC_DIR),$(SRCS_FILES))
OBJS			=	$(addprefix $(OBJ_DIR),$(SRCS_FILES:.c=.o))
OBJF = cache_exists

all: $(OBJF) $(NAME)

$(OBJF):
	@mkdir -p $(OBJ_DIR)

$(NAME):	$(OBJS) $(HEADER)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(CYAN) Compiled! $(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@echo "$(GREEN) Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(YELLOW) Objects files cleaned.$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(MAGENTA) Executable files cleaned. $(DEF_COLOR)"

re: fclean all
	@echo "$(RED) Cleaned and rebuilt everything.$(DEF_COLOR)"

.PHONY: all clean fclean re
