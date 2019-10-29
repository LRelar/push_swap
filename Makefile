# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sstark <sstark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/06 00:16:21 by mschimme          #+#    #+#              #
#    Updated: 2019/10/29 19:42:53 by sstark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER	=	./make_check
PUSH	=	./make_push


.PHONY: all clean fclean re

all: build

build:
	@$(MAKE) -f $(CHECKER)
	@$(MAKE) -f $(PUSH)

clean:
	@$(MAKE) -f $(CHECKER) clean
	@$(MAKE) -f $(PUSH) clean

fclean: 
	@$(MAKE) -f $(CHECKER) fclean
	@$(MAKE) -f $(PUSH) fclean

re: fclean all
