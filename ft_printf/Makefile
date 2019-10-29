# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sstark <sstark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/06 00:16:21 by mschimme          #+#    #+#              #
#    Updated: 2019/10/29 17:35:27 by sstark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
CC	= gcc
FLAGS = -Wall -Wextra -Werror

VPATH	:=	./ft_printf:
SOURCE	+=	csp.c \
			dioux.c \
			e.c \
			f.c \
			flags.c \
			ft_dtoa.c \
			ft_insert.c \
			g.c \
			help.c \
			lst_killer.c \
			print.c \
			print_for_printf.c \
			searching.c \
			size_converter.c \
			size_revision.c
VPATH	+=	./libft
SOURCE	+=	ft_allocated_size.c \
			ft_atoi.c \
			ft_bzero.c \
			ft_del.c \
			ft_free.c \
			ft_get_next_line.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlen.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_malloc.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_mult.c \
			ft_mult_atod.c \
			ft_power.c \
			ft_power_for_two.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_qsort_i.c \
			ft_realloc.c \
			ft_sqrt.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strndup.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_utoa.c
			

OBJ_DIR		:=	./obj
OBJECTS		:= $(patsubst %,$(OBJ_DIR)/%,$(SOURCE:.c=.o))

INC_DIR	:=	./includes ./libft/includes
IFLAGS	+= $(foreach d, $(INC_DIR), -I$d)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

$(OBJ_DIR)/%.o:%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS)  -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all