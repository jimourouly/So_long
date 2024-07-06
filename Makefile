# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroulet <jroulet@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 18:14:56 by jroulet           #+#    #+#              #
#    Updated: 2024/07/01 12:37:06 by jroulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
CC = cc
DEBUGGER = -g
SRCS = ./so_long.c\
		./draw_shape.c \
		./GNL/get_next_line.c \
		./GNL/get_next_line_utils.c\
		./mapchecker.c
OBJS = $(SRCS:.c=.o)

LIBDIR = ./libft
LIBNAME = libft.a

NAME = so_long

## MINILIBX
OS = $(shell uname)
ifeq ($(OS), Linux)
MLXFLAGS = -Lmlx_linux -lmlx -L/usr/X11/lib -lXext -lX11
INCLUDE = -I/usr/include -Imlx_linux
else
MLXFLAGS = -L/path/to/mac/lib -lmlx -framework OpenGL -framework AppKit
INCLUDE = -I/path/to/mac/include
endif
#### MINILIBX END

all: $(NAME)

$(NAME): makelibft $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBDIR)/$(LIBNAME) $(MLXFLAGS) -o $(NAME) -lm

makelibft:
	make -C $(LIBDIR)
	cp $(LIBDIR)/$(LIBNAME) .

debug: $(NAME)
	$(CC) $(DEBUGGER) $(FLAGS) $(OBJS) $(LIBDIR)/$(LIBNAME) $(MLXFLAGS) -o $(NAME)

clean:
	make -C $(LIBDIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBDIR) fclean
	rm -f $(LIBNAME)
	rm -f $(NAME)

re: fclean all

git:
	git add .
	git commit -m "$t" -m "$b"
	git push

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

.PHONY: all clean fclean re debug git
