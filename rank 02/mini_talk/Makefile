# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abastida <abastida@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 13:51:08 by abastida          #+#    #+#              #
#    Updated: 2022/11/17 09:43:03 by abastida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	$(MAKE) -f client.mk
	$(MAKE) -f server.mk

bonus:
	$(MAKE) -f client.mk client_bonus
	$(MAKE) -f server.mk server_bonus

clean:
	$(MAKE) -f client.mk clean
	$(MAKE) -f server.mk clean

fclean:
	$(MAKE) -f client.mk fclean
	$(MAKE) -f server.mk fclean

re:
	$(MAKE) -f client.mk re
	$(MAKE) -f server.mk re

.PHONY: all clean fclean re bonus
