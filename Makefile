# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 18:14:56 by jroulet           #+#    #+#              #
#    Updated: 2024/07/01 12:37:06 by jroulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
CC = cc
DEBUGGER = -g
SRCS = ./so_long.c
OBJS = $(SRCS:.c=.o)

LIBDIR = ./libft
LIBNAME = libft.a

NAME = so_long

##MINILIBX
OS=$(shell uname)
ifeq ($(OS), Linux)
INCLUDE = -I./mlx
else
INCLUDE = -I./path/to/mac/include # Adjust this path as necessary
endif

MLXDIR = ./mlx
MLXLIB = $(MLXDIR)/libmlx_$(OS).a # Corrected typo here
####MINILIBX END

%.o: %.c
	$(CC) $(FLAGS) $(DEBUGGER) $(INCLUDE) -c $< -o $@ # Ensure INCLUDE is used here

all: $(NAME)

$(NAME): makelibft $(OBJS)
	$(CC) $(OBJS) $(LIBDIR)/$(LIBNAME) -o $(NAME)

makelibft:
	make -C $(LIBDIR)
	cp $(LIBDIR)/$(LIBNAME) .

debug: $(NAME)
	$(CC) $(DEBUGGER) $(OBJS) $(LIBDIR)/$(LIBNAME) -o $(NAME)

# Other targets remain unchanged

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
