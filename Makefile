# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 18:14:56 by jroulet           #+#    #+#              #
#    Updated: 2024/06/26 18:48:53 by jroulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
CC = cc
DEBUGGER = -g
SRCS =	./so_long.c
OBJS = $(SRCS:.c=.o)

LIBDIR = ./libft
LIBNAME = libft.a

NAME = so_long


##MINILIBX
OS=$(shell uname)
ifeq ($(OS), Linux)
defrule:
	INCLUDE = /mlx/
else
defrule :
	echo i am mac
endif

MLXDIR = ./mlx
MLXLIB = $(MLX_DIR)/libmlx_$(UNAME).a
####MINILIBX END

%.o: %.c
	$(CC) $(FLAGS) -g -c $< -o $@

all: $(NAME)

$(NAME): makelibft $(OBJS)
	$(CC) $(OBJS) $(LIBDIR)/$(LIBNAME) -o $(NAME)

makelibft:
	make -C $(LIBDIR)
	cp $(LIBDIR)/$(LIBNAME) .

debug: $(NAME)
	$(CC) $(DEBUGGER) $(OBJS) $(LIBDIR)/$(LIBNAME) -o $(NAME)

git: fclean
	git add .
	git commit -m "$t" -m "$b"
	git push

clean:
	make -C $(LIBDIR) clean
	rm -f $(OBJS)
	rm -f ./sort/*.o

fclean: clean
	make -C $(LIBDIR) fclean
	rm -f $(LIBNAME)
	rm -f $(NAME)
	rm -f ./sort/*.o

re: fclean all

.PHONY: debugger compile clean re fclean bonus git all
